#include "stack.h"
using namespace std;

/**
* @brief       功能：把数据项从栈顶压入栈内，移动栈顶指示器
* @param [in]  输入参数 a：char 表示要压入栈的字符
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
* @brief       功能：从栈顶弹出数据项，移动栈顶指示器
* @param [in]
* @return      char
* @exception   如果栈是空的，则返回 '0'
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
* @brief       功能：读栈顶数据项，栈顶指示器不变
* @param [in]
* @return      char
* @exception   如果栈是空的，则返回 '0'
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
* @brief       功能：判断栈是否为空
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