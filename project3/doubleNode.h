/* *
* @copyright 2013-2014, Zhejiang University
* @file   project3
* @brief  实现浮点型节点的操作
*
* 版本历史：
* @Verson  0.1 @date 2014-05-21   jxzhuge12：新建文件
*
*/

#ifndef DOUBLENODE_H    //防止doubleNode.h被重复引用
#define DOUBLENODE_H

#include<iostream>
using namespace std;

#include "Node.h"

//浮点型节点类定义
class doubleNode :public Node
{
private:
	double val;
public:
	doubleNode(double a) :val(a) {}

	/**
	* @brief       功能：输出浮点数
	* @param [in]
	* @return      void
	* @exception
	*/
	void print() const
	{
		cout << val << "    ";
	}

	/**
	* @brief       功能：设置节点浮点值
	* @param [in]  输入参数 i：double
	* @return      void
	* @exception
	*/
	void SetVal(double i)
	{
		val = i;
	}
};

#endif