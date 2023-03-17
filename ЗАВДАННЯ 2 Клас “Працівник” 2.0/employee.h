#pragma once
#include<string>
using namespace std;

class employee
{
public:
	employee();
	employee(string fullName, int years, int hours, int normHours, int forHour);
	employee(const employee& other);
	string getName();
	int getYears();
	int getHours();
	int getNorm();
	int getSalary();
	void setName(string name);
	void setYears(int years);
	void setNorm(int norm);
	void setHours(int hours);
	void setforHour(int forHour);
	void input();
	void output(int forHour);
	int getWage(int forHour);
	string getInitials();
	friend istream& operator>>(istream&, employee&);
	friend ostream& operator<<(ostream&, const employee&);
	bool operator==(employee);
	operator string();
	employee& operator=(employee&);

private:
	int forHour;
	int salary;
	string fullName;
	string initials;
	int years;
	int hours;
	int normHours;
};