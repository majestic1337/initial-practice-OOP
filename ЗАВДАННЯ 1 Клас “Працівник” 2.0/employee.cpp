#include "employee.h"
#include<iostream>
#include<string>
using namespace std;

employee::employee()
{
	fullName = "";
	years = 0;
	hours = 0;
	normHours = 0;
}

employee::employee(string fullName, int years, int hours, int normHours)
{
	this->fullName = fullName;
	this->years = years;
	this->hours = hours;
	this->normHours = normHours;
}

employee::employee(const employee& other)
{
	this->fullName = other.fullName;
	this->hours = other.hours;
	this->normHours = other.normHours;
	this->years = other.years;
}

string employee::getName() { return fullName; }
int employee::getHours() { return hours; }
int employee::getNorm() { return normHours; }
int employee::getYears() { return years; }

void employee::setName(string name) { fullName = name; }
void employee::setYears(int years) { this->years = years; }
void employee::setHours(int hours) { this->hours = hours; }
void employee::setNorm(int norm) { normHours = norm; }

void employee::output(int forHour)
{
	cout << endl << "Повне ім'я працівника: " << fullName << endl;
	cout << "Стаж працівника: " << years << endl;
	cout << "Відпрацьовано годин: " << hours << endl;
	cout << "Необхідна кількість відпрацьованих годин: " << normHours << endl;
	cout << "Заробітня плата "<<initials() <<"рівна: " << getWage(forHour) << endl;
}

int employee::getWage(int forHour)
{
	int sum;
	sum = hours * forHour;
	if (hours < normHours) { sum -= (sum * 20) / 100; }
	if (10 <= years && years <= 20) { sum += sum / 10; }
	if (years > 20) { sum += (sum * 20) / 100; }
	return sum;
}

string employee::initials()
{
	string word, initialsName;
	int start = 0, end = fullName.find(' ');
	initialsName += fullName.substr(start, end) + " ";
	start = end + 1;
	end = fullName.find(' ', start);
	word = fullName.substr(start, end - start);
	initialsName = initialsName + word[0] + ". ";
	start = end + 1;
	word = fullName.substr(start, fullName.length() - start);
	initialsName = initialsName + word[0] + ". ";
	return initialsName;
}

void employee::input()
{
	cout << endl << "Введіть ПІБ працівника: ";
	cin.ignore(); getline(cin, fullName);
	cout << "Введіть стаж працівника: ";
	cin >> years;
	cout << "Введіть кількість відпрацьованих годин: ";
	cin >> hours;
	cout << "Введіть необхідну кількість відпрацьованих годин: ";
	cin >> normHours;
}
