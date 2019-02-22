#include "SortMethod.h"
#include "DoubleLinkedList.h"

void Sort::sort(DoubleLinkedList * list)
{
}

/*
void BubbleSort::sort(DoubleLinkedList * list)
{
	StorageHelper Helper;
	Node * temp = list->begin->next;

	while (temp != list->end)
	{
		temp->setStockPrice(Helper.getStockPrice(temp->stockName));
		temp = temp->next;
	}

	for (int i = 1; i < list->num; i++)
	{
		for(int j = i; j <= list->num; j++)
		{
			Node * stock1 = list->find_node_pos(i);
			Node * stock2 = list->find_node_pos(j);
			double stock_1 = stock1->getNumberOfShares()*stock1->getStockPrice();
			double stock_2 = stock2->getNumberOfShares()*stock2->getStockPrice();
			if (stock_1 < stock_2)
			{
				list->swap(i, j);
			}

		}
	}




}

void SelectSort::sort(DoubleLinkedList * list)
{
	StorageHelper Helper;
	Node * temp = list->begin->next;

	while (temp != list->end)
	{
		temp->setStockPrice(Helper.getStockPrice(temp->stockName));
		temp = temp->next;
	}

	for (int i = 1; i <= list->num - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j <= list->num; j++)
		{
			Node * stock1 = list->find_node_pos(min);
			Node * stock2 = list->find_node_pos(j);
			double stock_1 = stock1->getNumberOfShares()*stock1->getStockPrice();
			double stock_2 = stock2->getNumberOfShares()*stock2->getStockPrice();
			if (stock_1 < stock_2)
			{
				min = j;
			}

		}
		list->swap(i, min);
	}


}

*/
