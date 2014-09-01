/* *
* @copyright 2013-2014, Zhejiang University
* @file   project3
* @brief  ʵ����������Ĳ���
*
* �汾��ʷ��
* @Verson  0.1 @date 2014-05-21   jxzhuge12���½��ļ�
*
*/

#ifndef CLIST_H    //��ֹheader.h���ظ�����
#define CLIST_H

#include<iostream>
#include<string>
using namespace std;

#include "Node.h"
#include "intNode.h"
#include "doubleNode.h"
#include "stringNode.h"

class cList
{
private:
	Node *pHead;
public:
	cList() :pHead(NULL) {}

	/**
	* @brief       ���ܣ��������ͷ���������νڵ�
	* @param [in]  ������� val��int ��ʾ���������������ֵ
	* @return      void
	* @exception   
	*/
	void insert(int val);

	/**
	* @brief       ���ܣ��������ͷ�����¸����ͽڵ�
	* @param [in]  ������� val��double ��ʾ��������ĸ�������ֵ
	* @return      void
	* @exception
	*/
	void insert(double val);

	/**
	* @brief       ���ܣ��������ͷ�������ַ���
	* @param [in]  ������� val��string ��ʾ����������ַ���ֵ
	* @return      void
	* @exception
	*/
	void insert(string val);

	/**
	* @brief       ���ܣ��������β���������νڵ�
	* @param [in]  ������� val��int ��ʾ���������������ֵ
	* @return      void
	* @exception
	*/
	void append(int val);

	/**
	* @brief       ���ܣ��������β�����¸����ͽڵ�
	* @param [in]  ������� val��double ��ʾ��������ĸ�������ֵ
	* @return      void
	* @exception
	*/
	void append(double val);

	/**
	* @brief       ���ܣ��������β�������ַ���
	* @param [in]  ������� val��string ��ʾ����������ַ���ֵ
	* @return      void
	* @exception
	*/
	void append(string val);

	/**
	* @brief       ���ܣ���������
	* @param [in]  
	* @return      void
	* @exception  
	*/
	void destroy();

	/**
	* @brief       ���ܣ��ҵ�����ָ�����һ���ڵ��ָ��
	* @param [in]  
	* @return      Node*
	* @exception   
	*/
	Node* FindTail();

	/**
	* @brief       ���ܣ�����ͷ���ָ������
	* @param [in]
	* @return      Node*&
	* @exception
	*/
	Node*& GetPHead();

	/**
	* @brief       ���ܣ��������������
	* @param [in]  ������� out��ostream&  list��cList&
	* @return      ostream&
	* @exception
	*/
	friend ostream& operator<<(ostream& out, cList& list);

	~cList();
};

#endif