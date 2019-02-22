#pragma once
//todo add two type's of sort 
using namespace std;
#include "DoubleLinkedList.h"
#include "Node.h"

class Sort
{
public:
	friend class DoubleLinkedList;
	friend class StockAccount;
	virtual void sort(DoubleLinkedList *list);
	

private:
	int sortType;
};


class BubbleSort :public Sort
{
public:
	//void sort(DoubleLinkedList * list);
};


class SelectSort :public Sort
{
public:
	//void sort(DoubleLinkedList * list);
};



