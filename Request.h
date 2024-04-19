#pragma once
#include<string>
using namespace std;
class Request
{
	string userName;
	string senderNum;
	float amount;
public:
	Request();
	Request(string userName, string senderNum, float amount);
};

