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

string Request::display() {
	return this->requestId + "\t" + this->senderNum + "\t" + to_string(this->amount);
}

// ==================================

string Request::toString() {
	return this->userName + "&" + this->requestId + "&" + this->senderNum + "&" + to_string(this->amount) ;
}