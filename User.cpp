#include "User.h"
#include "System.h"

using namespace std;
User::User() {
	this->userName = "";
	this->passWord = "";
	this->balance = 0;
	this->activation = false;
}

//F2 <= 11
void User::login(string userName, string passWord) {
	User *specificUser = System::getUserByUserName(userName);
	if (specificUser->passWord != passWord) {
		throw invalidDataToLogin();
	}
}

//F3
float User::getBalance() {
	return this->balance;
}

//F4 <= 11 && <= 22
void User::sendMoney(string userName, float amount) {
	User* specificUser = System::getUserByUserName(userName);
	if (amount <= 0) {
		throw nonNegativityNum();
	}
	else if (this->balance < amount) {
		throw insufficientBalance();
	}
	else if (this->activation == false || specificUser->activation == false) {
		throw userSuspention();
	}
	else {
		this->balance -= amount;
		specificUser->balance += amount;
		Transaction tr(this->userName, specificUser->userName, amount);
		//System::makeTransaction(tr);
	}
}

//F5 <= 11
void User::requestMoney(string senderNum, float amount) {
	User* specificUser = System::getUserByUserName(senderNum);
	if (amount <= 0) {
		throw nonNegativityNum();
	}
	else if (this->activation == false || specificUser->activation == false) {
		throw userSuspention();
	}
	else {
		Request r(System::generateRequestId(senderNum), senderNum, this->userName, amount);
		specificUser->userRequests.push(r);
	}
}

//==================
string User::toString() {
	return this->userName + "&" + this->passWord + "&" + to_string(this->balance) + "&" + to_string(this->activation);
}