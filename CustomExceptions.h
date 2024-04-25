#pragma once
#include <exception>
using namespace std;

class userNotFoundEx : public exception
{
public:
	userNotFoundEx() {}
};

class requestIdNotFound : public exception
{
public:
	requestIdNotFound() {}
};

class invalidDataToLogin : public exception
{
public:
	invalidDataToLogin() {}
};

class usernameExit : public exception
{
public:
	usernameExit() {}
};

class nonNegativityNum : public exception
{
public:
	nonNegativityNum() {}
};

class insufficientBalance : public exception
{
public:
	insufficientBalance() {}
};

class emptyData : public exception
{
public:
	emptyData() {}
};