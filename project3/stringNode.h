/* *
* @copyright 2013-2014, Zhejiang University
* @file   project3
* @brief  实现字符串节点的操作
*
* 版本历史：
* @Verson  0.1 @date 2014-05-21   jxzhuge12：新建文件
*
*/

#ifndef STRINGNODE_H    //防止stringNode.h被重复引用
#define STRINGNODE_H

#include<iostream>
#include<string>
using namespace std;

#include "Node.h"

//字符串节点类定义
class stringNode :public Node
{
private:
	string val;
public:
	stringNode(string a) :val(a) {}

	/**
	* @brief       功能：输出字符串
	* @param [in]
	* @return      void
	* @exception
	*/
	void print() const
	{
		cout << val << "    ";
	}

	/**
	* @brief       功能：设置节点字符串值
	* @param [in]  输入参数 i：string
	* @return      void
	* @exception
	*/
	void SetVal(string i)
	{
		val = i;
	}
};

#endif