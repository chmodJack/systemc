/*************************************************************************
    > File Name       : Xnor.hpp
    > Author          : chmodJack
    > Mail            : 158754845@qq.com 
    > GitHub          : https://github.com/chmodJack 
    > Created Time    : 2018年02月07日 星期三 11时04分43秒
    > Description     : 
*************************************************************************/
#ifndef __XNOR_HPP__
#define __XNOR_HPP__

#if 0

#include"LogicalGate.hpp"
class Xnor:public LogicalGate
{
public:
	void keepBalance(void)
	{
#if NOT_RECOMMENDED
		C=!(A^B);
#else
		C.write(not(A.read() xor B.read()));
#endif
	}

	void print(void)
	{
		cout<<sc_time_stamp()<<" Xnor: "<<"A->"<<A<<" "<<"B->"<<B<<" "<<"C->"<<C<<endl;
	}

	Xnor(sc_module_name name):LogicalGate(name){}
};

#else

#include"Xor.hpp"
#include"Not.hpp"
class Xnor:public sc_module
{
public:
	sc_in<bool> A;
	sc_in<bool> B;

	sc_out<bool> C;

	Xnor(sc_module_name name)
	{
		cout<<"Created me.Xnor."<<endl;

		xx=new Xor("Xor");
		nn=new Not("Not");

		xx->A(A);
		xx->B(B);
		xx->C(a);

		nn->A(a);
		nn->B(C);
	}

	void print(void)
	{
		cout<<sc_time_stamp()<<" Xnor: A->"<<A<<" B->"<<B<<" C->"<<C<<endl;
	}
private:
	LogicalGate*    xx;
	Not*            nn;
	sc_signal<bool> a;
};

#endif

#endif//__XNOR_HPP__
