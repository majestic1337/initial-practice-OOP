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

void employee::output()
{
	cout << endl << "Full name of worker: " << fullName << endl;
	cout << "Years of working: " << years << endl;
	cout << "Hours of working: " << hours << endl;
	cout << "Norm hours of working: " << normHours << endl;
}

int employee::calculateWagesbyCustom()
{
	cout << endl << "Enter salary for hour: ";
	int sum;  cin >> sum;
	int salary = hours * sum;
	if (hours < normHours) { salary -= (salary * 20) / 100; }
	if (10 <= years && years <= 20) { salary += salary / 10; }
	if (years > 20) { salary += (salary * 20) / 100; }
	return salary;
}

int employee::calculateWagesbyConst()
{
	int sum = 100;
	int salary = hours * sum;
	if (hours < normHours) { salary -= (salary * 20) / 100; }
	if (10 <= years && years <= 20) { salary += salary / 10; }
	if (years > 20) { salary += (salary * 20) / 100; }
	return salary;
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
	cout << endl << "Enter name of worker: ";
	cin.ignore(); getline(cin, fullName);
	cout << "Years of working: ";
	cin >> years;
	cout << "Hours of working: ";
	cin >> hours;
	cout << "Norm hours of working: ";
	cin >> normHours;
}
istream& operator>>(istream& is, employee& current)
{
	cout << endl << "Enter name of worker: ";
	cin.ignore(); getline(is, current.fullName);
	cout << "Years of working: ";
	is >> current.years;
	cout << "Hours of working: ";
	is >> current.hours;
	cout << "Norm hours of working: ";
	is >> current.normHours;
	return is;
}
ostream& operator<<(ostream& os, const employee& current)
{
	os << endl << "Full name of worker: " << current.fullName << endl;
	os << "Years of working: " << current.years << endl;
	os << "Hours of working: " << current.hours << endl;
	os << "Norm hours of working: " << current.normHours << endl;
	return os;
}

bool employee::operator==(employee current)
{
	return calculateWagesbyConst() == current.calculateWagesbyConst();
}

employee& employee::operator=(employee& current)
{
	if (this == &current) { return *this; }
	fullName = current.fullName;
	years = current.years;
	hours = current.hours;
	normHours = current.normHours;
	return *this;
}

employee::operator string()
{
	return fullName + " " + to_string(years) + " " + to_string(hours) + " " + to_string(normHours);
}

