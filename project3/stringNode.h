/* *
* @copyright 2013-2014, Zhejiang University
* @file   project3
* @brief  ʵ���ַ����ڵ�Ĳ���
*
* �汾��ʷ��
* @Verson  0.1 @date 2014-05-21   jxzhuge12���½��ļ�
*
*/

#ifndef STRINGNODE_H    //��ֹstringNode.h���ظ�����
#define STRINGNODE_H

#include<iostream>
#include<string>
using namespace std;

#include "Node.h"

//�ַ����ڵ��ඨ��
class stringNode :public Node
{
private:
	string val;
public:
	stringNode(string a) :val(a) {}

	/**
	* @brief       ���ܣ�����ַ���
	* @param [in]
	* @return      void
	* @exception
	*/
	void print() const
	{
		cout << val << "    ";
	}

	/**
	* @brief       ���ܣ����ýڵ��ַ���ֵ
	* @param [in]  ������� i��string
	* @return      void
	* @exception
	*/
	void SetVal(string i)
	{
		val = i;
	}
};

#endif