/***********************************************************************
 * Header:
 *    INSERTION SORT
 * Summary:
 *    This will contain just the prototype for insertionSortTest(). You may
 *    want to put other class definitions here as well.
 * Author
 *    Jose Paredes, Cam Dockstader & Nathan Prestwich
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
  //use nodes to put array values in a linked list to sort the array
	Node<T> * pNode = new Node<T>;
	pNode->data = array[0];
	int i = 0;
	
	for (i = 1; i < num; i++)
	{
		Node<T> * thisNode = new Node<T>(array[i]);
    //if the value in thisNode is greater/equal to the value in pnode
		if (thisNode->data >= pNode->data) 
		{
      //loops until it hits either NULL or pNode->pNext value is greater than in thisNode
			while (pNode->pNext && thisNode->data > pNode->pNext->data)
			{
				pNode = pNode->pNext;
			}
	    //inserts thisNode in front of pNode
			thisNode->pNext = pNode->pNext;
			thisNode->pPrev = pNode;
      
			if (pNode->pNext)
			{
				pNode->pNext->pPrev = thisNode;
			}

			pNode->pNext = thisNode;
		}
    //else the value in thisNode is less than the value in pNode
		else 
		{
      //loops until it hits either Null or pNode->pPrev value is lesser than in thisNode
			while (pNode->pPrev && thisNode->data < pNode->pPrev->data)
			{
				pNode = pNode->pPrev;
			}
			//inserts thisNode before pNode
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
	//loop to insert the values in the linked list back into the array
	i = 0;
	while (pNode->pNext)
	{
		array[i] = pNode->data;
		pNode = pNode->pNext;
		i++;
	}
	
	array[i] = pNode->data;
}

#endif // INSERTION_SORT_H