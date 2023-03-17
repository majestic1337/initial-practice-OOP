#pragma once
#include"employee.h"
#include<iostream>
using namespace std;

void bubbleSort(employee* list, int amount)
{
	for (int i = 0; i < amount - 1; i++)
	{
		for (int j = 0; j < amount; j++)
		{
			if (list[i].getSalary() > list[i + 1].getSalary())
			{
				employee temp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = temp;
			}
		}
	}
}
