#include "Admin.h"
#include "System.h"




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
	specificUser = System::getUserByUserName(userName); // to verfiy if user is not found
	System::users.erase(userName);
}

// F19
void Admin::suspendUser(string userName) {
	User* specificUser = new User;
	specificUser = System::getUserByUserName(userName);
	if (specificUser->activation == false)
		throw usernameUsed();
	specificUser->activation = false;
}

// F20
queue<Transaction> Admin::viewUserTransactions(string userName) {
	User* specificUser = new User;
	specificUser = System::getUserByUserName(userName);
	queue<Transaction> userTransactions;
	queue<Transaction> allTransactions = System::transactions;
	while (!allTransactions.empty())
	{
		if (allTransactions.front().senderNum == specificUser->userName ||
			allTransactions.front().recipientNum == specificUser->userName) {
			userTransactions.push(System::transactions.front());
		}
		allTransactions.pop();
	}
	
	return userTransactions;
}

//F21
void Admin::editUserNameForUserAccount(string userName, string newUserName) {
	User* specificUser = new User;
	specificUser = System::getUserByUserName(userName);
	if (System::users[newUserName].userName == "") {
		specificUser->userName = newUserName;
	}
	else {
		throw usernameUsed();
	}

}

// F23
void Admin::activateUser(string userName) {
	User* specificUser = new User;
	specificUser = System::getUserByUserName(userName);
	if (specificUser->activation == true)
		throw usernameUsed();
	specificUser->activation = true;
}

// ========================

string Admin::toString() {
	return this->userName + "&" + this->passWord ;
}

