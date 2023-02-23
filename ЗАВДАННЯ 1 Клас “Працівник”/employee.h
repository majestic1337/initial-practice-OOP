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
	void calculateWagesbyCustom();
	void calculateWagesbyConst();
	string initials();

private:
	string fullName;
	int years;
	int hours;
	int normHours;
};

