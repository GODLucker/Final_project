#pragma once
#include<iostream>
using namespace std;
class date
{
private:
	int day;
	int month;
	int year;

public:

	date();
	date(int day, int month, int year);

	int get_day();
	void set_day(int day);

	int get_month();
	void set_month(int month);

	int get_year();
	void set_year(int year);
	virtual bool isLongYear();
	
	friend ostream& operator<<(ostream& out, const date& date);
	friend bool operator >=(const date& d1, const date& d2);
	friend bool operator <=(const date& d1, const date& d2);
};

 