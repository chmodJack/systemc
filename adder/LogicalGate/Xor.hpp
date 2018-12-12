/*************************************************************************
    > File Name       : Xor.hpp
    > Author          : chmodJack
    > Mail            : 158754845@qq.com 
    > GitHub          : https://github.com/chmodJack 
    > Created Time    : 2018年02月07日 星期三 10时44分53秒
    > Description     : 
*************************************************************************/
#ifndef __XOR_HPP__
#define __XOR_HPP__

#include"LogicalGate.hpp"
class Xor:public LogicalGate
{
public:
	void keepBalance(void)
	{
#if NOT_RECOMMENDED
		C=A^B;
#else
		C.write(A.read() xor B.read());
#endif
	}
	void print(void)
	{
		cout<<sc_time_stamp()<<" Xor: A->"<<A<<" B->"<<B<<" C->"<<C<<endl;
	}
	Xor(sc_module_name name="Xor"):LogicalGate(name){}
};

#endif//__XOR_HPP__
