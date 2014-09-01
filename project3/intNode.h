/* *
* @copyright 2013-2014, Zhejiang University
* @file   project3
* @brief  实现整形节点的操作
*
* 版本历史：
* @Verson  0.1 @date 2014-05-21   jxzhuge12：新建文件
*
*/

#ifndef INTNODE_H    //防止intNode.h被重复引用
#define INTNODE_H

#include<iostream>
using namespace std;

#include "Node.h"

//整形节点类定义
class intNode :public Node
{
private:
	int val;
public:
	intNode(int a) :val(a) {}

	/**
	* @brief       功能：输出整数
	* @param [in]
	* @return      void
	* @exception
	*/
	void print() const
	{
		cout << val << "    ";
	}

	/**
	* @brief       功能：设置节点整数值
	* @param [in]  输入参数 i：int
	* @return      void
	* @exception
	*/
	void SetVal(int i)
	{
		val = i;
	}
};

#endif