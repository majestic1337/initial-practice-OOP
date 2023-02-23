#include<iostream>
#include<string>
#include"employee.h"
using namespace std;

int main()
{
	int amount; cin >> amount;
	employee* list = new employee[amount];
	for (int i = 0; i < amount; i++)
	{
		list[i].input();
	}
	for (int i = 0; i < amount; i++)
	{
		list[i].output();
	}
	for (int i = 0; i < amount; i++)
	{
		list[i].calculateWagesbyConst();
	}
}