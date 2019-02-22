

using namespace std;

#include <iostream>	
#include <string>
#include "DoubleLinkedList.h"
#include "Node.h"
#include "StorageHelper.h"


 DoubleLinkedList::DoubleLinkedList()
{
	 num = 0;
	 begin = new Node("",0);
	 end = new Node("",0);
	 begin->pre = NULL;
	 begin->next = end;
	 end->next = NULL;
	 end->pre = begin;

}
 DoubleLinkedList::~DoubleLinkedList()
 {

	 Node* currentPtr = begin;
	 while (currentPtr) {
		 Node* tempPtr = currentPtr;
		 currentPtr = currentPtr->next;
		 delete tempPtr;
		 tempPtr = NULL;
	 }
 }


void DoubleLinkedList::insert_node(Node* node)
{
	//connect node to end of list
	//change pointers
	//
	node->next = end;
	node->pre = end->pre;
	end->pre->next = node;
	end->pre = node;
	num++;
	
	//finished
}
void DoubleLinkedList::delete_node(Node* node)
{
	//change pointers
	//delete the certain node

	node->pre->next = node->next;
	node->next->pre = node->pre;
	delete(node);


}

Node* DoubleLinkedList::find_node(string name)
{
	
	Node * temp = begin->next;
	
	while (temp != end)
	{

		if (temp->stockName == name)
		{
			return temp;
		}

		temp = temp->next;
	}

	cout << "could not search the stock in owned stocks" << endl;
	return nullptr;
}
int DoubleLinkedList::getsize()
{
	Node *node=this->begin->next;
	int count=0;
	while (node != end)
	{
		count++;
		node = node->next;
	}
	num = count;
	return num;
}
double DoubleLinkedList::printList()
{
	Node * temp = begin->next;
	double total = 0.0;
	cout << endl << "name" << setw(16) << "num of shares" << setw(16) << "price" << setw(16) << "total_value";

	while (temp != end)
	{
		
		cout  <<endl<<temp->stockName << setw(16) << temp->getNumberOfShares() << setw(16) << temp->getStockPrice() << setw(16)
			<< temp->getNumberOfShares()*temp->getStockPrice();

		total = temp->getNumberOfShares()*temp->getStockPrice()*1.0+total;

		temp = temp->next;
	}

	return total;
	
}

void DoubleLinkedList::deleteAll()
{
	while (begin->next != end)
	{
		delete_node(begin->next);
	}
}


void DoubleLinkedList::swap(int pos1,int pos2)
{

	Node* n1 = find_node_pos(pos1); //find node1 and node2
	Node* n2 = find_node_pos(pos2);
	if (n1 == nullptr || n2 == nullptr) {
		cout << "Error: invalid swap." << endl; //both of the node must exist
		return;
	}
	else { // determine node1 and node2 is neighbouring or not first
		if (n1->next == n2) { //if neighbouring, exchange the next and pre of both two nodes to swap it
			n1->next = n2->next;
			n2->pre = n1->pre;
			n1->pre->next = n2;
			n1->pre = n2;
			n2->next->pre = n1;
			n2->next = n1;
		}
		else if (n1->pre == n2) {
			n2->next = n1->next;
			n1->pre = n2->pre;
			n2->pre->next = n1;
			n2->pre = n1;
			n1->next->pre = n2;
			n1->next = n2;
		}
		else { // if not neighbouring, store the node1's pre and next to tempPtr first
			Node* tempPtr = new Node("", 0);
			tempPtr->next = n1->next;
			tempPtr->pre = n1->pre;
			n1->pre->next = n2;
			n1->next->pre = n2;
			n1->pre = n2->pre;
			n1->next = n2->next;
			n2->pre->next = n1;
			n2->next->pre = n1;
			n2->pre = tempPtr->pre;
			n2->next = tempPtr->next;
			delete(tempPtr);
		}
	}
}


Node* DoubleLinkedList::find_node_pos(int pos)
{
	int count = 1;
	Node *temp=begin->next;
	if (pos > getsize())
	{
		cout << "invalid position" << endl;
		return nullptr;
	}

	while ((count++) < pos)
	{
		temp = temp->next;
	}

	return temp;
}



double DoubleLinkedList::countValue()
{
	double total = 0.0;
	Node *temp = begin->next;

	while (temp != end)
	{
		total = temp->getStockPrice()*temp->getNumberOfShares()*1.0 + total;
		temp = temp->next;
	}

	return total*1.0;

}


Node* DoubleLinkedList::getBegin()
{
	return begin;
}

Node* DoubleLinkedList::getEnd()
{
	return end;
}

Node * DoubleLinkedList::getNext()
{
	return nullptr;
}

Node * DoubleLinkedList::getPre()
{
	return nullptr;
}
