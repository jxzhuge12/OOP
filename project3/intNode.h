/* *
* @copyright 2013-2014, Zhejiang University
* @file   project3
* @brief  ʵ�����νڵ�Ĳ���
*
* �汾��ʷ��
* @Verson  0.1 @date 2014-05-21   jxzhuge12���½��ļ�
*
*/

#ifndef INTNODE_H    //��ֹintNode.h���ظ�����
#define INTNODE_H

#include<iostream>
using namespace std;

#include "Node.h"

//���νڵ��ඨ��
class intNode :public Node
{
private:
	int val;
public:
	intNode(int a) :val(a) {}

	/**
	* @brief       ���ܣ��������
	* @param [in]
	* @return      void
	* @exception
	*/
	void print() const
	{
		cout << val << "    ";
	}

	/**
	* @brief       ���ܣ����ýڵ�����ֵ
	* @param [in]  ������� i��int
	* @return      void
	* @exception
	*/
	void SetVal(int i)
	{
		val = i;
	}
};

#endif