
using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include "StockAccount.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <iomanip>
#include "DoubleLinkedList.h"
#include "StorageHelper.h"
#include "Node.h"


void StockAccount::refreshList(DoubleLinkedList * list)
{
	int count = 0;
	Node *temp = list->getBegin();
	



	while ((temp=temp->next)!=list->getEnd())
	{
		//temp->setStockPrice(getStockPrice(temp->stockName));
		//temp->setStockPrice(listHelper.getStockPrice(temp->stockName));
		//test.getStockPrice(temp->stockName);
		//temp->setStockPrice(list.getStockPrice(temp->stockName));
		//abandon

		temp->setStockPrice(getStockPrice(temp->stockName));
		



	}


}

double StockAccount::test()
{
	cout<<Helper.getLastLine("Result_1.txt");
	return 1;
}

void StockAccount::changeSortType()
{
	cout << "which type of sort method do you want to use?" << endl
		<< "1,select sort   2,bubble ,please input the number" << endl;
	cin >> sortMethod;
	if ((sortMethod != 1) && (sortMethod != 2))
	{
		cout << "munber not match" << endl;
		sortMethod = 1;
	}

	

}

void StockAccount::bubbleSort()
{
	list.getsize();
	Node * temp = list.getBegin()->next;

	while (temp != list.getEnd())
	{
		temp->setStockPrice(Helper.getStockPrice(temp->stockName));
		temp = temp->next;
	}

	for (int i = 1; i < list.getsize(); i++)
	{
		for (int j = i; j <= list.getsize(); j++)
		{
			Node * stock1 = list.find_node_pos(i);
			Node * stock2 = list.find_node_pos(j);
			double stock_1 = stock1->numOfShares *stock1->stockPrice;
			double stock_2 = stock2->numOfShares *stock2->stockPrice;
			if (stock_1 < stock_2)
			{
				list.swap(i, j);
			}

		}
	}

}

void StockAccount::SelectSort()
{


	list.getsize();
	Node * temp = list.getBegin()->next;

	refreshList(&list);
	/*
		while (temp != list.getEnd())
		{
			temp->setStockPrice(Helper.getStockPrice(temp->stockName));
			temp = temp->next;
		}
*/
		for (int i = 1; i <= list.getsize()-1; i++)
		{
			int min = i;
			for (int j = i + 1; j <= list.getsize(); j++)
			{
				Node * stock1 = list.find_node_pos(min);
				Node * stock2 = list.find_node_pos(j);
				double stock_1 = stock1->numOfShares *stock1->stockPrice;
				double stock_2 = stock2->numOfShares *stock2->stockPrice;
				if (stock_1 < stock_2)
				{
					min = j;
				}

			}
			list.swap(i, min);
		}


	
}

void StockAccount::displayAstock(string name)//option 1
{
	//find if the stock exit
	string stock = Helper.getWordInLine(Helper.quickSearch("Result_1.txt", name),1);
	if (stock == "fail")
	{
		cout <<" can not find this stock "<< endl;
		return;
	}
	else
	{
		double price = getStockPrice(name);
		if (price == -1)
		{
			cout << "price search fail" << endl;
			return;
		}
		cout << name << "  $" << price << endl << endl;
	}
	return;

}

void  StockAccount::showOwnedStocks()//option 2
{

	refreshList(&list);

	//todo sort the list
	if (sortMethod == 1)
	{
		SelectSort();
	}
	else
		{
		bubbleSort();
		}
	double total = 0.0;

	cout << "Cash balance = $" << getBalance() << endl;
	//cout << "Company-Symbol Number Price-per-share  Total value"<<endl;
	total=list.printList();
	
	total = total + getBalance();
	cout << endl<<"total portfolio: $"<<total<<endl;

}

