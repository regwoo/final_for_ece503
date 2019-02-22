
#include "Account.h"
#include "BankAccount.h"
#include "DoubleLinkedList.h"
#include "StockAccount.h"
#include "StorageHelper.h"
int Stock();
int Bank();
int Exit();

StockAccount SA;
BankAccount BA;
StorageHelper HP;
//User user;
int main()
{
	//get the last cash while program starts
	//USER.setBalance(HP.stringWith$Todouble(HP.getWordInLine(HP.getLastLine("Account.txt"), 1)));
	
	//teset zone
	//cout << HP.stringWith$Todouble(HP.getWordInLine(HP.getLastLine("Account.txt"), 1));
	//test zone
	int exitSign=1;
	

	SA.loadStocks();
	
	

	while (exitSign)
	{
		cout << endl << "Welcome to the Account Management System."<<endl
			<<"Please select an account to access:" << endl
			<< "1. Stock Portfolio Account " << endl
			<< "2. Bank Account " << endl
			<< "3. Exit" << endl;
		do
		{
			cin >>exitSign;
		} while ((exitSign < 1) || (exitSign > 3));

		switch (exitSign)
		{
		case 1:Stock(); break;
		case 2:Bank(); break;
		case 3:Exit(); exitSign = 0; break;
		}

	}


}

int Stock()
{
	int exitSign = 1;
		while (exitSign)
		{
			string name = "";
			double price = 0.0;
			int shares = 0;
			cout << endl << "1. Display the price for a stock symbol" << endl
				<< "2. Display the current portfolio " << endl
				<< "3. Buy shares " << endl
				<< "4. Sell shares " << endl
				<< "5. View a graph for the portfolio value " << endl
				<< "6. View transaction history " << endl
				<< "7. Return to previous menu" << endl
				<< "8.change sort method" << endl;

			do
			{
				cin >> exitSign;
			} while ((exitSign < 1) || (exitSign > 7));

			switch (exitSign)
			{
			case 1:
				
				cout << "Please enter the stock symbol:" << endl;
				cin >> name;
				cout << "Price per share of" <<name<< endl;
				if (SA.getStockPrice(name) == -1)
				{
					cout << "can not find the stock" << endl;
					break;
				}
				else
				{
					cout << name<<" ";
					cout<<SA.getStockPrice(name);
					break;
				}
			case 2:
				
				SA.showOwnedStocks();
				break;

			case 3:

				
				SA.buyShare();
				break;

			case 4:
				
				SA.sellShare();
				break;

			case 5:
				//wait for edit
				break;

			case 6:
				SA.viewHistory();
				break;

			case 7:
				exitSign = 0;
				break;
			case 8:
				SA.changeSortType();
				break;
			}

		}

		return 1;
}




int Bank()
{
	int exitSign = 1;
	while (exitSign)
	{
		double money=0.0;
		cout << endl << "1. View account balance " << endl
			<< "2. Deposit money " << endl
			<< "3. Withdraw money " << endl
			<< "4. Print out history " << endl
			<< "5. Return to previous menu" << endl;
		do
		{
			cin >> exitSign;
		} while ((exitSign < 1) || (exitSign > 5));

		switch (exitSign)
		{
		case 1:
			cout << "You have " << BA.getBalance() << " in your bank account" << endl;
			break;

		case 2:
			cout << "please input the amount you want to deposit" << endl;
			cin >> money;
			BA.deposit(money);
			break;

		case 3:
			cout << "please input the amount you want to withdraw" << endl;
			cin >> money;
			BA.withDraw(money);
			break;

		case 4:
			BA.printHistory();
			break;

		case 5:
			exitSign = 0;
			break;

		}

		
	}
	return 1;
}

int Exit()
{
	SA.saveStocks();
	BA.AddAccountHistory(BA.getBalance()*1.00, BA.getBalance()+ SA.getStockValue()*1.00);
	//save balnce and portfolio and stocks and exit

	return 1;
}