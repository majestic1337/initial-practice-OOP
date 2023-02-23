#pragma once
#include<string>
using namespace std;

class employee
{
public:
	employee();
	employee(string fullName, int years, int hours, int normHours);
	employee(const employee& other);
	string getName();
	int getYears();
	int getHours();
	int getNorm();
	void setName(string name);
	void setYears(int years);
	void setNorm(int norm);
	void setHours(int hours);
	void input();
	void output();
	string initials();
	int calculateWagesbyCustom();
	int calculateWagesbyConst();
	friend istream& operator>>(istream&, employee&);
	friend ostream& operator<<(ostream&, const employee&);
	bool operator==(employee);
	operator string();
	employee& operator=(employee&);

private:
	string fullName;
	int years;
	int hours;
	int normHours;
};

