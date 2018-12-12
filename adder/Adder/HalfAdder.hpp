/*************************************************************************
    > File Name       : HalfAdder.hpp
    > Author          : chmodJack
    > Mail            : 158754845@qq.com 
    > GitHub          : https://github.com/chmodJack 
    > Created Time    : 2018年02月07日 星期三 14时30分36秒
    > Description     : 
*************************************************************************/
#ifndef __HALFADDER_HPP__
#define __HALFADDER_HPP__

#include"Xor.hpp"
#include"And.hpp"
//class HalfAdder => Error: (E100) port specified outside of module: port 'port_0' (sc_port_base)
class HalfAdder:public sc_module
{
public:
	sc_in<bool> A;
	sc_in<bool> B;

	sc_out<bool> S;
	sc_out<bool> C;

	//typedef HalfAdder SC_CURRENT_USER_MODULE;
	HalfAdder(sc_module_name name="HalfAdder")
	{
		cout<<"Created me.HalfAdder."<<endl;

		xx=new Xor("Xor");
		aa=new And("And");

		xx->A(A);
		xx->B(B);
		xx->C(S);

		aa->A(B);
		aa->B(A);
		aa->C(C);
	}
	~HalfAdder(void)
	{
		cout<<"Delete me.HalfAdder."<<endl;

		delete xx;
		delete aa;
	}

	void print(void)
	{
		cout<<sc_time_stamp()<<" HalfAdder: A->"<<A<<" B->"<<B<<" S->"<<S<<" C->"<<C<<endl;
	}
private:
	LogicalGate* xx;
	LogicalGate* aa;
};

#endif//__HALFADDER_HPP__
