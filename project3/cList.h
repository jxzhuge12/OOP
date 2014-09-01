/* *
* @copyright 2013-2014, Zhejiang University
* @file   project3
* @brief  实现异质链表的操作
*
* 版本历史：
* @Verson  0.1 @date 2014-05-21   jxzhuge12：新建文件
*
*/

#ifndef CLIST_H    //防止header.h被重复引用
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
	* @brief       功能：在链表表头插入新整形节点
	* @param [in]  输入参数 val：int 表示插入链表的整形数值
	* @return      void
	* @exception   
	*/
	void insert(int val);

	/**
	* @brief       功能：在链表表头插入新浮点型节点
	* @param [in]  输入参数 val：double 表示插入链表的浮点型数值
	* @return      void
	* @exception
	*/
	void insert(double val);

	/**
	* @brief       功能：在链表表头插入新字符串
	* @param [in]  输入参数 val：string 表示插入链表的字符串值
	* @return      void
	* @exception
	*/
	void insert(string val);

	/**
	* @brief       功能：在链表表尾插入新整形节点
	* @param [in]  输入参数 val：int 表示插入链表的整形数值
	* @return      void
	* @exception
	*/
	void append(int val);

	/**
	* @brief       功能：在链表表尾插入新浮点型节点
	* @param [in]  输入参数 val：double 表示插入链表的浮点型数值
	* @return      void
	* @exception
	*/
	void append(double val);

	/**
	* @brief       功能：在链表表尾插入新字符串
	* @param [in]  输入参数 val：string 表示插入链表的字符串值
	* @return      void
	* @exception
	*/
	void append(string val);

	/**
	* @brief       功能：链表销毁
	* @param [in]  
	* @return      void
	* @exception  
	*/
	void destroy();

	/**
	* @brief       功能：找到链表指向最后一个节点的指针
	* @param [in]  
	* @return      Node*
	* @exception   
	*/
	Node* FindTail();

	/**
	* @brief       功能：返回头结点指针引用
	* @param [in]
	* @return      Node*&
	* @exception
	*/
	Node*& GetPHead();

	/**
	* @brief       功能：输出操作符重载
	* @param [in]  输入参数 out：ostream&  list：cList&
	* @return      ostream&
	* @exception
	*/
	friend ostream& operator<<(ostream& out, cList& list);

	~cList();
};

#endif