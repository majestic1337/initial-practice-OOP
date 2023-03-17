#include<iostream>
#include"employee.h"
#include"fuctions.h"
#include"Windows.h"
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	cout << "¬вед≥ть норму оплати за годину: ";
	int forHour; cin >> forHour;
	cout << "¬вед≥ть к≥льк≥сть прац≥вник≥в: ";
	int numberOfWorkers; cin >> numberOfWorkers;
	employee* list = new employee[numberOfWorkers];
	for (int i = 0; i < numberOfWorkers; i++)
	{
		list[i].setforHour(forHour);
		cin>>list[i];
	}
	cout << endl << "=====================-≤нформац≥€ про прац≥вник≥в-=====================" << endl;
	bubbleSort(list, numberOfWorkers);
	for (int i = 0; i < numberOfWorkers; i++)
	{
		cout << list[i];
		cout << list[i].operator string() << endl;
	}
}
