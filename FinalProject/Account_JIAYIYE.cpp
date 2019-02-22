
#include "Account.h"
#include "DoubleLinkedList.h"
#include "StorageHelper.h"

 Account::Account()
{
	

}

void Account::setBalance(double bal)
{// Helper.stringWith$Todouble(Helper.getWordInLine(Helper.getLastLine("Account.txt"), 1));
	//get the last cash while program starts
	Helper.clearFile("Cash.txt");
	Helper.addToLastLine("Cash.txt", Helper.toString(bal));
}
double Account ::getBalance()
{
	double temp = Helper.stringWith$Todouble(Helper.getWordInLine(Helper.getLastLine("Cash.txt"), 1));
	return temp;
}
void Account ::AddAccountHistory(double cash, double stockValue)
{
	//string stock = currentPtr->stockName + "\t\t" + Helper.toString(currentPtr->getNumberOfShares());
	string temp = "";
	stringstream out;
	out << left <<endl<< setw(16) << "$" + Helper.toString(cash, 2) <<
		setw(16) << "$" + Helper.toString(stockValue, 2) << setw(16) <<
		Helper.getTimeandDate() ;
	temp = out.str();
	Helper.addToLastLine("Account.txt", temp);
}
void Account ::ShowAccountHistory()
{
	cout << left << endl <<
		setw(16) << "balance" << setw(16) << "stock value" << setw(16) << "time" << endl;
	Helper.printfile("Account.txt");
}