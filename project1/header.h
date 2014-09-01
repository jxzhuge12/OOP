/* *
* @copyright 2013-2014, Zhejiang University
* @file   Project1
* @brief  ʵ��ͬ������Ĳ���
*
* �汾��ʷ��
* @Verson  0.1 @date 2014-03-14   jxzhuge12���½��ļ�
*
*/

#ifndef HEADER_H    //��ֹheader.h���ظ�����
#define HEADER_H

#include<stdlib.h>
#include<stdio.h>

typedef struct Node *PNODE;

//Node�ṹ�嶨��
struct Node{
	int val;
	struct Node *pNext;
};

/**
* @brief       ���ܣ��������ͷ�����½ڵ�
* @param [in]  ������� head��PNODE ��ʾ����ͷ���ָ�� a��int ��ʾҪ�����������
* @return      void
* @exception   ����������������Ч������ͷ���ָ�룬����ֹ����
*/
extern void inserthead(PNODE head, int a);

/**
* @brief       ���ܣ��������β�����½ڵ�
* @param [in]  ������� head��PNODE ��ʾ����ͷ���ָ�� a��int ��ʾҪ�����������
* @return      void
* @exception   ����������������Ч������ͷ���ָ�룬����ֹ����
*/
extern void insertend(PNODE head, int a);

/**
* @brief       ���ܣ��������pos������½ڵ�
* @param [in]  ������� head��PNODE ��ʾ����ͷ���ָ�� a��int ��ʾҪ����������� pos��int ��ʾҪ����Ľڵ�λ��
* @return      void
* @exception   ����������������Ч������ͷ���ָ�룬���߲����λ�ó��������ȣ�����ֹ����
*/
extern void insertpos(PNODE head, int a, int pos);

/**
* @brief       ���ܣ��������ͷɾ���ڵ�
* @param [in]  ������� head��PNODE ��ʾ����ͷ���ָ��
* @return      void
* @exception   ����������������Ч������ͷ���ָ�룬����ֹ����
*/
extern void deletehead(PNODE head);

/**
* @brief       ���ܣ��������βɾ���ڵ�
* @param [in]  ������� head��PNODE ��ʾ����ͷ���ָ��
* @return      void
* @exception   ����������������Ч������ͷ���ָ�룬����ֹ����
*/
extern void deleteend(PNODE head);

/**
* @brief       ���ܣ��������pos�ɾ���ڵ�
* @param [in]  ������� head��PNODE ��ʾ����ͷ���ָ�� pos��int ��ʾҪɾ���Ľڵ�λ��
* @return      void
* @exception   ����������������Ч������ͷ���ָ�룬����ɾ����λ�ó��������ȣ�����ֹ����
*/
extern void deletepos(PNODE head, int pos);

/**
* @brief       ���ܣ���ʼ������
* @param [in]  ������� head��PNODE * ��ʾ����ͷ���ָ���ַ
* @return      void
*/
extern void create(PNODE *head);

/**
* @brief       ���ܣ��ҵ��������һ���ڵ�
* @param [in]  ������� head��PNODE ��ʾ����ͷ���ָ�� num��int * ����������
* @return      PNODE
* @exception   ����������������Ч������ͷ���ָ�룬����ֹ����
*/
extern PNODE findend(PNODE head, int *num);

/**
* @brief       ���ܣ�����ת��
* @param [in]  ������� head��PNODE ��ʾ����ͷ���ָ��
* @return      void
* @exception   ����������������Ч������ͷ���ָ�룬����ֹ����
*/
extern void reverse(PNODE head);

/**
* @brief       ���ܣ���������
* @param [in]  ������� head��PNODE * ��ʾ����ͷ���ָ���ַ
* @return      void
* @exception   ����������������Ч������ͷ���ָ�룬����ֹ����
*/
extern void destroy(PNODE *head);

/**
* @brief       ���ܣ�������ϲ�
* @param [in]  ������� head1��PNODE ��ʾ����ͷ���ָ�� head2��PNODE ��ʾ����ͷ���ָ��
* @return      PNODE
* @exception   ����������������Ч������ͷ���ָ�룬����ֹ����
*/
extern PNODE concatenate(PNODE head1, PNODE head2);

/**
* @brief       ���ܣ���������ÿ��Ԫ��
* @param [in]  ������� head��PNODE ��ʾ����ͷ���ָ��
* @return      void
* @exception   ����������������Ч������ͷ���ָ�룬����ֹ����
*/
extern void output(PNODE head);

#endif