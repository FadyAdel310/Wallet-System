#pragma once
#include <string>
#include "Time.h"
#include "Date.h"

using namespace std;
class Transaction
{
public:
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
	Transaction(){
		this->senderNum = "";
		this->recipientNum = "";
		this->amount = 0;
		this->transactionDate = Date::getTodayDate();
		this->transactionTime = Time::getTimeNow();
	}

	// ==============================================================

	string toString();
};

