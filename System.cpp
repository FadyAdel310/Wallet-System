#include "System.h"
#include "CustomExceptions.h"

using namespace std;

unordered_map<string, User> System::users;
queue <Transaction> System::transactions;
Admin System::admin;

//F11
User* System::getUserByUserName(string userName) {
	if (System::users[userName].userName == "") {
		throw userNotFound();
	}
	else {
		return &System::users[userName];
	}
}


//F22
void System::makeTransaction(Transaction newTransaction) {
	System::transactions.push(newTransaction);
}

//F23
string System::generateRequestId(string userName) {
	User* specificUser = System::getUserByUserName(userName);
	if (specificUser->userRequests.size() == 0) {
		return "1";
	}
	else {
		int newNumber = stoi(specificUser->userRequests.back().requestId) + 1;
		return to_string(newNumber);
	}
}

// ====================Files=============
void System::loadDataFromFiles() {
	loadUsersData();
	loadRequestsData();
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
		users.insert(make_pair(dataRow[0], tempUser));
	}
}
void System::loadRequestsData() {
	vector<string> dataList = FileHandler::ReadFromFile("F:/Programming/c++ projects/Wallet-System/files/requests.txt");
	for (int i = 0; i < dataList.size(); i++) {
		vector <string> dataRow = StringFunctions::split(dataList[i], '&');
		Request tmpRequest;
		tmpRequest.userName = dataRow[0];
		tmpRequest.requestId = dataRow[1];
		tmpRequest.senderNum = dataRow[2];
		tmpRequest.amount = stof(dataRow[3]);
		System::users[dataRow[0]].userRequests.push(tmpRequest);
	}

}
void System::loadAdminData() {
	vector<string> dataList = FileHandler::ReadFromFile("F:/Programming/c++ projects/Wallet-System/files/admin.txt");
	vector <string> dataRow = StringFunctions::split(dataList[0], '&');
	System::admin.userName = dataRow[0];
	System::admin.passWord = dataRow[1];
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
		System::transactions.push(tempTr);
	}
}

void System::saveDataIntoFiles() {
	saveUsersData();
	saveRequestsData();
	saveAdminData();
	saveTransactionsData();
}
void System::saveUsersData() {
	
	string* dataList = new string[System::users.size()];
	unordered_map<string, User>::iterator it;
	int i = 0;
	for (it = System::users.begin();it != System::users.end();it++) {
		dataList[i] = it->second.toString();
		i++;
	}
	FileHandler::WriteInFile("F:/Programming/c++ projects/Wallet-System/files/users.txt", System::users.size(), dataList);

}
void System::saveRequestsData() {
	int requestsSize = 0;
	for (auto it = System::users.begin();it != System::users.end();it++) {
		requestsSize += it->second.userRequests.size();
	}
	string* dataList = new string[requestsSize];
	int c = 0;
	for (auto it = System::users.begin();it != System::users.end();it++) {
		while(!it->second.userRequests.empty()) {
			dataList[c] = it->second.userRequests.front().toString();
			it->second.userRequests.pop();
			c++;
		}
	}
	FileHandler::WriteInFile("F:/Programming/c++ projects/Wallet-System/files/requests.txt", requestsSize, dataList);
}
void System::saveAdminData() {
	string* dataList = new string[1];
	dataList[0] = System::admin.toString();
	FileHandler::WriteInFile("F:/Programming/c++ projects/Wallet-System/files/admin.txt", 1, dataList);
}
void System::saveTransactionsData() {
	string* dataList = new string[System::transactions.size()];
	int i = 0;
	while (!System::transactions.empty()) {
		dataList[i] = System::transactions.front().toString();
		System::transactions.pop();
		i++;
	}

	FileHandler::WriteInFile("F:/Programming/c++ projects/Wallet-System/files/transactions.txt", i, dataList);
}