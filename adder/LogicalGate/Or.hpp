/*************************************************************************
    > File Name       : Or.hpp
    > Author          : chmodJack
    > Mail            : 158754845@qq.com 
    > GitHub          : https://github.com/chmodJack 
    > Created Time    : 2018年02月07日 星期三 10时23分13秒
    > Description     : 
*************************************************************************/
#ifndef __OR_HPP__
#define __OR_HPP__

#include"LogicalGate.hpp"
class Or:public LogicalGate
{
public:
	void keepBalance(void)
	{
#if NOT_RECOMMENDED
		C=A|B;
#else
		C.write(A.read() or B.read());
#endif
	}
	void print(void)
	{
		cout<<sc_time_stamp()<<" Or: A->"<<A<<" B->"<<B<<" C->"<<C<<endl;
	}

	Or(sc_module_name name="Or"):LogicalGate(name){}
};

#endif//__OR_HPP__
