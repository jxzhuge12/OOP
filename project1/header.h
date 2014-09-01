/* *
* @copyright 2013-2014, Zhejiang University
* @file   Project1
* @brief  实现同质链表的操作
*
* 版本历史：
* @Verson  0.1 @date 2014-03-14   jxzhuge12：新建文件
*
*/

#ifndef HEADER_H    //防止header.h被重复引用
#define HEADER_H

#include<stdlib.h>
#include<stdio.h>

typedef struct Node *PNODE;

//Node结构体定义
struct Node{
	int val;
	struct Node *pNext;
};

/**
* @brief       功能：在链表表头插入新节点
* @param [in]  输入参数 head：PNODE 表示链表头结点指针 a：int 表示要插入链表的数
* @return      void
* @exception   如果输入参数不是有效的链表头结点指针，则终止程序
*/
extern void inserthead(PNODE head, int a);

/**
* @brief       功能：在链表表尾插入新节点
* @param [in]  输入参数 head：PNODE 表示链表头结点指针 a：int 表示要插入链表的数
* @return      void
* @exception   如果输入参数不是有效的链表头结点指针，则终止程序
*/
extern void insertend(PNODE head, int a);

/**
* @brief       功能：在链表第pos项处插入新节点
* @param [in]  输入参数 head：PNODE 表示链表头结点指针 a：int 表示要插入链表的数 pos：int 表示要插入的节点位置
* @return      void
* @exception   如果输入参数不是有效的链表头结点指针，或者插入的位置超过链表长度，则终止程序
*/
extern void insertpos(PNODE head, int a, int pos);

/**
* @brief       功能：在链表表头删除节点
* @param [in]  输入参数 head：PNODE 表示链表头结点指针
* @return      void
* @exception   如果输入参数不是有效的链表头结点指针，则终止程序
*/
extern void deletehead(PNODE head);

/**
* @brief       功能：在链表表尾删除节点
* @param [in]  输入参数 head：PNODE 表示链表头结点指针
* @return      void
* @exception   如果输入参数不是有效的链表头结点指针，则终止程序
*/
extern void deleteend(PNODE head);

/**
* @brief       功能：在链表第pos项处删除节点
* @param [in]  输入参数 head：PNODE 表示链表头结点指针 pos：int 表示要删除的节点位置
* @return      void
* @exception   如果输入参数不是有效的链表头结点指针，或者删除的位置超过链表长度，则终止程序
*/
extern void deletepos(PNODE head, int pos);

/**
* @brief       功能：初始化链表
* @param [in]  输入参数 head：PNODE * 表示链表头结点指针地址
* @return      void
*/
extern void create(PNODE *head);

/**
* @brief       功能：找到链表最后一个节点
* @param [in]  输入参数 head：PNODE 表示链表头结点指针 num：int * 计算链表长度
* @return      PNODE
* @exception   如果输入参数不是有效的链表头结点指针，则终止程序
*/
extern PNODE findend(PNODE head, int *num);

/**
* @brief       功能：链表转置
* @param [in]  输入参数 head：PNODE 表示链表头结点指针
* @return      void
* @exception   如果输入参数不是有效的链表头结点指针，则终止程序
*/
extern void reverse(PNODE head);

/**
* @brief       功能：链表销毁
* @param [in]  输入参数 head：PNODE * 表示链表头结点指针地址
* @return      void
* @exception   如果输入参数不是有效的链表头结点指针，则终止程序
*/
extern void destroy(PNODE *head);

/**
* @brief       功能：两链表合并
* @param [in]  输入参数 head1：PNODE 表示链表头结点指针 head2：PNODE 表示链表头结点指针
* @return      PNODE
* @exception   如果输入参数不是有效的链表头结点指针，则终止程序
*/
extern PNODE concatenate(PNODE head1, PNODE head2);

/**
* @brief       功能：输出链表的每个元素
* @param [in]  输入参数 head：PNODE 表示链表头结点指针
* @return      void
* @exception   如果输入参数不是有效的链表头结点指针，则终止程序
*/
extern void output(PNODE head);

#endif