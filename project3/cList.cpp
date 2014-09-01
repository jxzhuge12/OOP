#include<stdlib.h>
using namespace std;

#include "cList.h"

/**
* @brief       功能：在链表表头插入新整形节点
* @param [in]  输入参数 val：int 表示插入链表的整形数值
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
* @brief       功能：在链表表头插入新浮点型节点
* @param [in]  输入参数 val：double 表示插入链表的浮点型数值
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
* @brief       功能：在链表表头插入新字符串
* @param [in]  输入参数 val：string 表示插入链表的字符串值
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
* @brief       功能：在链表表尾插入新整形节点
* @param [in]  输入参数 val：int 表示插入链表的整形数值
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
* @brief       功能：在链表表尾插入新浮点型节点
* @param [in]  输入参数 val：double 表示插入链表的浮点型数值
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
* @brief       功能：在链表表尾插入新字符串
* @param [in]  输入参数 val：string 表示插入链表的字符串值
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
* @brief       功能：链表销毁
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
* @brief       功能：找到链表指向最后一个节点的指针
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
* @brief       功能：返回头结点指针引用
* @param [in]
* @return      Node*&
* @exception
*/
Node*& cList::GetPHead()
{
	return pHead;
}

/**
* @brief       功能：输出操作符重载
* @param [in]  输入参数 out：ostream&  list：cList&
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