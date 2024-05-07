#include "Transaction.h"


// ============================

string Transaction::toString() {
	return this->senderNum + "&" + this->recipientNum + "&" + this->transactionDate.toString() + "&" + this->transactionTime.toString() + "&" + to_string(this->amount);
}