#pragma once


using namespace std;
#include "StorageHelper.h"
#include "DoubleLinkedList.h"

#include <sstream>
#include <iomanip>
class Account 
{
	
public:
	Account();
	StorageHelper Helper;
	DoubleLinkedList list;
	void setBalance(double bal);
	
	double getBalance();
	
	void AddAccountHistory(double cash, double stockValue);

	void ShowAccountHistory();

private:
	double balance;
};

