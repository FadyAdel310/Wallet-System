#include "Admin.h"
#include "System.h"


//F12
void Admin::login(string userName, string passWord) {
	if (this->userName != userName || this->passWord != passWord) {
		throw invalidDataToLogin();
	}
}

//F13
vector<string> Admin::viewUsers() {
	if (System::users.size() == 0) {
		throw emptyData();
	}
	else {
		unordered_map<string, User>::iterator it;
		vector<string> usersDisplay;
		for (it = System::users.begin();it != System::users.end();it++) {
			usersDisplay.push_back(it->second.display());
		}
		return usersDisplay;
	}
}

//F14 <= 1
void Admin::addUserAcount(string userName, string passWord) {
	User::registerAccount(userName,passWord);
}

//F15
queue<string> Admin::viewAllTransactions() {
	queue<string> allTransactionsDisplayed;
	queue<Transaction> allTransactions = System::transactions;
	if (allTransactions.size() == 0) {
		throw emptyData();
	}
	else {
		while (!allTransactions.empty())
		{
			allTransactionsDisplayed.push(allTransactions.front().display());
			allTransactions.pop();
		}
	}
	return allTransactionsDisplayed;

}


// F16
void Admin::depositBalance(string userName, float amount) {
	User* specificUser = new User;
	specificUser = System::getUserByUserName(userName);
	if (amount <= 0) {
		throw nonNegativityNum();
	}
	else {
		specificUser->balance += amount;
	}
}

// F17
void Admin::withdrawBalance(string userName, float amount) {
	User* specificUser = new User;
	specificUser = System::getUserByUserName(userName);
	if (amount <= 0) {
		throw nonNegativityNum();
	}
	else if (specificUser->balance < amount) {
		throw insufficientBalance();
	}
	else {
		specificUser->balance -= amount;
	}
}

// F18
void Admin::deleteUserAccount(string userName) {
	User* specificUser = new User;
	specificUser = System::getUserByUserName(userName);
	System::users.erase(specificUser->userName);
}

// F19
void Admin::suspendUser(string userName) {
	User* specificUser = new User;
	specificUser = System::getUserByUserName(userName);
	if (specificUser->activation == false)
		throw userSuspention();
	specificUser->activation = false;
}

// F20
queue<string> Admin::viewUserTransactions(string userName) {
	User* specificUser = new User;
	specificUser = System::getUserByUserName(userName);
	return specificUser->viewTransactions();
}

//F21
void Admin::editUserNameForUserAccount(string userName, string newUserName) {
	User* specificUser = new User;
	specificUser = System::getUserByUserName(userName);
	specificUser->editUserName(newUserName);
}

// F23
void Admin::activateUser(string userName) {
	User* specificUser = new User;
	specificUser = System::getUserByUserName(userName);
	if (specificUser->activation == true)
		throw userSuspention();
	specificUser->activation = true;
}

// ========================

string Admin::toString() {
	return this->userName + "&" + this->passWord ;
}

