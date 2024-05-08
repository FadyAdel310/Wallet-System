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
	static unordered_map <string, User> users;  // For Optimazation searching 
	static queue <Transaction> transactions;
	static Admin admin;

	

	//------------------------------------

	//F11
	static User* getUserByUserName(string userName);

	//F22
	static void makeTransaction(Transaction newTransaction);

	//F23
	static string generateRequestId(string userName);

	//---------- Files ------------
	static void loadDataFromFiles();
	static void loadUsersData();
	static void loadRequestsData();
	static void loadAdminData();
	static void loadTransactionsData();

	static void saveDataIntoFiles();
	static void saveUsersData();
	static void saveRequestsData();
	static void saveAdminData();
	static void saveTransactionsData();
};

