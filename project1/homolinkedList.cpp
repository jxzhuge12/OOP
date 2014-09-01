#include"header.h"

/**
* @brief       功能：在链表表头插入新节点
* @param [in]  输入参数 head：PNODE 表示链表头结点指针 a：int 表示要插入链表的数
* @return      void
* @exception   如果输入参数不是有效的链表头结点指针，则终止程序
*/
void inserthead(PNODE head, int a)
{
	if (head == NULL)
		exit(-1);

	PNODE temp = (PNODE) malloc(sizeof(Node));
	temp->val = a;
	temp->pNext = head->pNext;
	head->pNext = temp;
}

/**
* @brief       功能：在链表表尾插入新节点
* @param [in]  输入参数 head：PNODE 表示链表头结点指针 a：int 表示要插入链表的数
* @return      void
* @exception   如果输入参数不是有效的链表头结点指针，则终止程序
*/
void insertend(PNODE head, int a)
{
	if (head == NULL)
		exit(-1);

	PNODE temp = (PNODE) malloc(sizeof(*temp));
	temp->val = a;
	temp->pNext = NULL;

	int num;
	PNODE temp2 = findend(head, &num);
	temp2->pNext = temp;
}

/**
* @brief       功能：在链表第pos项处插入新节点
* @param [in]  输入参数 head：PNODE 表示链表头结点指针 a：int 表示要插入链表的数 pos：int 表示要插入的节点位置
* @return      void
* @exception   如果输入参数不是有效的链表头结点指针，或者插入的位置超过链表长度，则终止程序
*/
void insertpos(PNODE head, int a, int pos)
{
	if (head == NULL)
		exit(-1);

	PNODE temp = (PNODE) malloc(sizeof(*temp));
	temp->val = a;
	temp->pNext = NULL;

	int num;
	int i;
	PNODE temp2 = findend(head, &num);

	if (num <= pos)
		exit(-1);
	else
	{
		for (i = 1; i < pos; i++)
		{
			head = head->pNext;
		}
		temp2 = head->pNext;
		head->pNext = temp;
		temp->pNext = temp2;
	}
}

/**
* @brief       功能：在链表表头删除节点
* @param [in]  输入参数 head：PNODE 表示链表头结点指针
* @return      void
* @exception   如果输入参数不是有效的链表头结点指针，则终止程序
*/
void deletehead(PNODE head)
{
	if (head == NULL)
		exit(-1);

	if (head->pNext == NULL)
		printf("该链表为空链表");
	else
	{
		PNODE temp = head->pNext;
		head->pNext = head->pNext->pNext;
		free(temp);
	}
}

/**
* @brief       功能：在链表表尾删除节点
* @param [in]  输入参数 head：PNODE 表示链表头结点指针
* @return      void
* @exception   如果输入参数不是有效的链表头结点指针，则终止程序
*/
void deleteend(PNODE head)
{
	if (head == NULL)
		exit(-1);

	PNODE temp = head->pNext;
	PNODE temp2 = NULL;
	if (head->pNext == NULL)
		printf("该链表为空链表");
	else
	{
		while (temp->pNext != NULL)
			temp2 = temp;
			temp = temp->pNext;
	}
	temp2->pNext = NULL;
	free(temp);
}

/**
* @brief       功能：在链表第pos项处删除节点
* @param [in]  输入参数 head：PNODE 表示链表头结点指针 pos：int 表示要删除的节点位置
* @return      void
* @exception   如果输入参数不是有效的链表头结点指针，或者删除的位置超过链表长度，则终止程序
*/
void deletepos(PNODE head, int pos)
{
	if (head == NULL)
		exit(-1);

	int num;
	int i;
	PNODE temp2 = findend(head, &num);

	if (num <= pos)
		exit(-1);
	else
	{
		for (i = 1; i < pos; i++)
		{
			head = head->pNext;
		}
		temp2 = head->pNext;
		head->pNext = head->pNext->pNext;
		free(temp2);
	}
}

/**
* @brief       功能：初始化链表
* @param [in]  输入参数 head：PNODE* 表示链表头结点指针地址
* @return      void
*/
void create(PNODE *pHead)
{
	*pHead = (PNODE) malloc(sizeof(pHead));
	(*pHead)->pNext = NULL;
}

/**
* @brief       功能：找到链表最后一个节点
* @param [in]  输入参数 head：PNODE 表示链表头结点指针 num：int * 计算链表长度
* @return      PNODE
* @exception   如果输入参数不是有效的链表头结点指针，则终止程序
*/
PNODE findend(PNODE head, int *num)
{
	if (head == NULL)
		exit(-1);

	*num = 0;
	PNODE temp = head;
	while (temp->pNext != NULL)
	{
		*num = *num + 1;
		temp = temp->pNext;
	}

	return temp;
}

/**
* @brief       功能：链表转置
* @param [in]  输入参数 head：PNODE 表示链表头结点指针
* @return      void
* @exception   如果输入参数不是有效的链表头结点指针，则终止程序
*/
void reverse(PNODE head)
{
	if (head == NULL)
		exit(-1);

	PNODE temp = NULL;
	PNODE temp1 = NULL;
	PNODE temp2 = head->pNext;
	while (temp2 != NULL)
	{
		temp = temp2->pNext;
		temp2->pNext = temp1;
		temp1 = temp2;
		temp2 = temp;
	}
	head->pNext = temp1;
}

/**
* @brief       功能：链表销毁
* @param [in]  输入参数 head：PNODE * 表示链表头结点指针地址
* @return      void
* @exception   如果输入参数不是有效的链表头结点指针，则终止程序
*/
void destroy(PNODE *head)
{
	if (*head == NULL)
		exit(-1);
	
	*head = (*head)->pNext;
	PNODE temp = NULL;
	while ((*head) != NULL)
	{
		temp = *head;
		*head = (*head)->pNext;
		free(temp);
	}
	*head = NULL;
}

/**
* @brief       功能：两链表合并
* @param [in]  输入参数 head1：PNODE 表示链表头结点指针 head2：PNODE 表示链表头结点指针
* @return      PNODE
* @exception   如果输入参数不是有效的链表头结点指针，则终止程序
*/
PNODE concatenate(PNODE head1, PNODE head2)
{
	if (head1 == NULL || head2 == NULL)
		exit(-1);

	PNODE head3 = NULL;
	create(&head3);

	while (head1->pNext != NULL)
	{
		head1 = head1->pNext;
		insertend(head3, head1->val);
	}

	while (head2->pNext != NULL)
	{
		head2 = head2->pNext;
		insertend(head3, head2->val);
	}

	return head3;
}

/**
* @brief       功能：输出链表的每个元素
* @param [in]  输入参数 head：PNODE 表示链表头结点指针
* @return      void
* @exception   如果输入参数不是有效的链表头结点指针，则终止程序
*/
void output(PNODE head)
{
	if (head == NULL)
		exit(-1);

	while (head->pNext != NULL)
	{
		head = head->pNext;
		printf("%d\n", head->val);
	}
}