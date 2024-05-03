#pragma once
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include "User.h"
#include "Admin.h"
#include "CustomExceptions.h"
#include "FileHandler.h"
#include <vector>

using namespace std;

class System
{
public:
	unordered_map <string, User> users;  // For Optimazation searching 
	queue <Transaction> transactions;
	Admin admin;

	//------------------------------------

	//F11
	 User getUserByUserName(string userName);

	//F22
	 void makeTransaction(Transaction newTransaction);


	//---------- Files ------------
	 void loadDataFromFiles();

	 void loadUsersData();
	 void loadRequestsDate();
	 void loadAdminData();
	 void loadTransactionsData();

};

