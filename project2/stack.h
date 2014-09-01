/* *
* @copyright 2013-2014, Zhejiang University
* @file   Project2
* @brief  实现栈的操作
*
* 版本历史：
* @Verson  0.1 @date 2014-05-10   jxzhuge12：新建文件
*
*/

#ifndef STACK_H    //防止stack.h被重复引用
#define STACK_H

typedef struct Node *PNODE;

#include<stdlib.h>

//Node结构体定义
struct Node
{
	char val;
	PNODE pNext;
};

//stack类定义
class stack{
private:
	PNODE pNode;
	stack(const stack&);
	stack& operator=(const stack&);
public:
	/**
	* @brief       功能：初始化栈，设栈顶为空
	* @param [in]  
	*/
	stack()
	{
		pNode = NULL;
	}
	/**
	* @brief       功能：清空栈
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
	* @brief       功能：把数据项从栈顶压入栈内，移动栈顶指示器
	* @param [in]  输入参数 a：char 表示要压入栈的字符
	* @return      void
	* @exception
	*/
	void push(char a);

	/**
	* @brief       功能：从栈顶弹出数据项，移动栈顶指示器
	* @param [in]  
	* @return      char
	* @exception   如果栈是空的，则返回 '0'
	*/
	char pop();

	/**
	* @brief       功能：读栈顶数据项，栈顶指示器不变
	* @param [in]  
	* @return      char
	* @exception   如果栈是空的，则返回 '0'
	*/
	char top() const;

	/**
	* @brief       功能：判断栈是否为空
	* @param [in]  
	* @return      bool
	* @exception   
	*/
	bool empty() const;
};

#endif