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
	salary = 0;
	forHour = 0;
	initials = "";
}

employee::employee(string fullName, int years, int hours, int normHours, int forHour)
{
	this->fullName = fullName;
	this->years = years;
	this->hours = hours;
	this->normHours = normHours;
	this->forHour = forHour;
	this->salary = getWage(forHour);
	this->initials = getInitials();
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
int employee::getSalary() { return salary; }

void employee::setName(string name) { fullName = name; }
void employee::setYears(int years) { this->years = years; }
void employee::setHours(int hours) { this->hours = hours; }
void employee::setNorm(int norm) { normHours = norm; }
void employee::setforHour(int forHour) { this->forHour = forHour;}

void employee::output(int forHour)
{
	cout << endl << "����� ��'� ����������: " << fullName << endl;
	cout << "���� ����������: " << years << endl;
	cout << "³����������� �����: " << hours << endl;
	cout << "��������� ������� ������������� �����: " << normHours << endl;
	cout << "�������� ����� " << initials << "����: " << salary << endl;
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

string employee::getInitials()
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
	cout << endl << "������ ϲ� ����������: ";
	cin.ignore(); getline(cin, fullName);
	initials = getInitials();
	cout << "������ ���� ����������: ";
	cin >> years;
	cout << "������ ������� ������������� �����: ";
	cin >> hours;
	cout << "������ ��������� ������� ������������� �����: ";
	cin >> normHours;
	salary = getWage(forHour);
}

istream& operator>>(istream& is, employee& current)
{
	cout << endl << "������ ϲ� ����������: ";
	cin.ignore(); getline(is, current.fullName);
	current.initials = current.getInitials();
	cout << "������ ���� ����������: ";
	is >> current.years;
	cout << "������ ������� ������������� �����: ";
	is >> current.hours;
	cout << "������ ��������� ������� ������������� �����: ";
	is >> current.normHours;
	current.salary = current.getWage(current.forHour);
	return is;
}
ostream& operator<<(ostream& os, const employee& current)
{
	os << endl << "����� ��'� ����������: " << current.fullName << endl;
	os << "���� ����������: " << current.years << endl;
	os << "³����������� �����: " << current.hours << endl;
	os << "��������� ������� ������������� �����: " << current.normHours << endl;
	os << "�������� ����� " <<	current.initials << "����: " << current.salary << endl;
	return os;
}

bool employee::operator==(employee current)
{
	return salary == current.salary;
}

employee& employee::operator=(employee& current)
{
	if (this == &current) { return *this; }
	fullName = current.fullName;
	initials = current.initials;
	years = current.years;
	hours = current.hours;
	normHours = current.normHours;
	forHour = current.forHour;
	salary = current.salary;
	return *this;
}

employee::operator string()
{
	return fullName + " " + to_string(years) + " " + to_string(hours) + " " + to_string(normHours)+" "+to_string(salary);
}