#pragma once
#include <exception>
using namespace std;

class userNotFound : public exception
{
public:
	userNotFound() {}
};

class userSuspention : public exception
{
public:
	userSuspention() {}
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

class usernameUsed : public exception
{
public:
	usernameUsed() {}
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