#pragma once
#include <string>
#include "Time.h"
#include "Date.h"

using namespace std;
class Transaction
{
	string senderNum;
	string recipientNum;
	Date transactionDate;
	Time transactionTime;
	float amount;
	Transaction(string senderNum,string recipientNum,float amount){
		this->senderNum = senderNum;
		this->recipientNum = recipientNum;
		this->amount = amount;
		this->transactionDate = Date::getTodayDate();
		this->transactionTime = Time::getTimeNow();
	}
};

