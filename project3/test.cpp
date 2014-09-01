#include<iostream>
using namespace std;

#include "Node.h"
#include "intNode.h"
#include "doubleNode.h"
#include "stringNode.h"
#include "cList.h"

void main()
{
	cList list1;
	list1.insert(23);
	list1.insert(43.45);
	list1.insert("hello");
	list1.append(1);
	list1.append("world");
	cout << list1;  //Êä³ö£ºhello    43.45    23    1    world
	cout << endl;
	list1.destroy();
	list1.insert(2.5);
	list1.append("jxzhuge12");
	list1.insert(1141);
	cout << list1;  //Êä³ö£º1141    2.5    jxzhuge12
}
