#pragma once
#include <string>
#include <queue>
#include "Transaction.h"
#include "User.h"

using namespace std;
class Admin
{
public:
	 string userName;
	 string passWord;

	//F12
	 void login(string userName, string passWord);

	//F13
	 vector<User> viewUsers();

	//F14 <= 1
	 void addUserAcount(string userName, string passWord);

	//F15
	 queue<Transaction> viewAllTransactions();

	//F16 <= 11
	 void depositBalance(string userName, float amount);
	
	//F17 <= 11
	 void withdrawBalance(string userName, float amount);

	//F18 <= 11
	 void deleteUserAccount(string userName);

	//F19 <= 11
	 void suspendUser(string userName);

	//F20
	 queue<Transaction> viewUserTransactions(string userName);

	//F21 <= 11
	 void editUserNameForUserAccount(string userName, string newUserName);

};