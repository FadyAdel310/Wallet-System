#pragma once
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include "User.h"
#include "Admin.h"
#include "CustomExceptions.h"

class System
{
public:
	static unordered_map <string ,User> users;  // For Optimazation searching 
	static queue <Transaction> transactions;
	static Admin admin;

	//------------------------------------

	//F11
	static User getUserByUserName(string userName);

	//F22
	static void makeTransaction(Transaction newTransaction);

};

