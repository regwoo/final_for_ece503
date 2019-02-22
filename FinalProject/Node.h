#pragma once
#include <string>
#include <iostream>
using namespace std;


//Node fun finnished
class Node {
	
public:
	//overlod for two kinds of input 
	friend class StockAccount;
	Node()
	{
		this->next = NULL;
	}
	Node(string name, double price)
	{
		this->stockName = name;
		this->setStockPrice(price);
		this->next = NULL;
	}
	Node(string name, int price, int num)
	{
		this->stockName = name;
		this->stockPrice = price;
		this->numOfShares = num;
		this->next = NULL;
	}
	~Node()
	{

	}
	
	double getStockPrice();
	void setNumberOfShares(int);
	int getNumberOfShares();
	void setStockPrice(double);
	Node* getNext();
	Node * pre;
	Node * next;
	string stockName;

private:
	double stockPrice;
	int numOfShares;
	
};

