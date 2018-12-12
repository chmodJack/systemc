/*************************************************************************
    > File Name       : And.hpp
    > Author          : chmodJack
    > Mail            : 158754845@qq.com 
    > GitHub          : https://github.com/chmodJack 
    > Created Time    : 2018年02月07日 星期三 10时21分53秒
    > Description     : 
*************************************************************************/
#ifndef __AND_HPP__
#define __AND_HPP__

#include"LogicalGate.hpp"
class And:public LogicalGate
{
public:
	void keepBalance(void)
	{
#if NOT_RECOMMENDED
		C=A&B;
#else
		C.write(A.read() and B.read());
#endif
	}
	void print(void)
	{
		cout<<sc_time_stamp()<<" And: A->"<<A<<" B->"<<B<<" C->"<<C<<endl;
	}

	And(sc_module_name name="And"):LogicalGate(name){}
};

#endif//__AND_HPP__
