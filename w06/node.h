#ifndef NODE_H
#define NODE_H

namespace custom
{

  template <class T>
  class Node
  {
    public:
      // Public member data
      T data;
      Node<T>* pNext;
      Node<T>* pPrev;

      // Constructors
      Node() 
      {
        pNext = NULL;
        pPrev = NULL;
      };
      Node(const T& t) 
      {
        data = t;
        pNext = NULL;
        pPrev = NULL;
      };

  };

  // Copy function
  template <class T> 
  Node<T>* copy(const Node<T>* pSource)
  {
    Node<T>* pDestination = new Node(pSource->data);
    Node<T>* pSrc = pSource;
    Node<T>* pDest = pDestination;

    for (Node* p = pSrc.pNext; p; p = p->pNext)
      pDest = insert(pSrc.data, pDest, true);
    return pDestination;
  }

  // Insert a new node into the linked list
  template <class T> 
  Node<T>* insert(Node<T>* pNode, const T& t, bool after = false)
  {
	/* todo
    pNew = new Node(t);
    return pNew;
	*/
  }

  // Find an element from a linked list
  template <class T> 
  Node<T>* find(Node<T>* pHead, const T& t)
  {
    return NULL;
  }

  // Output the contents of the list
  /* todo
  template <class T> 
  ostream& operator<< (ostream& out, Node<T>& rhs)
  {
    return out;
  }
  */

  // Clear the data from the list
  template <class T> 
  void freeData(Node<T>* & pHead)
  {

  }

  // Remove an element from the list
  template <class T> 
  Node<T>* remove(const Node<T>* pRemove)
  {
    return NULL;
  }

};
#endif
