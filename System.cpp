#include "System.h"

void System::loadDataFromFiles() {
	loadUsersData();
	loadRequestsDate();
	loadAdminData();
	loadTransactionsData();
}
void System::loadUsersData() {
	vector<string> dataList = FileHandler::ReadFromFile("F:/Programming/c++ projects/Wallet-System/files/users.txt");
	for (int i = 0; i < dataList.size(); i++) {
		vector <string> dataRow = StringFunctions::split(dataList[i], '&');
		User tempUser;
		tempUser.userName = dataRow[0];
		tempUser.passWord = dataRow[1];
		tempUser.balance = stof(dataRow[2]);
		tempUser.activation = dataRow[3] == "1";
		this->users.insert(make_pair(dataRow[0], tempUser));
	}
}
void System::loadRequestsDate() {
	vector<string> dataList = FileHandler::ReadFromFile("F:/Programming/c++ projects/Wallet-System/files/requests.txt");
	for (int i = 0; i < dataList.size(); i++) {
		vector <string> dataRow = StringFunctions::split(dataList[i], '&');
		Request tmpRequest;
		tmpRequest.userName = dataRow[0];
		tmpRequest.requestId = dataRow[1];
		tmpRequest.senderNum = dataRow[2];
		tmpRequest.amount = stof(dataRow[3]);
		this->users[dataRow[0]].userRequests.push(tmpRequest);
	}

}
void System::loadAdminData() {
	vector<string> dataList = FileHandler::ReadFromFile("F:/Programming/c++ projects/Wallet-System/files/admin.txt");
	vector <string> dataRow = StringFunctions::split(dataList[0], '&');
	this->admin.userName = dataRow[0];
	this->admin.passWord = dataRow[1];
}
void System::loadTransactionsData() {
	vector<string> dataList = FileHandler::ReadFromFile("F:/Programming/c++ projects/Wallet-System/files/transactions.txt");
	for (int i = 0; i < dataList.size(); i++) {
		vector <string> dataRow = StringFunctions::split(dataList[i], '&');
		Transaction tempTr;
		Date tmpTransactionDate(dataRow[2]);
		Time tmpTransactionTime(dataRow[3]);
		tempTr.senderNum = dataRow[0];
		tempTr.recipientNum = dataRow[1];
		tempTr.transactionDate = tmpTransactionDate;
		tempTr.transactionTime = tmpTransactionTime;
		tempTr.amount = stof(dataRow[4]);
		this->transactions.push(tempTr);
	}
}