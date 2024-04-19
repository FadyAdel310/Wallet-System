#pragma once
#include <map>
#include <unordered_map>
#include<set>
#include <string>
#include "User.h"
#include "Admin.h"

class System
{
public:
	static unordered_map <string ,User> users;
	static set <Transaction> transactions;
	static Admin admin;

	//------------------------------------

	//F11
	static User getUserByUserName(string userName);

};

