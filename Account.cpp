#pragma warning(disable : 4996)

#include<iostream>
#include<sstream>
#include<string.h>
#include "Account.h"
using namespace std;

Account::Account(char* holder, char* number, char* accType, double amount){
	
	this->acc_holder = new char[strlen(holder) + 1];
	strcpy(this->acc_holder, holder);

	this->acc_type = new char[strlen(accType) + 1];
	strcpy(this->acc_type, accType);

	this->acc_num = new char[strlen(number) + 1];
	strcpy(this->acc_num, number);

	this->balance = amount;

}


bool Account::deposit(double amount) {
	if (amount > 10000.00 || amount < 0)
		return false;
	this->balance += amount;
	return true;
}

bool Account::withdraw(double amount) {
	if (this->balance - amount < 0)
		return false;
	this->balance -= amount;
	return true;
}

char* Account::enquiryHolder() {
	return this->acc_holder;
}
char* Account::enquiryAccNum() {
	return this->acc_num;
}
char* Account::enquiryAccType() {
	return this->acc_type;
}
double Account::enquiryBal() {
	return this->balance;
}

void Account::setName(char* new_name) {
	delete[] this->acc_holder;
	this->acc_holder = new char[strlen(new_name) + 1];
	strcpy(this->acc_holder, new_name);
}

void Account::setType(char* new_name) {
	delete[] this->acc_type;
	this->acc_type = new char[strlen(new_name) + 1];
	strcpy(this->acc_type, new_name);
}

void Account::setNum() {
	delete[] this->acc_num;
	this->acc_num = new char[1];
	this->acc_num[0] = '\0';
}