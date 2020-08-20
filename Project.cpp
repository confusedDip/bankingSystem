#include <iostream>
#include<stdlib.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include "Account.h"
#include "Utitlity.h"
using namespace std;

void showMenu() {
	system("CLS");
	cout << "  MAIN MENU" << endl;
	cout << endl;
	cout << "  01. NEW ACCOUNT" << endl;
	cout << "  02. DEPOSIT MONEY" << endl;
	cout << "  03. WITHDRAW MONEY" << endl;
	cout << "  04. BALANCE ENQUIRY" << endl;
	cout << "  05. ALL ACCOUNT HOLDER LIST" << endl;
	cout << "  06. CLOSE AN ACCOUNT" << endl;
	cout << "  07. MODIFY AN ACCOUNT" << endl;
	cout << "  08. EXIT" << endl;
	cout << endl;
	cout << "  Select Your Option <1-8> ";
}

int main()
{
	Accounts Souradip;

	int choice;
	while (1) {
		showMenu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			Souradip.add_account();
			break;
		case 2:
			Souradip.deposit_money();
			break;
		case 3:
			Souradip.withdraw_money();
			break;
		case 4:
			break;
		case 5:
			Souradip.display();
			break;
		case 6:
			break;
		case 7: 
			break;
		case 8:
			cout << "\n  Thank You For Banking With Us" << endl;
			Sleep(2000);
			exit(0);
		default:
			cout << "\n  Invalid Choice." << endl;
			Sleep(1000);
		}
	}
}

