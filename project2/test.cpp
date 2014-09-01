#include <iostream>
#include <string>
using namespace std;
#include "stack.h"

int main(void)
{
	string input;
	stack Stack;
	int i;

	cin >> input;

	for (i = 0; i < input.length(); i++)
	{
		if (input[i] == '['||input[i] == '(')
		{
			Stack.push(input[i]);
		}
		else if (input[i] == ']')
		{
			if (Stack.empty())
			{
				cout << "���Ų�ƥ�䣡" << endl;
				return 0;
			}
			else if (Stack.top() == '[')
			{
				Stack.pop();
			}
			else
			{
				cout << "���Ų�ƥ�䣡" << endl;
				return 0;
			}
		}
		else if (input[i] == ')')
		{
			if (Stack.empty())
			{
				cout << "���Ų�ƥ�䣡" << endl;
				return 0;
			}
			if (Stack.top() == '(')
			{
				Stack.pop();
			}
			else
			{
				cout << "���Ų�ƥ�䣡" << endl;
				return 0;
			}
		}
	}

	if (Stack.empty())
		cout << "����ƥ�䣡" << endl;
	else
		cout << "���Ų�ƥ�䣡" << endl;

	return 0;
}