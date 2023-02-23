#include"employee.h"
#include<iostream>
using namespace std;

void bubbleSort(employee* list, int amount)
{
	for (int i = 0; i < amount - 1; i++)
	{
		if (list[i].calculateWagesbyConst() > list[i + 1].calculateWagesbyConst())
		{
			employee temp = list[i];
			list[i] = list[i + 1];
			list[i + 1] = temp;
		}
	}
	int n =0;
	for (int i = 0; i < amount - 1; i++)
	{
		if (list[i].calculateWagesbyConst() < list[i + 1].calculateWagesbyConst() || list[i].calculateWagesbyConst() == list[i + 1].calculateWagesbyConst())
		{
			n++;
			if (n == amount)
			{
				break;
			}
		}
		else
		{
			bubbleSort(list, amount);
		}
	}
}

