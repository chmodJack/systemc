/*************************************************************************
    > File Name       : Not.hpp
    > Author          : chmodJack
    > Mail            : 158754845@qq.com 
    > GitHub          : https://github.com/chmodJack 
    > Created Time    : 2018年02月09日 星期五 08时49分52秒
    > Description     : 
*************************************************************************/
#ifndef __NOT_HPP__
#define __NOT_HPP__

#include"systemc.h"
class Not:public sc_module
{
public:
	sc_in<bool> A;

	sc_out<bool> B;

	void keepBalance(void)
	{
#if NOT_RECOMMENDED
		B=!A;
#else
		B.write(not A.read());
#endif
	}
	void print(void)
	{
		cout<<sc_time_stamp()<<"A->"<<A<<" B->"<<B<<endl;
	}

	typedef Not SC_CURRENT_USER_MODULE;
	Not(sc_module_name name)
	{
		cout<<"Create me.Not."<<endl;
		SC_METHOD(keepBalance);
		sensitive<<A;
		dont_initialize();
	}
};

#endif//__NOT_HPP__
