#include "User.h"

using namespace std;
User::User() {
	this->userName = "";
	this->passWord = "";
	this->balance = 0;
	this->activation = false;
}


//==================
string User::toString() {
	return this->userName + "&" + this->passWord + "&" + to_string(this->balance) + "&" + to_string(this->activation);
}