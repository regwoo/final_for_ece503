#include "Node.h"


double Node::getStockPrice()
{
	return stockPrice;
}

int Node::getNumberOfShares()
{
	return numOfShares;
}

void Node::setNumberOfShares(int num)
{
	this->numOfShares = num;
}

void Node::setStockPrice(double num)
{
	this->stockPrice = num;
}

Node* Node::getNext()
{
	return next;
}