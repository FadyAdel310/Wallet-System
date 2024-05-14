#include<iostream>
#include "Time.h"
#include "System.h"
#include "FileHandler.h"
#include <unordered_map>
#include "Date.h"

using namespace std;

// ================= helper Functions :

void displayQueue(queue<string> q) {
	while (!q.empty())
	{
		cout << q.front() << endl;
		q.pop();
	}
}

// ================= helper Functions :


// ================= main sub Functions :
// F24
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
	catch (weakPassword ex) {
		cout << "This Password Is Weak .. Password Length Must Be 4 Or More" << endl;
		cout << "[1] Try Again \n[2] Exit\n";
		string choice;cin >> choice;
		if (choice != "2")
			registerUser();
		else
			return;
	}
}

// F25
void displayAllUsersForAdminRole() {
	try {
		cout << "\nUserName\tPassword\tAmount\tStatus\n";
		cout << "--------------------------\n";
		for (int i = 0; i < System::admin.viewUsers().size(); i++) {
			cout << System::admin.viewUsers().at(i) << endl;
		}
		cout << "--------------------------\n";
	}
	catch (emptyData ex) {
		cout << "There Is No Users In System .." << endl;
	}
}

// F26
void userFunctionsForAdminRole(User * specificUser) {
	cout << "\n--------------------------\n";
	cout << specificUser->display() << endl;
	cout << "--------------------------\n";
	cout << "\n[1] Deposit\n[2] Withdraw\n[3] View his/him Transactions\n[4] Edit his/him Password";
	cout << "\n[5] Suspend This User\n[6] Activate This User\n[7] Delete This Account\n[8] Back to menu ..\n\n";
	cout << "Enter Your Choice .. : ";
	string choice;
	cin >> choice;
	if (choice == "1") {
		try {
			cout << "Enter Amount To Deposit : ";
			float amount;
			cin >> amount;
			System::admin.depositBalance(specificUser->userName, amount);
			cout << "\nThis User Have Deposited Successfully .. \n\n";
		}
		catch (nonNegativityNum ex) {
			cout << "Amount Can NOT Be Negative Or Zero ..\n";
		}
	}
	else if (choice == "2") {
		try {
			cout << "Enter Amount To Withdraw : ";
			float amount;
			cin >> amount;
			System::admin.withdrawBalance(specificUser->userName, amount);
			cout << "\nThis User Have Withdrawed Successfully .. \n\n";

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
		cout << "\nEnter New Password For This User : ";
		string password;
		cin >> password;
		try
		{
			specificUser->editPassword(password);
			cout << "\n\nYour Password Have Been Changed Successfully .. \n\n";
		}
		catch (weakPassword ex)
		{
			cout << "\n\n This Password Is Weak .. Password Length Must Be 4 Or More \n\n";
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
void userDashboard(User *currentUser) {
	cout << "\n******* User Dashboard *******\n" << endl;
	cout << "--------------------------\n";
	cout << "UserName\tPassword\tAmount\tStatus\n";
	cout << "--------------------------\n";
	cout << currentUser->display() << endl;;
	cout << "--------------------------\n\n";
	cout << "[1] Send Money To User\n[2] Request Money From User\n[3] Show My Transactions\n";
	cout << "[4] Show My Requests From Others\n[5] Delete Request From My List\n[6] Edit My Password\n[7] Log out\n\n";
	cout << "Enter Your Choice : >> ";
	string choice;cin >> choice;
	if (choice == "1") {
		string userName;
		float amount;
		cout << "\n\nEnter Username For Receipent : ";
		cin >> userName;
		cout << "\n\nEnter Amount To Send : ";
		cin >> amount;
		try {
			currentUser->sendMoney(userName, amount);
			cout << "\n\nMoney Have Been Sent Successfully To " + userName + "\n\n";
		}
		catch (userNotFound ex) {
			cout << "\n\nThis Username Is Not Exist In System ..\n\n";
		}
		catch (nonNegativityNum ex) {
			cout << "\n\nAmount Can Not Be Negative Or Zero ..\n\n";
		}
		catch (insufficientBalance ex) {
			cout << "\n\nInsufficient Balance .. Amount Are Greater Than Your Balance ..\n\n";
		}
		catch (userSuspention ex) {
			cout << "\n\nUser Who Is Suspended Can Not Send Or Receive Money ..\n\n";
		}
	}
	else if (choice == "2") {
		string userName;
		float amount;
		cout << "\n\nEnter Username For Request From : ";
		cin >> userName;
		cout << "\n\nEnter Amount To Send : ";
		cin >> amount;
		try {
			currentUser->requestMoney(userName, amount);
			cout << "\n\nMoney Have Been Requested Successfully from " + userName + "\n\n";
		}
		catch (userNotFound ex) {
			cout << "\n\nThis Username Is Not Exist In System ..\n\n";
		}
		catch (nonNegativityNum ex) {
			cout << "\n\nAmount Can Not Be Negative Or Zero ..\n\n";
		}
		catch (userSuspention ex) {
			cout << "\n\nUser Who Is Suspended Can Not Send Or Receive Money ..\n\n";
		}
	}
	else if (choice == "3") {
		try {
			if (System::admin.viewUserTransactions(currentUser->userName).size() == 0) {
				cout << "\nThere Is No Transactions For This User ..\n";
			}
			else {
				cout << "\nSender\tReceipent\tAmount\tDate\tTime\n";
				cout << "--------------------------\n";
				displayQueue(System::admin.viewUserTransactions(currentUser->userName));
			}
		}
		catch (emptyData ex) {
			cout << "\nThere Is No Transactoins In System ..\n\n";
		}
	}
	else if (choice == "4") {
		cout << "\n\n Id\tSender\tamount\n";
		cout << "--------------------------------\n";
		try {
			displayQueue(currentUser->viewRequests());
		}
		catch (emptyData ex) {
			cout << "\n\nThere Is No Requests For Your Up To Now ..\n\n";
		}
	}
	else if (choice == "5") {
		if(currentUser->userRequests.size()==0)
			cout << "\n\nThere Is No Requests For Your Up To Now ..\n\n";
		else {
			cout << "\n\n Id\tSender\tamount\n";
			cout << "\n--------------------------------\n";
				displayQueue(currentUser->viewRequests());
			cout << "\n--------------------------------\n";
			cout << "\nEnter Request ID For Delete : ";
			string id;
			cin >> id;
			try {
				currentUser->deleteRequest(id);
			}
			catch (requestIdNotFound ex) {
				cout << "\n\nRequest Id You Entered Not Found .. \n\n";
			}
		}
	}

	else if (choice == "6") {
		cout << "\nEnter New Password For You : ";
		string newPassword;
		cin >> newPassword;
		try
		{
			currentUser->editPassword(newPassword);
			cout << "\n\nYour Password Have Been Changed Successfully .. \n\n";
		}
		catch (weakPassword ex)
		{
			cout << "\n\n This Password Is Weak .. Password Length Must Be 4 Or More \n\n";
		}
	}
	else if (choice=="7")
	{
		return;
	}
	userDashboard(currentUser);
}

int main() {
	string choice;
	do {
		System::loadDataFromFiles();
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
					userDashboard(currentUser);
				}
				catch (userNotFound ex)
				{
					cout << "\nIncorrect Username Or Password To Login ..\n" << endl;
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