/* *
* @copyright 2013-2014, Zhejiang University
* @file   Project2
* @brief  ʵ��ջ�Ĳ���
*
* �汾��ʷ��
* @Verson  0.1 @date 2014-05-10   jxzhuge12���½��ļ�
*
*/

#ifndef STACK_H    //��ֹstack.h���ظ�����
#define STACK_H

typedef struct Node *PNODE;

#include<stdlib.h>

//Node�ṹ�嶨��
struct Node
{
	char val;
	PNODE pNext;
};

//stack�ඨ��
class stack{
private:
	PNODE pNode;
	stack(const stack&);
	stack& operator=(const stack&);
public:
	/**
	* @brief       ���ܣ���ʼ��ջ����ջ��Ϊ��
	* @param [in]  
	*/
	stack()
	{
		pNode = NULL;
	}
	/**
	* @brief       ���ܣ����ջ
	* @param [in]
	*/
	~stack()
	{
		if (!empty())
		{
			pop();
		}
	}

	/**
	* @brief       ���ܣ����������ջ��ѹ��ջ�ڣ��ƶ�ջ��ָʾ��
	* @param [in]  ������� a��char ��ʾҪѹ��ջ���ַ�
	* @return      void
	* @exception
	*/
	void push(char a);

	/**
	* @brief       ���ܣ���ջ������������ƶ�ջ��ָʾ��
	* @param [in]  
	* @return      char
	* @exception   ���ջ�ǿյģ��򷵻� '0'
	*/
	char pop();

	/**
	* @brief       ���ܣ���ջ�������ջ��ָʾ������
	* @param [in]  
	* @return      char
	* @exception   ���ջ�ǿյģ��򷵻� '0'
	*/
	char top() const;

	/**
	* @brief       ���ܣ��ж�ջ�Ƿ�Ϊ��
	* @param [in]  
	* @return      bool
	* @exception   
	*/
	bool empty() const;
};

#endif