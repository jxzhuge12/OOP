#include "stack.h"
using namespace std;

/**
* @brief       ���ܣ����������ջ��ѹ��ջ�ڣ��ƶ�ջ��ָʾ��
* @param [in]  ������� a��char ��ʾҪѹ��ջ���ַ�
* @return      void
* @exception
*/
void stack::push(char a)
{
	PNODE temp = (PNODE) malloc(sizeof(Node));
	temp->val = a;
	temp->pNext = pNode;
	pNode = temp;
}

/**
* @brief       ���ܣ���ջ������������ƶ�ջ��ָʾ��
* @param [in]
* @return      char
* @exception   ���ջ�ǿյģ��򷵻� '0'
*/
char stack::pop()
{
	if (pNode != NULL)
	{
		char temp = pNode->val;
		PNODE tempPN = pNode;
		pNode = pNode->pNext;
		free(tempPN);
		return temp;
	}
	else
		return '0';
}

/**
* @brief       ���ܣ���ջ�������ջ��ָʾ������
* @param [in]
* @return      char
* @exception   ���ջ�ǿյģ��򷵻� '0'
*/
char stack::top() const
{
	if (pNode != NULL)
	{
		return pNode->val;
	}
	else
		return '0';
}

/**
* @brief       ���ܣ��ж�ջ�Ƿ�Ϊ��
* @param [in]
* @return      bool
* @exception
*/
bool stack::empty() const
{
	if (pNode == NULL)
		return true;
	else
		return false;
}