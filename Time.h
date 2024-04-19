#pragma once
#include <string>
#include <vector>
#include "StringFunctions.h"
using namespace std;
class Time
{
public:
	int hour, minute, second;
	Time(){
		this->hour = 0;
		this->minute = 0;
		this->second = 0;
	}
	Time(string timeString){
		try {
			vector <string> itemsList = StringFunctions::split(timeString, ':');
			this->hour = stoi(itemsList[0]);
			this->minute = stoi(itemsList[1]);
			this->second = stoi(itemsList[2]);

		}
		catch (exception e) {
			cout << "invalid time string" << endl;
			this->hour = 0;
			this->minute = 0;
			this->second = 0;
		}
	}
	string toString(){
		return to_string(this->hour) + ":" + to_string(this->minute) + ":" + to_string(this->second);
	}
	static Time getTimeNow(){
		string time = __TIME__;
		Time timeObj;
		vector <string> itemsList = StringFunctions::split(time, ':');
		timeObj.hour = stoi(itemsList[0]);
		timeObj.minute = stoi(itemsList[1]);
		timeObj.second = stoi(itemsList[2]);
		return timeObj;
	}
};

