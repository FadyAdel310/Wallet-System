#pragma once
#include<string>
using namespace std;
class Request
{
	string requestId;
	string userName;
	string senderNum;
	float amount;
public:
	Request();
	
	Request(string requestId,string userName, string senderNum, float amount);
};

