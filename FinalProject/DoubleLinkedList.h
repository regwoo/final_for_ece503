#pragma once
#include <string>


using namespace std;
#include "Node.h"

class DoubleLinkedList
{
	
public:
	DoubleLinkedList();
	~DoubleLinkedList();
	friend class StcockAccount;
	void insert_node(Node*);
	void  delete_node(Node*);
	//Node* find_node();
	Node* find_node(string);
	Node* find_node_pos(int pos);
	Node* getBegin();
	Node* getEnd();

	Node* getNext();
	Node* getPre();
	int getsize();
	double printList();
	void deleteAll();//delete all node from the list
	void swap(int a,int b);//swap two node
	//return value change to node *,mind the sort disturb

	double countValue();
	int num;
private:
	Node * begin;
	Node * end;
	
};