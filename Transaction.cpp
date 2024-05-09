#include "Transaction.h"

string Transaction::display() {
	return this->senderNum + " ==> " + this->recipientNum + "\t" + to_string(this->amount) + "\t" + this->transactionDate.toString() + "\t" + this->transactionTime.toString();
}

// ============================

string Transaction::toString() {
	return this->senderNum + "&" + this->recipientNum + "&" + this->transactionDate.toString() + "&" + this->transactionTime.toString() + "&" + to_string(this->amount);
}