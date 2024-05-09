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
	Transaction(string senderNum, string recipientNum, float amount);
	Transaction();

	string display();

	// ==============================================================

	string toString();
};

