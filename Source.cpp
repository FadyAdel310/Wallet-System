#include<iostream>
#include "Time.h"
#include "System.h"
#include "FileHandler.h"
#include <unordered_map>
#include "Date.h"

using namespace std;

// ================= helper Functions :
bool isValidFloatNumber(string input) {
	bool isNumber = true;
	for (char c : input) {
		if (!isdigit(c)) {
			isNumber = false;
			break;
		}
	}
	return isNumber;
}
void displayQueue(queue<string> q) {
	while (!q.empty())
	{
		cout << q.front() << endl;
		q.pop();
	}
}
// ================= helper Functions :


// ================= main sub Functions :
void registerUser() {
	cout << "\n========== User Register Page ..==========\n" << endl;
	string userName, password;
	cout << "Enter User Name : ";
	cin >> userName;
	cout << "Enter Password  : ";
	cin >> password;
	try {
		User::registerAccount(userName, password);
		cout << "\nUser Have Been Registered Successfully ..\n";
	}
	catch (usernameUsed ex) {
		cout << "This Username Is Already Exist .." << endl;
		cout << "[1] Try Again \n[2] Exit\n";
		string choice;cin >> choice;
		if (choice != "2")
			registerUser();
		else
			return;
	}
}
void displayAllUsersForAdminRole() {
	try {
		for (int i = 0; i < System::admin.viewUsers().size(); i++) {
			if (i == 0) {
				cout << "\nUserName\tPassword\tAmount\tStatus\n";
				cout << "--------------------------\n";
			}
			cout << System::admin.viewUsers().at(i) << endl;
		}
		cout << "--------------------------\n";
	}
	catch (emptyData ex) {
		cout << "There Is No Users In System .." << endl;
	}
}
void userFunctionsForAdminRole(User * specificUser) {
	cout << "\n--------------------------\n";
	cout << specificUser->display() << endl;
	cout << "--------------------------\n";
	cout << "\n[1] Deposit\n[2] Withdraw\n[3] View his/him Transactions\n[4] Edit his/him Username";
	cout << "\n[5] Suspend This User\n[6] Activate This User\n[7] Delete This Account\n[8] Back to menu ..\n\n";
	cout << "Enter Your Choice .. : ";
	string choice;
	cin >> choice;
	if (choice == "1") {
		try {
			cout << "Enter Amount To Deposit : ";
			string amount;
			cin >> amount;
			if (isValidFloatNumber(amount)) {
				System::admin.depositBalance(specificUser->userName, stof(amount));
				cout << "\nThis User Have Deposited Successfully .. \n\n";
			}
			else
				cout << "Amount MUST Be Valid Number ..\n";
		}
		catch (nonNegativityNum ex) {
			cout << "Amount Can NOT Be Negative Or Zero ..\n";
		}
	}
	else if (choice == "2") {
		try {
			cout << "Enter Amount To Withdraw : ";
			string amount;
			cin >> amount;
			if (isValidFloatNumber(amount)) {
				System::admin.withdrawBalance(specificUser->userName, stof(amount));
				cout << "\nThis User Have Withdrawed Successfully .. \n\n";
			}
			else
				cout << "Amount MUST Be Valid Number ..\n";
		}
		catch (nonNegativityNum ex) {
			cout << "Amount Can NOT Be Negative Or Zero ..\n";
		}
		catch (insufficientBalance ex) {
			cout << "Insufficient Balance (amount are greater than from user balance) ..\n";
		}
	}
	else if (choice == "3") {
		try {
			if (System::admin.viewUserTransactions(specificUser->userName).size() == 0) {
				cout << "\nThere Is No Transactions For This User ..\n";
			}
			else {
				cout << "\nSender\tReceipent\tAmount\tDate\tTime\n";
				cout << "--------------------------\n";
				displayQueue(System::admin.viewUserTransactions(specificUser->userName));
			}
		}
		catch (emptyData ex) {
			cout << "\nThere Is No Transactoins In System ..\n\n";
		}
	}	
	else if (choice == "4") {
		cout << "\nEnter New Username For This User : ";
		string oldUserName = specificUser->userName;
		string newUserName;
		cin >> newUserName;
		try
		{
			System::admin.editUserNameForUserAccount(specificUser->userName, newUserName);
			cout << "\n" + oldUserName + " Have Been Changed To " + newUserName + " successfully ..\n\n";
		}
		catch (usernameUsed ex)
		{
			cout << "\n This Username Is Already Exist .. \n";
		}
	}	
	else if (choice == "5") {
		try
		{
			System::admin.suspendUser(specificUser->userName);
			cout << "\n" + specificUser->userName + " Have Been Suspended Successfully ..\n";
		}
		catch (userSuspention ex)
		{
			cout << "\nThis User Is Already Inactive\n";
		}
	}	
	else if (choice == "6") {
		try
		{
			System::admin.activateUser(specificUser->userName);
			cout << "\n" + specificUser->userName + " Have Been Activated Successfully ..\n";
		}
		catch (userSuspention ex)
		{
			cout << "\nThis User Is Already Active\n";
		}
	}	
	else if (choice == "7") {
		cout << "\nAre You Sure To Delete " + specificUser->userName + " From System ..? 'yes To Confirm' .. : ";
		string choice;
		cin >> choice;
		if (choice == "yes") {
			System::admin.deleteUserAccount(specificUser->userName);
			cout << "\nUser Have Been Deleted Successfully .. \n\n";
			return;
		}
		else {
			cout << "\n Deletion NOT Take Action ..\n\n";
		}
	}
	else if (choice == "8") {
		return;
	}
	userFunctionsForAdminRole(specificUser);
}
// ================= main sub Functions :



