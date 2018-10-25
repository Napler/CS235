/***********************************************************************
 * Header:
 *    INSERTION SORT
 * Summary:
 *    This will contain just the prototype for insertionSortTest(). You may
 *    want to put other class definitions here as well.
 * Author
 *    <your names here>
 ************************************************************************/

#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "node.h"

 /***********************************************
  * INSERTION SORT
  * Sort the items in the array
  **********************************************/
template <class T>
void sortInsertion(T array[], int num)
{
	Node<T> * pNode = new Node<T>;
	pNode->data = array[0];
	
	for (int i = 1; i < num; i++)
	{
		Node<T> * thisNode = new Node<T>(array[i]);

		if (thisNode->data >= pNode->data) 
		{
			while (pNode->pNext && thisNode->data > pNode->pNext->data)
			{
				pNode = pNode->pNext;
			}
	
			thisNode->pNext = pNode->pNext;
			thisNode->pPrev = pNode;

			if (pNode->pNext)
			{
				pNode->pNext->pPrev = thisNode;
			}

			pNode->pNext = thisNode;
		}
		else 
		{
			while (pNode->pPrev && thisNode->data < pNode->pPrev->data)
			{
				pNode = pNode->pPrev;
			}
			
			thisNode->pNext = pNode;
			thisNode->pPrev = pNode->pPrev;

			if (pNode->pPrev)
			{
				pNode->pPrev->pNext = thisNode;
			}

			pNode->pPrev = thisNode;
		}
	}
	
	while (pNode->pPrev)
	{
		pNode = pNode->pPrev;
	}
	
	int iter = 0;
	while (pNode->pNext)
	{
		array[iter] = pNode->data;
		pNode = pNode->pNext;
		iter++;
	}
	
	array[iter] = pNode->data;
}

#endif // INSERTION_SORT_H