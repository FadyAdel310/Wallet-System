#include "Request.h"

Request::Request() {

	this->requestId = "";
	this->userName = "";
	this->senderNum = "";
	this->amount=0;

}
Request::Request(string requestId, string userName, string senderNum, float amount) {
	
	this->requestId = requestId;
	this->userName = userName;
	this->senderNum = senderNum;
	this->amount = amount;

}
