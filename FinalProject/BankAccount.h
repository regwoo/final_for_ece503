#pragma once

using namespace std;
#include "Account.h"

class BankAccount:public Account
{
public:
	void viewAccountBalance();//op1
	void deposit(double price);//op2
	void withDraw(double price);//op3
	void printHistory();//op4
	void addBankHistory(int mode,int amount);//op5 for op 2 3
	




};