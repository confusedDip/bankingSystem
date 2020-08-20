#pragma once
class Account {
private:
	char* acc_holder;
	char* acc_num;
	char* acc_type;
	double balance;
public:
	Account(char*, char*, char*, double);
	//~Account();
	bool deposit(double);
	bool withdraw(double);
	char* enquiryHolder();
	char* enquiryAccNum();
	char* enquiryAccType();
	double enquiryBal();
};