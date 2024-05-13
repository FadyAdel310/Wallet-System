#include "User.h"
#include "System.h"

using namespace std;
User::User() {
	this->userName = "";
	this->passWord = "";
	this->balance = 0;
	this->activation = false;
}
User::User(string userName,string passWord) {
	this->userName = userName ;
	this->passWord = passWord;
	this->balance = 0;
	this->activation = true;
}

//F1 <= 11
void User::registerAccount(string userName, string passWord) {
	if (System::users[userName].userName != "") {
		throw usernameUsed();
	}
	else {
		User tempUser;
		tempUser.userName = userName;
		tempUser.passWord = passWord;
		tempUser.balance = 0;
		tempUser.activation = true;
		System::users[userName] = tempUser;
	}
}

//F2 <= 11
void User::login(string userName, string passWord) {
	User *specificUser = System::getUserByUserName(userName);
	if (specificUser->passWord != passWord) {
		throw invalidDataToLogin();
	}
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
		System::makeTransaction(tr);
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

//F6
queue<string> User::viewTransactions() {
	queue<string> userTransactions;
	queue<Transaction> allTransactions = System::transactions;
	if (allTransactions.size() == 0) {
		throw emptyData();
	}
	else {
		while (!allTransactions.empty())
		{
			if (allTransactions.front().senderNum == this->userName ||
				allTransactions.front().recipientNum == this->userName) {
				userTransactions.push(allTransactions.front().display());
			}
			allTransactions.pop();
		}
	}
	return userTransactions;
}

//F7
void User::editPassword(string newPassword) {
	if (newPassword.length() < 4) {
		throw weakPassword();
		return;
	}
	else {
		this->passWord = newPassword;
	}
}

//F8 <=11
//void User::editUserName(string newUserName) {
//	if (System::users.find(newUserName) == System::users.end() ) {
//		this->userName = newUserName;
//	}
//	else {
//		throw usernameUsed();
//	}
//}

//F9
queue<string> User::viewRequests() {
	queue<string> requestsDisplay;
	queue<Request> tempUserRequests = this->userRequests;
	if (this->userRequests.size() == 0) {
		throw emptyData();
	}
	else {
		while (!tempUserRequests.empty())
		{
			requestsDisplay.push(tempUserRequests.front().display());
			tempUserRequests.pop();
		}
		return requestsDisplay;
	}
}

//F10
void User::deleteRequest(string requestId) {
	if (stoi(requestId) < 1 || stoi(requestId) > stoi(this->userRequests.back().requestId)) {
		cout << stoi(requestId) << endl;
		throw requestIdNotFound();
	}
	else {
		queue<Request> tempUserRequests = this->userRequests;
		queue<Request> updatedUserRequest;
		while (!tempUserRequests.empty())
		{
			if (tempUserRequests.front().requestId != requestId) {
				updatedUserRequest.push(tempUserRequests.front());
			}
			tempUserRequests.pop();
		}
		this->userRequests = updatedUserRequest;
	}
}

// F24
string User::display() {
	string activationStat = this->activation == true ? "active" : "inactive";
	return this->userName + "\t" + this->passWord + "\t" + to_string(this->balance) + "\t" + activationStat;
}

//==================
string User::toString() {
	return this->userName + "&" + this->passWord + "&" + to_string(this->balance) + "&" + to_string(this->activation);
}