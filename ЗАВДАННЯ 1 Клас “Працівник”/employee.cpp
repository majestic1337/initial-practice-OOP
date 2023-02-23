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

string employee::getName(){ return fullName; }
int employee::getHours(){ return hours; }
int employee::getNorm(){ return normHours; }
int employee::getYears(){ return years; }

void employee::setName(string name) { fullName = name; }
void employee::setYears(int years) { this->years = years; }
void employee::setHours(int hours) { this->hours = hours; }
void employee::setNorm(int norm) { normHours = norm; }

void employee::output()
{
	cout <<endl<< "Full name of worker: " << fullName << endl;
	cout << "Years of working: " << years << endl;
	cout << "Hours of working: " << hours << endl;
	cout << "Norm hours of working: " << normHours << endl;
}

void employee::calculateWagesbyCustom()
{
	cout <<endl<< "Enter salary for hour: ";
	int salary, sum; cin >> salary;
	sum = hours * salary;
	if (hours<normHours){ sum -= (sum * 20) / 100; }
	if (10<=years && years<=20){ sum += sum / 10; }
	if (years > 20) { sum += (sum * 20) / 100; }
	cout <<endl<< "The salary of " << fullName << "is: " << sum << endl;
}

void employee::calculateWagesbyConst()
{
	int salary = 100, sum;
	sum = hours * salary;
	if (hours < normHours) { sum -= (sum * 20) / 100; }
	if (10 <= years && years <= 20) { sum += sum / 10; }
	if (years > 20) { sum += (sum * 20) / 100; }
	cout << endl << "The salary of " << initials() << "is: " << sum << endl;
}


string employee::initials()
{
	string word, initialsName;
	int start = 0, end = fullName.find(' ');
	initialsName += fullName.substr(start, end) + " ";
	start = end + 1;
	end = fullName.find(' ', start);
	word = fullName.substr(start, end - start);
	initialsName = initialsName+ word[0] + ". ";
	start = end + 1;
	word = fullName.substr(start, fullName.length() - start);
	initialsName = initialsName + word[0] + ". ";
	return initialsName;
}

void employee::input()
{
	cout << endl << "Enter name of worker: ";
	cin.ignore(); getline(cin, fullName);
	cout << "Years of working: ";
	cin >> years;
	cout << "Hours of working: ";
	cin >> hours;
	cout << "Norm hours of working: ";
	cin >> normHours;
}

