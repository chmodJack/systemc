/*************************************************************************
    > File Name       : LogicalGate.hpp
    > Author          : chmodJack
    > Mail            : 158754845@qq.com 
    > GitHub          : https://github.com/chmodJack 
    > Created Time    : 2018年02月07日 星期三 10时15分48秒
    > Description     : 
*************************************************************************/
#ifndef __LOGICALGATE_HPP__
#define __LOGICALGATE_HPP__

#include"systemc.h"
class LogicalGate:public sc_module
{
public:
	sc_in<bool> A;
	sc_in<bool> B;

	sc_out<bool> C;

	virtual void keepBalance(void)=0;
	virtual void print(void)=0;

	typedef LogicalGate SC_CURRENT_USER_MODULE;
	LogicalGate(sc_module_name name)
	{
		cout<<"Create me."<<name<<"."<<endl;

		SC_METHOD(keepBalance);
		sensitive<<A<<B;
		dont_initialize();
	}
};

#endif//__LOGICALGATE_HPP__
