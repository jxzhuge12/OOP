/* *
* @copyright 2013-2014, Zhejiang University
* @file   project3
* @brief  实现节点的操作
*
* 版本历史：
* @Verson  0.1 @date 2014-05-21   jxzhuge12：新建文件
*
*/

#ifndef NODE_H    //防止Node.h被重复引用
#define NODE_H

//节点类定义
class Node
{
private:
	Node *pNext;
public:
	Node() :pNext(0) {}

	/**
	* @brief       功能：在节点后连入新节点
	* @param [in]  输入参数 p：Node* 表示要连入的结点指针
	* @return      void
	* @exception   
	*/
	void linkTo(Node *p)
	{
		pNext = p;
	}

	/**
	* @brief       功能：返回下一个节点指针引用
	* @param [in]  
	* @return      Node*&
	* @exception
	*/
	Node*& next()
	{
		return pNext;
	}

	virtual ~Node(){}

	virtual void print() const = 0;
};

#endif