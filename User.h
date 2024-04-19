#pragma once
#include <string>
#include <vector>
#include <queue>
#include "Request.h"
#include "Transaction.h"

using namespace std;
class User
{
	string userName;
	string passWord;
	float balance;
	bool activation;
	queue <Request> userRequests;
public:
	User();
	User(string fullName, string userName, string passWord);

	//-----------------------------------
	
	//F1 <= 11
	static bool registerAccount(string userName, string passWord);

	//F2 <= 11
	static bool login(string userName, string passWord);

	//F3
	float getBalance();

	//F4 <= 11
	void sendMoney(string userName, float amount);

	//F5 <= 11
	void requestMoney(string senderNum, float amount);
	
	//F6
	vector<Transaction> viewTransactions();

	//F7
	void editPassword(string newPassword);

	//F8 <= 11
	bool editUserName(string newUserName);

	//F9
	queue<Request> viewRequests();

	//F10
	bool deleteRequest(string requestId);

	//-----------------------------------

};

