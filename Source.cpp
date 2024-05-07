#include<iostream>
#include "Time.h"
#include "System.h"
#include "FileHandler.h"
#include <unordered_map>
#include "Date.h"

using namespace std;

void main() {
	System mainWallet;
	mainWallet.loadDataFromFiles();

	cout << "Welcome .. " << endl;
	
	mainWallet.saveDataIntoFiles();
	
}