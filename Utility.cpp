#pragma warning(disable : 4996)

#include<iostream>
#include<stdlib.h>
#include<limits>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include "Utitlity.h"

using namespace std;


void Accounts::add_account() {
	system("CLS");
	cout << "==========New Account Form=======================" << endl << endl;
	char FName[25], LName[25], name[50], type[50], num[50];
	double balance;

	cout << "      Enter Account Number: ";
	cin >> num;
	
	cout << "      Enter Name of the Account Holder: "<<endl;
	cout << "      \t=>First Name: ";
	cin >> FName;
	cout << "      \t=>Last Name: ";
	//cin.getline(Lname, 50);
	cin >> LName;
	strcat(FName, " ");
	strcat(FName, LName);
	strcpy(name, FName);

	cout << "      Enter Account Type(S/C): ";
	cin >> type;

	cout << "      Enter Opening Balance"<<endl;
	cout << "      \tSavings: Rs. 1000.00" << endl;
	cout << "      \tCurrent: Rs. 500.00\n\t      ";
	cin >> balance;


	// Checking if Account Number already exists
	for (int i = 0; i < accounts.size(); i++) {
		if (strcmp(accounts[i].enquiryAccNum(), num) == 0) {
			cout << "      \t Sorry, Account already exists. Try with different Account Number." << endl;
			Sleep(1500);
			add_account();
		}
	}
	
	// Account Type Validation
	if (strcmp(type, "S") != 0 && strcmp(type, "C") != 0)
	{
		cout << "      \tInvalid Account Type. Try Again." << endl;
		Sleep(1500);
		add_account();
	}

	// Minimum Opening Balance Validation
	if (strcmp(type, "S") == 0 && balance < 1000.00) {
		cout << "      \tDeposit Minimum Rs. 1000.00 for opening a Savings Account. Try Again." << endl;
		Sleep(1500);
		add_account();
	}
	if (strcmp(type, "C") == 0 && balance < 500.00) {
		cout << "      \tDeposit Minimum Rs. 500.00 for opening a Current Account. Try Again." << endl;
		Sleep(1500);
		add_account();
	}


	// Adding New Account to the DataBase
	Account newUser(name, num, type, balance);
	accounts.push_back(newUser);
	cout << endl;
	cout << "      \t New User Successfully Added" << endl;
	cout << endl << "=================================================" << endl << endl;
	
	Sleep(500);
	cout << "Redirecting to the Main Menu . . ." << endl;
	Sleep(2000);

}

void Accounts::deposit_money() {
	if (accounts.size() == 0) {
		cout << "  Sorry, We don't have any account yet." << endl;
		Sleep(1000);
		return;
	}
	char num[50];
	double amount;
	
	system("CLS");
	cout << "=========Money Deposit Form=======================" << endl << endl;

	cout << "      Enter Account Number: ";
	cin >> num;

	// Checking if Account Number  exists
	for (int i = 0; i < accounts.size(); i++) {
		if (strcmp(accounts[i].enquiryAccNum(), num) == 0) {
			enquiry(num);
			cout << "      \n      Enter Amount to Deposit: ";
			cin >> amount;
			accounts[i].deposit(amount);
			cout << "Successfully Deposited Rs. " << amount<<" in Account Number "<<num<<endl;
			cout << endl << "=================================================" << endl;
			Sleep(500);
			cout << "Redirecting to the Main Menu . . ." << endl;
			Sleep(2000); 
			return;
		}
	}

	// If wrong account number is given
	cout << "      Account Not Found. Check Account Number again." << endl;
	Sleep(1500);
	deposit_money();
}

void Accounts::enquiry(char* num) {
	if (num[0] == '\0')
		return;
	
	// Checking if Account Number  exists
	for (int i = 0; i < accounts.size(); i++) {
		if (strcmp(accounts[i].enquiryAccNum(), num) == 0) {
			cout << endl << "=================================================" << endl;
			cout << endl;
			cout << "      Account Number:        " << accounts[i].enquiryAccNum()<<endl;
			cout << "      Account Holder Name:   " << accounts[i].enquiryHolder()<<endl;
			cout << "      Account Type:          " << accounts[i].enquiryAccType() << endl;
			cout << "      Account Balance:       " << accounts[i].enquiryBal() << endl;
			cout << endl << "=================================================" << endl;
			return;
		}
	}

	// If wrong account number is given
	cout << "      Account Not Found. Check Account Number again." << endl;
	Sleep(1500);
	enquiry(num);
}

