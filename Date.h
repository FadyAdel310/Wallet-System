#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "StringFunctions.h"
using namespace std;
class Date
{
private:
	int daysOfMonth;
	void validateDaysOfMonth() {
		if (this->month == 1 || this->month == 3 || this->month == 5 ||
			this->month == 7 || this->month == 8 ||
			this->month == 10 || this->month == 12) {
			this->daysOfMonth = 31;
		}
		else if (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11) {
			this->daysOfMonth = 30;
		}
		else {
			if ((this->year % 4) == 0) {
				this->daysOfMonth = 29;
			}
			else {
				this->daysOfMonth = 28;
			}
		}
	}
	static string getMonthVal(string month) {
		if (month == "Jan")
			return "1";
		else if (month == "Feb")
			return "2";
		else if (month == "Mar")
			return "2";
		else if (month == "Apr")
			return "4";
		else if (month == "May")
			return "5";
		else if (month == "June")
			return "6";
		else if (month == "July")
			return "7";
		else if (month == "Aug")
			return "8";
		else if (month == "Sep")
			return "9";
		else if (month == "Oct")
			return "10";
		else if (month == "Nov")
			return "11";
		else if (month == "Dec")
			return "12";
	}
public:
	int day;
	int month;
	int year;

	Date() {
		this->year = 0;
		this->month = 0;
		this->day = 0;
		this->daysOfMonth = 0;
	}

	Date(string dateString) {
		vector<string> itemsList = StringFunctions::split(dateString, '-');
		try {
			this->day = stoi(itemsList[0]);
			this->month = stoi(itemsList[1]);
			this->year = stoi(itemsList[2]);
		}
		catch (exception e) {
			cout << "invalid date string" << endl;
			this->day = 0;
			this->month = 0;
			this->year = 0;
		}

		this->validateDaysOfMonth();
	}

	string toString() {
		return to_string(day) + "-" + to_string(month) + "-" + to_string(year) + "\n";
	}

	static Date getTodayDate() {
		Date dateObj;
		vector<string> itemsList = StringFunctions::split(__DATE__, ' ');
		dateObj.day = stoi(itemsList[1]);
		dateObj.month = stoi(Date::getMonthVal(itemsList[0]));
		dateObj.year = stoi(itemsList[2]);
		dateObj.validateDaysOfMonth();
		return dateObj;
	}
};