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
				cout << "À¨ºÅ²»Æ¥Åä£¡" << endl;
				return 0;
			}
			else if (Stack.top() == '[')
			{
				Stack.pop();
			}
			else
			{
				cout << "À¨ºÅ²»Æ¥Åä£¡" << endl;
				return 0;
			}
		}
		else if (input[i] == ')')
		{
			if (Stack.empty())
			{
				cout << "À¨ºÅ²»Æ¥Åä£¡" << endl;
				return 0;
			}
			if (Stack.top() == '(')
			{
				Stack.pop();
			}
			else
			{
				cout << "À¨ºÅ²»Æ¥Åä£¡" << endl;
				return 0;
			}
		}
	}

	if (Stack.empty())
		cout << "À¨ºÅÆ¥Åä£¡" << endl;
	else
		cout << "À¨ºÅ²»Æ¥Åä£¡" << endl;

	return 0;
}