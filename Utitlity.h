#pragma once
#include<vector>
#include "Account.h"

using namespace std;

class Accounts {
private:
	vector<Account> accounts;
public:
	void add_account();
	void deposit_money();
	void withdraw_money();
	void enquiry(char*);
	void display();
	//void close_account();
	//void modify_account();
};