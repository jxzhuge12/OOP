#include<stdlib.h>
using namespace std;

#include "cList.h"

/**
* @brief       ���ܣ��������ͷ���������νڵ�
* @param [in]  ������� val��int ��ʾ���������������ֵ
* @return      void
* @exception
*/
void cList::insert(int val)
{
	intNode *temp = new intNode(val);
	if (pHead == NULL)
	{
		pHead = temp;
	}
	else
	{
		temp->linkTo(pHead);
		pHead = temp;
	}
}

/**
* @brief       ���ܣ��������ͷ�����¸����ͽڵ�
* @param [in]  ������� val��double ��ʾ��������ĸ�������ֵ
* @return      void
* @exception
*/
void cList::insert(double val)
{
	doubleNode *temp = new doubleNode(val);
	if (pHead == NULL)
	{
		pHead = temp;
	}
	else
	{
		temp->linkTo(pHead);
		pHead = temp;
	}
}

/**
* @brief       ���ܣ��������ͷ�������ַ���
* @param [in]  ������� val��string ��ʾ����������ַ���ֵ
* @return      void
* @exception
*/
void cList::insert(string val)
{
	stringNode *temp = new stringNode(val);
	if (pHead == NULL)
	{
		pHead = temp;
	}
	else
	{
		temp->linkTo(pHead);
		pHead = temp;
	}
}

/**
* @brief       ���ܣ��������β���������νڵ�
* @param [in]  ������� val��int ��ʾ���������������ֵ
* @return      void
* @exception
*/
void cList::append(int val)
{
	Node *pTemp = FindTail();
	intNode *temp = new intNode(val);
	if (pTemp == NULL)
	{
		pHead = temp;
	}
	else
	{
		pTemp->linkTo(temp);
	}
}

/**
* @brief       ���ܣ��������β�����¸����ͽڵ�
* @param [in]  ������� val��double ��ʾ��������ĸ�������ֵ
* @return      void
* @exception
*/
void cList::append(double val)
{
	Node *pTemp = FindTail();
	doubleNode *temp = new doubleNode(val);
	if (pTemp == NULL)
	{
		pHead = temp;
	}
	else
	{
		pTemp->linkTo(temp);
	}
}

/**
* @brief       ���ܣ��������β�������ַ���
* @param [in]  ������� val��string ��ʾ����������ַ���ֵ
* @return      void
* @exception
*/
void cList::append(string val)
{
	Node *pTemp = FindTail();
	stringNode *temp = new stringNode(val);
	if (pTemp == NULL)
	{
		pHead = temp;
	}
	else
	{
		pTemp->linkTo(temp);
	}
}

/**
* @brief       ���ܣ���������
* @param [in]
* @return      void
* @exception
*/
void cList::destroy()
{
	Node *p = pHead;
	Node *temp;
	while (p != NULL)
	{
		temp = p;
		p = p->next();
		delete temp;
	}
	pHead = NULL;
}

/**
* @brief       ���ܣ��ҵ�����ָ�����һ���ڵ��ָ��
* @param [in]
* @return      Node*
* @exception
*/
Node* cList::FindTail()
{
	Node *temp = pHead;
	if (temp == NULL)
	{
		return NULL;
	}
	while (temp->next() != NULL){
		temp = temp->next();
	}
	return temp;
}

/**
* @brief       ���ܣ�����ͷ���ָ������
* @param [in]
* @return      Node*&
* @exception
*/
Node*& cList::GetPHead()
{
	return pHead;
}

/**
* @brief       ���ܣ��������������
* @param [in]  ������� out��ostream&  list��cList&
* @return      ostream&
* @exception
*/
ostream& operator<<(ostream& out, cList& list)
{
	Node *temp = list.GetPHead();
	while (temp != NULL){
		temp->print();
		temp = temp->next();
	}
	return out;
}

cList::~cList()
{
	destroy();
}