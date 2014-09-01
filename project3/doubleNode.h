/* *
* @copyright 2013-2014, Zhejiang University
* @file   project3
* @brief  ʵ�ָ����ͽڵ�Ĳ���
*
* �汾��ʷ��
* @Verson  0.1 @date 2014-05-21   jxzhuge12���½��ļ�
*
*/

#ifndef DOUBLENODE_H    //��ֹdoubleNode.h���ظ�����
#define DOUBLENODE_H

#include<iostream>
using namespace std;

#include "Node.h"

//�����ͽڵ��ඨ��
class doubleNode :public Node
{
private:
	double val;
public:
	doubleNode(double a) :val(a) {}

	/**
	* @brief       ���ܣ����������
	* @param [in]
	* @return      void
	* @exception
	*/
	void print() const
	{
		cout << val << "    ";
	}

	/**
	* @brief       ���ܣ����ýڵ㸡��ֵ
	* @param [in]  ������� i��double
	* @return      void
	* @exception
	*/
	void SetVal(double i)
	{
		val = i;
	}
};

#endif