#include "Transaction.h"
#include <string>

using namespace std;

Transaction::Transaction() {
	this->senderNum = "";
	this->recipientNum = "";
	this->amount = 0;
	this->transactionDate = Date::getTodayDate();
	this->transactionTime = Time::getTimeNow();
}

Transaction::Transaction(string senderNum, string recipientNum, float amount) {
	this->senderNum = senderNum;
	this->recipientNum = recipientNum;
	this->amount = amount;
	this->transactionDate = Date::getTodayDate();
	this->transactionTime = Time::getTimeNow();
}

string Transaction::display() {
	return this->senderNum + " ==> " + this->recipientNum + "\t" + to_string(this->amount) + "\t" + this->transactionDate.toString() + "\t" + this->transactionTime.toString();
}

// ============================

string Transaction::toString() {
	return this->senderNum + "&" + this->recipientNum + "&" + this->transactionDate.toString() + "&" + this->transactionTime.toString() + "&" + to_string(this->amount);
}