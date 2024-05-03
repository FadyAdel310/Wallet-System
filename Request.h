#pragma once
#include<string>
using namespace std;
class Request
{
public:
	string userName;
	string requestId;
	string senderNum;
	float amount;
	
	Request();

	Request(string requestId,string userName, string senderNum, float amount);
};

