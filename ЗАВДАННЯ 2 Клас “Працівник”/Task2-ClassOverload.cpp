#include<iostream>
#include<string>
#include"employee.h"
#include"functions.h"
using namespace std;

int main()
{
	int amount; cin >> amount;
	employee* list = new employee[amount];
	for (int i = 0; i < amount; i++)
	{
		cin >> list[i];
	}
	bubbleSort(list, amount);
	for (int i = 0; i < amount; i++)
	{
		cout << list[i];
		cout << "Salary: " << list[i].calculateWagesbyConst();
	}
}