void adminDashboard() {
	cout << "\n******* Admin Dashboard *******\n" << endl;
	cout << "[1] View All Users In System\n[2] View All Transactions\n[3] Add New User\n[4] Get Specific User\n[5] Log Out\n\n==== Enter Your Choice => : ";
	string choice;cin >> choice;
	if (choice == "1") {
		displayAllUsersForAdminRole();
	}
	else if (choice == "2") {
		try
		{
			cout << "\nSender\tReceipent\tAmount\tDate\tTime\n";
			cout << "--------------------------\n";
			displayQueue(System::admin.viewAllTransactions());
		}
		catch (emptyData ex)
		{
			cout << "There Is No Transactions In System .." << endl;
		}
	}
	else if (choice == "3") {
		registerUser();
	}
	else if (choice == "4") {
		displayAllUsersForAdminRole();
		cout << "Enter Username For Get .. : ";
		string specificUserName;
		cin >> specificUserName;
		try
		{
			User* specificUser = System::getUserByUserName(specificUserName);
			userFunctionsForAdminRole(specificUser);
		}
		catch (userNotFound ex)
		{
			cout << "There Is No User With Username : " + specificUserName << endl;
		}
	}
	else if (choice == "5") {
		return;
	}
	adminDashboard();
}
void UserDashboard(User *currentUser) {
	cout << currentUser->userRequests.size() << endl;
}

int main() {
	string choice;
	do {
		System::loadDataFromFiles();
		cout << "t : " << System::users.size() << endl;
		cout << "\n[1] Admin\n[2] User\n[3] Exit\n\nEnter Your Choice .." << endl;
		cin >> choice;
		if (choice == "1") {
			cout << "\n========== Admin Login Page ..==========\n" << endl;
			string adminUserName, adminPassword;
			cout << "Admin User Name : ";
			cin >> adminUserName;
			cout << "Admin Password  : ";
			cin >> adminPassword;
			try
			{
				System::admin.login(adminUserName, adminPassword);
				adminDashboard();
			}
			catch (invalidDataToLogin ex)
			{
				cout << "\nInvalid Login To Admin Dashboard ..\n" << endl;
			}
		}
		else if (choice == "2") {
			cout << "\n========== User Page ..==========\n" << endl;
			cout << "[1] Login\n[2] Register\n\nEnter Your Choice ..\n";
			string choice;
			cin >> choice;
			if (choice == "1") {
				cout << "\n========== User Login Page ..==========\n" << endl;
				string userName, password;
				cout << "Enter User Name : ";
				cin >> userName;
				cout << "Enter Password  : ";
				cin >> password;
				try
				{
					User::login(userName, password);
					User* currentUser = System::getUserByUserName(userName);
					UserDashboard(currentUser);
				}
				catch (invalidDataToLogin ex)
				{
					cout << "\nIncorrect Username Or Password To Login ..\n" << endl;
				}
			}
			else if (choice == "2") {
				registerUser();
			}
			else {
				cout << "Invalid Input .. Try again" << endl;
			}
		}
		System::saveDataIntoFiles();

	} while (choice != "3");
	
}