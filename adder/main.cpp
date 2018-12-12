/*************************************************************************
    > File Name       : main.cpp
    > Author          : chmodJack
    > Mail            : 158754845@qq.com
    > GitHub          : https://github.com/chmodJack
    > Created Time    : 2018年02月07日 星期三 11时40分23秒
    > Description     : 
*************************************************************************/

//#include"FullAdder.hpp"
#include"NBitsFullAdder.hpp"

#if 1

#define BITS 4
int sc_main(int argc,char* argv[])
{
	try
	{
		auto& adder=*new NBitsFullAdder<BITS>("NBitsFullAdder");

		sc_signal<sc_uint<BITS>> a,b,s;
		sc_signal<bool>          ci,co;

		adder.A(a);
		adder.B(b);
		adder.S(s);
		adder.CI(ci);
		adder.CO(co);

		auto print=[&](){adder.print();};

		sc_start(1,SC_NS);
		print();

		a=255;b=255;ci=1;
		sc_start(1,SC_NS);
		print();
	}
	catch(const char* msg)
	{
		cout<<msg<<endl;
	}

	return 0;
}

#else

#include"Xnor.hpp"

int sc_main(int argc,char* argv[])
{
	Xnor xx("Xnor");
	sc_signal<bool> a,b,c;
	clock

	xx.A(a);
	xx.B(b);
	xx.C(c);

	auto print=[&](){xx.print();};

	sc_start(1,SC_NS);
	print();

	a=1;b=0;
	sc_start(1,SC_NS);
	print();

	a=0;b=1;
	sc_start(1,SC_NS);
	print();

	a=1;b=1;
	sc_start(1,SC_NS);
	print();

	a=0;b=0;
	sc_start(1,SC_NS);
	print();

	return 0;
}

#endif
