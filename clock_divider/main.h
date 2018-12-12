#ifndef __MAIN_H__
#define __MAIN_H__

#include"systemc.h"
#include"unistd.h"

namespace common
{
	template<class T>
	class port_t
	{
	public:
		sc_out<T> out;
		sc_buffer<T> buffer;
	public:
		void operator()(port_t& port)
		{
			//互相绑定操作
			this->out(port.buffer);
			port.out(this->buffer);

			//互相保存对方的this指针
			bind_me = &port;
			port.bind_me = this;
		}
		inline const T& read(void)
		{
			return buffer.read();
		}
		inline void write(const T& dat)
		{
			out.write(dat);
		}
		operator const sc_interface&()const
		{
			//被绑定时需要的类型转换操作符
			return buffer;
		}
		inline void operator = (const T& dat)
		{
			//赋值操作符，同write
			out.write(dat);
		}
		inline operator const T&()const
		{
			//赋值操作符右边的，同read
			return buffer.read();
		}
	public:
		//跟我互相绑定的那个端口
		port_t* bind_me = nullptr;
	};

	class clock_t
	{
	public:
		sc_time period;
	public:
		bool operator==(const clock_t& clk)const
		{
			return ((this->period) == (clk.period));
		}
		friend ostream& operator << (ostream &os, const clock_t& clk)
		{
			os << clk.period;
			return os;
		}
		operator char*() const
		{
			return (char*)"common::clock_t";
		}
	};

	class clock_master :public sc_module
	{
	public:
		common::port_t<common::clock_t> clk;
	public:
		common::clock_t m_transmit_value;
	public:
		SC_HAS_PROCESS(clock_master);
		clock_master(sc_module_name name, const sc_time& period) :sc_module(name)
		{
			SC_THREAD(once_thread);
			m_transmit_value.period = period;
		}
		clock_master(sc_module_name name, double value, sc_time_unit unit) :sc_module(name)
		{
			SC_THREAD(once_thread);
			m_transmit_value.period = sc_time(value, unit);
		}
		void once_thread(void)
		{
			while (1)
			{
				clk.write(m_transmit_value);
				cout<<name()<<": this is master clock."<<sc_time_stamp()<<endl;
				wait();//yield forever, this thread is just let clk port have data to read, from the other modules
			}
		}
	};

	class clock_divider:public sc_module
	{
	public:
		common::port_t<common::clock_t> master[2];
		common::port_t<common::clock_t> slave[3];
	public:
		uint32_t reg_mux=1;

		uint32_t reg_mul1=1;
		uint32_t reg_div1=1;

		uint32_t reg_mul2=2;
		uint32_t reg_div2=1;

		uint32_t reg_mul3=3;
		uint32_t reg_div3=1;
	public:
		SC_HAS_PROCESS(clock_divider);
		clock_divider(sc_module_name name):sc_module(name)
		{
			SC_THREAD(run);
			for(uint32_t i=0;i<2;i++)
				sensitive<<master[i];
		}
		void run(void)
		{
			while(1)
			{
				wait();
				update_clock();
				cout<<name()<<": this is clock divider, new input comming."<<sc_time_stamp()<<endl;
			}
		}
		void update_clock(void)
		{
			sc_time temp;

			switch(reg_mux)
			{
				case 0:
					{
						temp = master[0].read().period;
					}
					break;
				case 1:
					{
						temp = master[1].read().period;
					}
					break;
			}

			common::clock_t trans;

			trans.period = (temp * reg_mul1) / reg_div1;
			slave[0].write(trans);

			trans.period = (temp * reg_mul2) / reg_div2;
			slave[1].write(trans);

			trans.period = (temp * reg_mul3) / reg_div3;
			slave[2].write(trans);
		}
	};
}

#endif//__MAIN_H__
