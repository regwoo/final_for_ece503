

using namespace std;
#include <iostream>
#include <string>
#include "BankAccount.h"
#include <iomanip>
#include <sstream>

void BankAccount::viewAccountBalance()
{
	//account.getBalance()
	cout << getBalance()<<endl;
}
void BankAccount:: deposit(double input)
{
	//getbalance()+   then setbalance,addbankhistory()
	setBalance((getBalance() + input)*1.0);
	addBankHistory(1, input);
	
}
void BankAccount :: withDraw(double output)
{
	//getBalance(),judge
	if (getBalance() < output)
	{
		cout << "not enough balance,transaction fali" << endl;
	}
	else
	{
		setBalance((getBalance() - output)*1.0);
		addBankHistory(2, output);
	}
	//if ok,setbalance()  addbankhistory() 
}
void BankAccount :: printHistory()
{
	//loadbankhistory()
	cout << left << endl << setw(16) << "event" << setw(16) 
		<< "Amount" << setw(16) << "Date" << setw(16) 
		<< "Balance" << endl;
	Helper.printfile("BankHistory.txt");
}

void BankAccount::addBankHistory(int mode, int amount)
{
	//mode 1 deposit mode2 withdraw mode3 but stock mode 4 sell stock
	//		Event    Amount   Date   Balance 


	string modestr = "";
	string temp = "";
	if (mode == 1)
	{
		modestr = "Deposit";
	}
	if (mode == 2)
	{
		modestr = "Withdrawal";
		
	}
	if (mode == 3)
	{
		modestr = "Buy Stock";
		
	}
	if (mode == 4)
	{
		modestr = "Sell Stock";
	}

	stringstream out;
	out << left << setw(16) << modestr << setw(16) << "$" + Helper.toString(amount, 2) <<
		setw(16) << Helper.getTimeandDate() << setw(16) << "$" + Helper.toString(getBalance())<<endl;
	temp = out.str();
	Helper.addToLastLine("BankHistory.txt", temp);

}