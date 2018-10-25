#ifndef NODE_H
#define NODE_H

#include "node.h"
#include <string>
using namespace std;

/***********************************************
 * NODE
 **********************************************/
template <class T>
class Node
{
public:
	// Public member data
	T data;
	Node * pNext;
	Node * pPrev;

	// Constructors
	Node()
	{
		pNext = NULL;
		pPrev = NULL;
	}
	Node(const T &t)
	{
		data = t;
		pNext = NULL;
		pPrev = NULL;
	}
};

/***********************************************
 * COPY FUNCTION
 **********************************************/
template <class T>
Node<T> *copy(const Node<T> *pSource)
{
	Node<T> *copy = new Node<T>(pSource->data);
	Node<T> *node = copy;

	while (pSource->pNext)
	{
		pSource = pSource->pNext;
		node->pNext = new Node<T>(pSource->data);
		node->pNext->pPrev = node;
		node = node->pNext;
	}

	return copy;
}

/***********************************************
 * INSERT FUNCTION
 * Insert a new node into the linked list
 **********************************************/
template <class T>
Node<T> *insert(Node<T> *pNode, const T &t, bool after = false)
{
	Node<T> *pNew = new Node<T>(t);

	if (pNode == NULL) 
	{
		pNode = pNew;
		return pNode;
	}

	if (after == true) 
	{
		if (pNode->pNext != NULL)
		{
			pNew->pNext = pNode->pNext;
			pNode->pNext->pPrev = pNew;

			pNode->pNext = pNew;
			pNew->pPrev = pNode;
		}
		else
		{
			pNode->pNext = pNew;
			pNew->pPrev = pNode;
		}
	}
	else {
		if (pNode->pPrev != NULL)
		{
			pNew->pPrev = pNode->pPrev;
			pNode->pPrev->pNext = pNew;

			pNew->pNext = pNode;
			pNode->pPrev = pNew;
		}
		else
		{
			pNode->pPrev = pNew;
			pNew->pNext = pNode;
		}
	}

	return pNew;
}

/***********************************************
* FIND
* Find an element from a linked list
**********************************************/
template <class T>
Node <T> * find(Node<T> *pHead, const T &t)
{
	while (pHead->pNext)
	{
		if (t == pHead->data)
		{
			return pHead;
		}

		pHead = pHead->pNext;
	}

	if (t == pHead->data)
	{
		return pHead;
	}

	return NULL;
}

/***********************************************
 * OPERATOR <<
 * Output the contents of the list
 **********************************************/
template <class T>
std::ostream &operator<< (std::ostream &out, Node<T> *rhs)
{
	for (Node<T> *p = rhs; p; p = p->pNext)
	{
		out << p->data;
		if (p->pNext != NULL)
		{
			out << ", ";
		}
	}

	return out;
}

/***********************************************
 * FREEDATA
 * Clear the data from the list
 **********************************************/
template <class T>
void freeData(Node<T> *&pHead)
{
	Node<T> *toDelete;
	while (pHead != NULL)
	{
		toDelete = pHead;
		pHead = pHead->pNext;
		delete toDelete;
	}
}

/***********************************************
 * REMOVE
 * Remove an element from the list
 **********************************************/
template <class T>
Node<T> *remove(const Node<T> *pRemove)
{
	if (pRemove == NULL)
	{
		return NULL;
	}

	if (pRemove->pPrev != NULL)
	{
		pRemove->pPrev->pNext = pRemove->pNext;
	}

	if (pRemove->pNext != NULL)
	{
		pRemove->pNext->pPrev = pRemove->pPrev;
	}

	Node<T> *result;

	if (pRemove->pPrev != NULL)
	{
		result = pRemove->pPrev;
	}
	else
	{
		result = pRemove->pNext;
	}

	delete pRemove;
	return result;
}

#endif