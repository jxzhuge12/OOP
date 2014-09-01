#include"header.h"

/**
* @brief       ���ܣ��������ͷ�����½ڵ�
* @param [in]  ������� head��PNODE ��ʾ����ͷ���ָ�� a��int ��ʾҪ�����������
* @return      void
* @exception   ����������������Ч������ͷ���ָ�룬����ֹ����
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
* @brief       ���ܣ��������β�����½ڵ�
* @param [in]  ������� head��PNODE ��ʾ����ͷ���ָ�� a��int ��ʾҪ�����������
* @return      void
* @exception   ����������������Ч������ͷ���ָ�룬����ֹ����
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
* @brief       ���ܣ��������pos������½ڵ�
* @param [in]  ������� head��PNODE ��ʾ����ͷ���ָ�� a��int ��ʾҪ����������� pos��int ��ʾҪ����Ľڵ�λ��
* @return      void
* @exception   ����������������Ч������ͷ���ָ�룬���߲����λ�ó��������ȣ�����ֹ����
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
* @brief       ���ܣ��������ͷɾ���ڵ�
* @param [in]  ������� head��PNODE ��ʾ����ͷ���ָ��
* @return      void
* @exception   ����������������Ч������ͷ���ָ�룬����ֹ����
*/
void deletehead(PNODE head)
{
	if (head == NULL)
		exit(-1);

	if (head->pNext == NULL)
		printf("������Ϊ������");
	else
	{
		PNODE temp = head->pNext;
		head->pNext = head->pNext->pNext;
		free(temp);
	}
}

/**
* @brief       ���ܣ��������βɾ���ڵ�
* @param [in]  ������� head��PNODE ��ʾ����ͷ���ָ��
* @return      void
* @exception   ����������������Ч������ͷ���ָ�룬����ֹ����
*/
void deleteend(PNODE head)
{
	if (head == NULL)
		exit(-1);

	PNODE temp = head->pNext;
	PNODE temp2 = NULL;
	if (head->pNext == NULL)
		printf("������Ϊ������");
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
* @brief       ���ܣ��������pos�ɾ���ڵ�
* @param [in]  ������� head��PNODE ��ʾ����ͷ���ָ�� pos��int ��ʾҪɾ���Ľڵ�λ��
* @return      void
* @exception   ����������������Ч������ͷ���ָ�룬����ɾ����λ�ó��������ȣ�����ֹ����
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
* @brief       ���ܣ���ʼ������
* @param [in]  ������� head��PNODE* ��ʾ����ͷ���ָ���ַ
* @return      void
*/
void create(PNODE *pHead)
{
	*pHead = (PNODE) malloc(sizeof(pHead));
	(*pHead)->pNext = NULL;
}

/**
* @brief       ���ܣ��ҵ��������һ���ڵ�
* @param [in]  ������� head��PNODE ��ʾ����ͷ���ָ�� num��int * ����������
* @return      PNODE
* @exception   ����������������Ч������ͷ���ָ�룬����ֹ����
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
* @brief       ���ܣ�����ת��
* @param [in]  ������� head��PNODE ��ʾ����ͷ���ָ��
* @return      void
* @exception   ����������������Ч������ͷ���ָ�룬����ֹ����
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
* @brief       ���ܣ���������
* @param [in]  ������� head��PNODE * ��ʾ����ͷ���ָ���ַ
* @return      void
* @exception   ����������������Ч������ͷ���ָ�룬����ֹ����
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
* @brief       ���ܣ�������ϲ�
* @param [in]  ������� head1��PNODE ��ʾ����ͷ���ָ�� head2��PNODE ��ʾ����ͷ���ָ��
* @return      PNODE
* @exception   ����������������Ч������ͷ���ָ�룬����ֹ����
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
* @brief       ���ܣ���������ÿ��Ԫ��
* @param [in]  ������� head��PNODE ��ʾ����ͷ���ָ��
* @return      void
* @exception   ����������������Ч������ͷ���ָ�룬����ֹ����
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