void  StockAccount::buyShare()//option 3
{
	int Shares = 0;
	string stockSymbol;
	double stockPrice = 0.0;
	double buyprice = 0.0;
	cout << "Please enter the stock symbol you wish to purchase:" << endl;
	cin >> stockSymbol;
	cout << "Please enter the number of shares:" << endl;
	cin >> Shares;
	cout << "Please enter the maximum amount you are willing to pay per share:  " << endl;
	cin >> buyprice;
	

	if ((stockPrice = getStockPrice(stockSymbol)) == -1)
	{
		cout << "can not find the price, fail" << endl;

	}else if(stockPrice>buyprice)
	{
		cout << "stock price is higher than the price you want to make a deal,fail" << endl;
		return;
	}
	else 
	{
		if (stockPrice*Shares > getBalance())
		{
			cout << "not enough balance for transaction"<<endl;
			return;
		}
		else
		{
			//add stock to list
			//check if the stock already exist
			if (list.find_node(stockSymbol) != nullptr)
			{//node exist
				Node* temp = list.find_node(stockSymbol);
				temp->setNumberOfShares(temp->getNumberOfShares() + Shares);
				temp->setStockPrice(stockPrice);
				
				cout << "new stock purchased" << endl;
			}
			else
			{//node not exist
				Node* temp = new Node;
				temp->stockName = stockSymbol;
				temp->setStockPrice(stockPrice);
				temp->setNumberOfShares(Shares);
				list.insert_node(temp);
				list.num++;
				cout << "new stock purchased" << endl;
			}
			setBalance((getBalance() - stockPrice * Shares)*1.0);
			addStockHistory(2, stockSymbol, stockPrice, Shares);
			addBankHistory(3, stockPrice*Shares * 1);

			//change balance
			//add history to stock history
			//add history to bank history

			//update stockValue?
		}
	}
	

}

void  StockAccount::sellShare()//option 4
{
	double sellPrice = 0.0;
	double stockPrice = 0.0;
	int Shares = 0;
	string stockSymbol="";
	cout << "Please enter the stock symbol you wish to sell:"<<endl;
	
	cin >> stockSymbol;
	cout << "Please enter the number of shares:" << endl;
	cin >> Shares;
	cout << "Please enter the  amount you are willing to sell per share:  " << endl;
	cin >> sellPrice;
	//get name and price and shares
	//compare stocks list,and the amount
	//compare the price
	//make a transaction
	//change balance
			//add history to stock history
			//add history to bank history

	if (list.find_node(stockSymbol) != nullptr)
	{
		if (list.find_node(stockSymbol)->getNumberOfShares() < Shares)
		{
			cout << "not engouh stock,fail" << endl;
		}
		else
		{
			if ((stockPrice = getStockPrice(stockSymbol)) < sellPrice)
			{
				cout << "the price you want to sell is too high,fail" << endl;
				return;
			}
			if (list.find_node(stockSymbol)->getNumberOfShares() == Shares)
			{
				Node* temp = list.find_node(stockSymbol);
				temp->setNumberOfShares(temp->getNumberOfShares() - Shares);
				temp->setStockPrice(stockPrice);
				setBalance((getBalance() + stockPrice * Shares)*1.0);
				list.delete_node(temp);
				list.num--;
				addStockHistory(1, stockSymbol, stockPrice, Shares);
				addBankHistory(3, stockPrice*Shares * 1);
				cout << "stock sold" << endl;
			}
			else
			{
				Node* temp = list.find_node(stockSymbol);
				temp->setNumberOfShares(temp->getNumberOfShares() - Shares);
				temp->setStockPrice(stockPrice);
				setBalance((getBalance() + stockPrice * Shares)*1.0);
				addStockHistory(1, stockSymbol, stockPrice, Shares);
				addBankHistory(3, stockPrice*Shares * 1);
				cout << "stock sold" << endl;



			}
		}
	}
	else
	{
		cout << "stock do not exist" << endl;
	}





}


void  StockAccount::viewHistory()//option 6
{
	cout << "Event     CompanySymbol     Number     Price per share    Total value    Time" << endl;
	Helper.printfile("StockHistory.txt");
}

