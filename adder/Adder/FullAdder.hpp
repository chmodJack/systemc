/*************************************************************************
    > File Name       : FullAdder.hpp
    > Author          : chmodJack
    > Mail            : 158754845@qq.com 
    > GitHub          : https://github.com/chmodJack 
    > Created Time    : 2018年02月08日 星期四 10时11分43秒
    > Description     : 
*************************************************************************/
#ifndef __FULLADDER_HPP__
#define __FULLADDER_HPP__

#include"HalfAdder.hpp"
#include"Or.hpp"
class FullAdder:public sc_module
{
public:
	sc_in<bool> A;
	sc_in<bool> B;
	sc_in<bool> CI;

	sc_out<bool> S;
	sc_out<bool> CO;

	//typedef FullAdder SC_CURRENT_USER_MODULE;
	FullAdder(sc_module_name name)
	{
		cout<<"Created me.FullAdder."<<endl;

		halfAdderArr[0]=new HalfAdder("HalfAdder1");
		halfAdderArr[1]=new HalfAdder("HalfAdder2");
		oo             =new Or("Or");

		halfAdderArr[0]->A(A);
		halfAdderArr[0]->B(B);
		halfAdderArr[0]->S(a);
		halfAdderArr[0]->C(b);

		halfAdderArr[1]->A(a);
		halfAdderArr[1]->B(CI);
		halfAdderArr[1]->S(S);
		halfAdderArr[1]->C(c);

		oo->A(c);
		oo->B(b);
		oo->C(CO);
	}
	~FullAdder(void)
	{
		cout<<"Delete me.FullAdder."<<endl;

		delete halfAdderArr[0];
		delete halfAdderArr[1];
		delete oo;
	}

	void print(void)
	{
		cout<<sc_time_stamp()<<" FullAdder: A->"<<A<<" B->"<<B<<" CI->"<<CI<<" S->"<<S<<" CO->"<<CO<<endl;
	}
private:
	HalfAdder*      halfAdderArr[2];
	LogicalGate*    oo;
	sc_signal<bool> a,b,c;
};

#endif//__FULLADDER_HPP__
