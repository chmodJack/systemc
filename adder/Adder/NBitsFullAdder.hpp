/*************************************************************************
    > File Name       : Adder/NBitsFullAdder.hpp
    > Author          : chmodJack
    > Mail            : 158754845@qq.com 
    > GitHub          : https://github.com/chmodJack 
    > Created Time    : 2018年02月08日 星期四 11时12分09秒
    > Description     : 
*************************************************************************/
#ifndef __NBITSFULLADDER_HPP__
#define __NBITSFULLADDER_HPP__

#include"systemc.h"
template<unsigned int N>//N <- [1,64]
class NBitsFullAdder:public sc_module
{
public:
	sc_in<sc_uint<N>> A;
	sc_in<sc_uint<N>> B;
	sc_in<bool>       CI;

	sc_out<sc_uint<N>> S;
	sc_out<bool>       CO;

	typedef NBitsFullAdder SC_CURRENT_USER_MODULE;
	NBitsFullAdder(sc_module_name name)
	{
		cout<<"Created me.NBitsFullAdder"<<endl;

		if(N==0)
			throw "Template parameter N is invalid";
		if(N>63)
			throw "Template parameter N is out of range.";

		SC_METHOD(keepBalance);
		sensitive<<A<<B<<CI;
		dont_initialize();
	}

	void keepBalance(void)
	{
		sc_uint<N+1> temp=A.read()+B.read()+CI.read();
		S.write(temp);
		CO.write(temp[N]);
	}
	void print(void)
	{
		cout<<sc_time_stamp()<<" NBitsFullAdder: A->"<<A.read()<<" B->"<<B.read()<<" CI->"<<CI.read()<<" S->"<<S.read()<<" CO->"<<CO.read()<<endl;
	}
};

#endif//__NBITSFULLADDER_HPP__
