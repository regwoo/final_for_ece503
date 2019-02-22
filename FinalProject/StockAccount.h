#pragma once

using namespace std;

#include "Account.h"
//#include "Node.h"
#include "DoubleLinkedList.h"
//#include "StockAccount.h"
#include "StorageHelper.h"



class DoubleLInkedList;

class StockAccount :public Account
{
	
	
public:
	friend class  DoubleLInkedList;



	void displayAstock(string name);//option 1
	void showOwnedStocks();//option 2
	void buyShare();//option 3
	void sellShare();//option 4
	void viewGraphPortfolioValue();//option 5
	void viewHistory();//option 6




	double getStockPrice(string name);//get price for a stock, for option 1 2 3 4,random fun works here

	
	double getStockValue();//get total price,  for option 2

	void addBankHistory(int mode,double amount);
	

	void addStockHistory(int mode,string name,double price,double shares);
	//add an transaction,for option 3 4

	void loadStocks();//get preious data from stock.txt

	void saveStocks();//save current stock for next time

	void setPortfolioVal();//just set the portfolio value ,for option 3 4 2 
	void getPortfolioValfromFile();//for option 5

	void refreshList(DoubleLinkedList *list);
	double test();

	void changeSortType();

	int sortMethod=1;

	void bubbleSort();

	void SelectSort();

private:
	double portfolioVal;

};