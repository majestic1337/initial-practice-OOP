#include<iostream>
#include"employee.h"
#include"Windows.h"
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	cout << "������ ����� ������ �� ������: ";
	int forHour; cin >> forHour;
	cout << "������ ������� ����������: ";
	int numberOfWorkers; cin >> numberOfWorkers;
	employee* list = new employee[numberOfWorkers];
	for (int i = 0; i < numberOfWorkers; i++)
	{
		list[i].input();
	}
	cout << endl << "=====================-���������� ��� ����������-=====================" << endl;
	for (int i = 0; i < numberOfWorkers; i++)
	{
		list[i].output(forHour);
	}
}
