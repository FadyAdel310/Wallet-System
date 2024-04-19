#pragma once
#include <string>
#include <queue>
#include "Transaction.h"
#include "User.h"

using namespace std;
class Admin
{
	static string userName;
	static string passWord;
public:

	//F12
	static bool login(string userName, string passWord);

	//F13
	static vector<User> viewUsers();

	//F14 <= 1
	static bool addUserAcount(string userName, string passWord);

	//F15
	static queue<Transaction> viewAllTransactions();

	//F16
	static void depositBalance(string userName, float amount);
	
	//F17
	static void withdrawBalance(string userName, float amount);

	//F18
	static bool deleteUserAccount(string userName);

	//F19
	static bool suspendUser(string userName);

	//F20
	static queue<Transaction> viewUserTransactions(string userName);

	//F21
	static bool editUserNameForUserAccount(string userName, string newUserName);

};