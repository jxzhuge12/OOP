#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include"header.h"

void main()
{
	int i;
	PNODE list1 = NULL, list2 = NULL;
	create(&list1);
	create(&list2);
	insertend(list1, 23);
	insertend(list1, 43);
	inserthead(list1, 3);
	inserthead(list1, -13);
	insertpos(list1, 15, 3);
	reverse(list1);
	insertend(list2, 24);
	insertend(list2, 44);
	inserthead(list2, 4);
	inserthead(list2, -14);
	insertpos(list2, 12, 2);
	PNODE list3 = concatenate(list1, list2);
	destroy(&list1);

	//output(list1); //若此行不备注，则程序退出运行，返回值为 -1
	printf("\n");
	output(list2);
	printf("\n");
	output(list3);

	scanf("%d", &i);
}
