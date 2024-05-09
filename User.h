#pragma once
#include <string>
#include <vector>
#include <queue>
#include "Request.h"
#include "Transaction.h"

using namespace std;
class User
{
public:
	string userName;
	string passWord;
	float balance;
	bool activation;
	queue <Request> userRequests;
	User();
	User(string userName, string passWord);

	//-----------------------------------
	
	//F1 <= 11
	static void registerAccount(string userName, string passWord);

	//F2 <= 11
	static void login(string userName, string passWord);

	//F3
	float getBalance();

	//F4 <= 11
	void sendMoney(string userName, float amount);

	//F5 <= 11
	void requestMoney(string senderNum, float amount);
	
	//F6
	queue<string> viewTransactions();

	//F7
	void editPassword(string newPassword);

	//F8 <= 11
	void editUserName(string newUserName);

	//F9
	queue<string> viewRequests();

	//F10
	void deleteRequest(string requestId);

	//F24
	string display();
	
	//-----------------------------------

	string toString();


};