void Accounts::withdraw_money() {
	if (accounts.size() == 0) {
		cout << "  Sorry, We don't have any account yet." << endl;
		Sleep(1000);
		return;
	}
	char num[50];
	double amount;

	system("CLS");
	cout << "==========Money Withdraw Form=======================" << endl << endl;

	cout << "      Enter Account Number: ";
	cin >> num;

	// Checking if Account Number  exists
	for (int i = 0; i < accounts.size(); i++) {
		if (strcmp(accounts[i].enquiryAccNum(), num) == 0) {
			enquiry(num);
			cout << "\n      Enter Amount to Withdraw: ";
			cin >> amount;
			
			if (accounts[i].withdraw(amount)) {
				cout << "Successfully Withdrawn Rs. " << amount << " from Account Number " << num << endl;
				cout << endl << "=================================================" << endl;
			}
			else {
				cout << "      Failed. Insufficient Balance." << endl;
				cout << endl << "=================================================" << endl;
			}
			Sleep(500);
			cout << "Redirecting to the Main Menu . . ." << endl;
			Sleep(2000); 
			return;
		}
	}

	// If wrong account number is given
	cout << "      Account Not Found. Check Account Number again." << endl;
	Sleep(1500);
	withdraw_money();

}

void Accounts::display() {
	system("CLS");
	cout << "\t    ACCOUNT HOLDERS LIST" << endl;
	for (int i = 0; i < accounts.size(); i++) {
		enquiry(accounts[i].enquiryAccNum());
	}
	cout << endl;
	Sleep(500);
	char x;
	cout << "Press Any key followed by an enter to go to the Main Menu: " << endl;
	cin >> x;
}

void Accounts::modify_account() {
	if (accounts.size() == 0) {
		cout << "  Sorry, We don't have any account yet." << endl;
		Sleep(1000);
		return;
	}
	char FName[25], LName[25], name[50], type[50], num[50];

	system("CLS");
	cout << "==========Account Modification Form=======================" << endl << endl;

	cout << "      Enter Account Number: ";
	cin >> num;

	// Checking if Account Number  exists
	for (int i = 0; i < accounts.size(); i++) {
		if (strcmp(accounts[i].enquiryAccNum(), num) == 0) {
			enquiry(num);
			cout << "Please enter the old one if you don't want to edit a field" << endl;
			cout << endl;
			cout << "      Enter Name of the Account Holder: " << endl;
			cout << "      \t=>First Name: ";
			cin >> FName;
			cout << "      \t=>Last Name: ";
			cin >> LName;

			strcat(FName, " ");
			strcat(FName, LName);
			strcpy(name, FName);
			accounts[i].setName(name);

			cout << "      Enter Account Type(S/C): ";
			cin >> type;

			accounts[i].setType(type);
			
			cout << "Successfully Modified Account Number " << num << endl;
			cout << endl << "=================================================" << endl;
			
			Sleep(500);
			cout << "Redirecting to the Main Menu . . ." << endl;
			Sleep(2000);
			return;
		}
	}

	// If wrong account number is given
	cout << "      Account Not Found. Check Account Number again." << endl;
	Sleep(1500);
	modify_account();
}

void Accounts::checkBalance() {
	if (accounts.size() == 0) {
		cout << "  Sorry, We don't have any account yet." << endl;
		Sleep(1000);
		return;
	}
	char num[50];

	system("CLS");
	cout << "==========Account Modification Form=======================" << endl << endl;

	cout << "      Enter Account Number: ";
	cin >> num;

	// Checking if Account Number  exists
	for (int i = 0; i < accounts.size(); i++) {
		if (strcmp(accounts[i].enquiryAccNum(), num) == 0) {
			enquiry(num);
			Sleep(500);
			char x;
			cout << "Press Any key followed by an enter to go to the Main Menu: " << endl;
			cin >> x;
			return;
		}
	}

	// If wrong account number is given
	cout << "      Account Not Found. Check Account Number again." << endl;
	Sleep(1500);
	checkBalance();
}

void Accounts::close_account() {
	if (accounts.size() == 0) {
		cout << "  Sorry, We don't have any account yet." << endl;
		Sleep(1000);
		return;
	}
	char num[50];

	system("CLS");
	cout << "==========Account Closing Form=======================" << endl << endl;

	cout << "      Enter Account Number: ";
	cin >> num;

	// Checking if Account Number  exists
	for (int i = 0; i < accounts.size(); i++) {
		if (strcmp(accounts[i].enquiryAccNum(), num) == 0) {
			enquiry(num);
			cout << "Are you sure you want to close this account?" << endl;
			cout << "\tYes(Y)  No(N)" << endl<<"\t";
			char c;
			cin >> c;
			if (c == 'Y' || c == 'y') {
				accounts[i].setNum();
				cout << "Successfully Closed Account Number " << num << endl;
				cout << endl << "=================================================" << endl;
			}
			else {
				cout << "Thank you for not leaving us"<< endl;
				cout << endl << "=================================================" << endl;
			}
			Sleep(500);
			cout << "Redirecting to the Main Menu . . ." << endl;
			Sleep(2000);
			return;
		}
	}

	// If wrong account number is given
	cout << "      Account Not Found. Check Account Number again." << endl;
	Sleep(1500);
	close_account();
}
