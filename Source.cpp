#include<iostream>
#include "Time.h"
#include "System.h"
#include "FileHandler.h"
#include <unordered_map>
#include "Date.h"

using namespace std;

int main() {

	System::loadDataFromFiles();
	cout << "Welcome .. " << endl;
	
	cout << System::users["mary1234"].userRequests.size() <<endl;

	System::getUserByUserName("fady1234")->requestMoney("mary1234", 24);

	cout << System::users["mary1234"].userRequests.size() << endl;

	//System::saveDataIntoFiles();
	return 0;
	
}