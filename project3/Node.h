/* *
* @copyright 2013-2014, Zhejiang University
* @file   project3
* @brief  ʵ�ֽڵ�Ĳ���
*
* �汾��ʷ��
* @Verson  0.1 @date 2014-05-21   jxzhuge12���½��ļ�
*
*/

#ifndef NODE_H    //��ֹNode.h���ظ�����
#define NODE_H

//�ڵ��ඨ��
class Node
{
private:
	Node *pNext;
public:
	Node() :pNext(0) {}

	/**
	* @brief       ���ܣ��ڽڵ�������½ڵ�
	* @param [in]  ������� p��Node* ��ʾҪ����Ľ��ָ��
	* @return      void
	* @exception   
	*/
	void linkTo(Node *p)
	{
		pNext = p;
	}

	/**
	* @brief       ���ܣ�������һ���ڵ�ָ������
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