double  StockAccount::getStockPrice(string name)//get price for a stock, for option 1 2 3 4,random fun works here,return -1 if fail to get price
{
	ifstream outFile1("Result_1.txt");
	ifstream outFile2("Result_2.txt");

	//random select from file1 and file2

	if (outFile1)
	{
		srand((unsigned)time(NULL));


		string a, b, c;

		int jump = 1 + rand() % 10;
		if (jump > 5)
		{
			string temp = Helper.quickSearch("Result_1.txt", name);
			if (temp == "fail")
			{
				return -1;
			}
			istringstream sin1(temp);

			sin1 >> a >> b >> c;

			return atof(b.c_str());

		}
		else
		{
			string temp = Helper.quickSearch("Result_2.txt", name);
			if (temp == "fail")
			{
				return -1;
			}
			istringstream sin1(temp);

			sin1 >> a >> b >> c;

			return atof(b.c_str());
		}


	}

	outFile1.close();
	outFile2.close();
	return -1;
}

double  StockAccount::getStockValue()//get total price,  for option 2
{
	double total = 0.0;
	Node * temp = list.getBegin();
	temp = temp->next;
	while (temp != list.getEnd())
	{
		total = temp->getNumberOfShares()*getStockPrice(temp->stockName)*1.0+total;
		temp = temp->next;
	}

	return total;
}



void  StockAccount::addStockHistory(int mode, string name, double price,double shares)
//add an transaction,for option 3 4
{
	string modestr="";
	string temp = "";
	if (mode == 1)
	{
		modestr = "Sell";
	}
	if (mode == 2)
	{
		modestr = "Buy";
	}

	stringstream out;
	out << left << setw(16) << modestr << setw(16) << name << 
		setw(16) << Helper.toString(shares) << setw(16) << "$" + Helper.toString(price) << setw(16) << Helper.toString(price * shares,2) <<
		setw(16) << Helper.getTimeandDate() << endl;
	temp = out.str();
	Helper.addToLastLine("StockHistory.txt", temp);

}

void  StockAccount::loadStocks()//get preious data from stock.txt
{
	list.num = 0;

	ifstream outFile1("CurrentPortfolio.txt");

	if (outFile1)
	{
		string line = "";
		while (getline(outFile1, line))
		{
			Node *temp = new Node;
			temp->stockName = Helper.getWordInLine(line, 1);
			temp->setNumberOfShares(stoi(Helper.getWordInLine(line, 3)));
			temp->setStockPrice(getStockPrice(temp->stockName));
			list.insert_node(temp);
			list.num++;
			 
		}
	}
	
	
	
	list.getsize();
	refreshList(&list);
	
	/*
	todo sort list
	if (sortMethod == 1)
	{
		SelectSort();
	}
	else
	{
		bubbleSort();
	}
	*/

}
void  StockAccount::saveStocks()//save current stock for next time
{
	Helper.clearFile("CurrentPortfolio.txt");
	//refresh price in the list
	refreshList(&list);
	//refresh total value
	
	Node* currentPtr = list.getBegin()->getNext();
	while (currentPtr != list.getEnd()) 
	{
		if (currentPtr == list.getBegin()->next)
		{
			string temp = "";
			//stringstream out;
			//out  << currentPtr->stockName << "\t""\t" << Helper.toString(currentPtr->getNumberOfShares());
			//temp = out.str();
			 temp= currentPtr->stockName + "\t\t" + Helper.toString(currentPtr->getNumberOfShares());
			Helper.addToLastLine("CurrentPortfolio.txt", temp);
		}
		else
		{
			string temp = "";
			//stringstream out;
			//out  << currentPtr->stockName << "\t""\t" << Helper.toString(currentPtr->getNumberOfShares());
			//temp = out.str();
			temp = "\n"+currentPtr->stockName + "\t\t" + Helper.toString(currentPtr->getNumberOfShares());
			Helper.addToLastLine("CurrentPortfolio.txt", temp);
		}

		

	
		//Helper.addToLastLine("CurrentPortfolio.txt", stock);

		currentPtr = currentPtr->getNext();

	}
	//write in file
}
void  StockAccount::setPortfolioVal()//just set the portfolio value ,for option 3 4 2 
{

}
void  StockAccount::getPortfolioValfromFile()//for option 5
{

}

void StockAccount::addBankHistory(int mode, double amount)
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
	out << left << endl << setw(16) << modestr << setw(16) << "$" + Helper.toString(amount, 2) <<
		setw(16) << Helper.getTimeandDate() << setw(16) << "$" + Helper.toString(getBalance()) << endl;
	temp = out.str();
	Helper.addToLastLine("BankHistory.txt", temp);

}