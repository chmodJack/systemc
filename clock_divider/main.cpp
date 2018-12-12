#include"main.h"

class base:public sc_module
{
public:
	common::port_t<common::clock_t> clk;
	sc_time period;
public:
	SC_HAS_PROCESS(base);
	base(sc_module_name name):sc_module(name)
	{
		SC_THREAD(clk_thread);
		sensitive<<clk;

		SC_THREAD(main_thread);
	}
	void clk_thread(void)
	{
		while(1)
		{
			wait();
			period = clk.read().period;
			cout<<name()<<": my new period is: "<<period<<", "<<sc_time_stamp()<<endl;
		}
	}
	void main_thread(void)
	{
		while(1)
		{
			wait(sc_time(10,SC_SEC));
			cout<<name()<<": this is main thread, "<<sc_time_stamp()<<endl;
			usleep(1000000);
		}
	}
};

int sc_main(int argc,char* argv[])
{
	common::clock_master m1("m1",1,SC_MS);
	common::clock_master m2("m2",2,SC_MS);

	base b1("b1");
	base b2("b2");
	base b3("b3");

	common::clock_divider diver1("diver1");

	m1.clk(diver1.master[0]);
	m2.clk(diver1.master[1]);

	diver1.slave[0](b1.clk);
	diver1.slave[1](b2.clk);
	diver1.slave[2](b3.clk);

	sc_start();
	return 0;
}
