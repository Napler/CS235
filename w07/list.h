#ifndef LIST_H
#define LIST_H

namespace custom
{
	template<typename T>
	struct Node
	{
		T data;
		Node<T> *pNext;
		Node<T> *pPrev;

		Node(T t) : data(t), pNext(nullptr), pPrev(nullptr) {};
	};


	template <class T>
	class list
	{
	private:
		Node<T> *pHead;
		Node<T> *pTail;
		int numElements;

		void linkNodes(Node<T> *front, Node<T> *back);

	public:
		list() : pHead(nullptr), pTail(nullptr), numElements(0) {};
		list(const list &rhs);
		list &operator=(const list &rhs);
		~list();

		int size() const { return numElements; }
		bool empty() const { return (bool)(!numElements); }
		void clear();

		void push_back(T t);
		void push_front(T t);
		void pop_back();
		void pop_front();

		T &front();
		const T &front() const;
		T &back();
		const T &back() const;

		// iterators
		class iterator;
		class const_iterator;
		class reverse_iterator;
		class const_reverse_iterator;

		void erase(iterator &it);
		void insert(iterator it, T t);

		iterator find(T t)
		{
			//todo
			return iterator();
		}

		iterator begin()
		{
			return iterator(pHead);
		}
		iterator end()
		{
			if (pTail != nullptr)
			{
				return iterator(pTail->pNext);
			}

			return iterator();
		}

		const_iterator cbegin()
		{
			return const_iterator(pHead);
		}
		const_iterator cend()
		{
			if (pTail != nullptr)
			{
				return const_iterator(pTail->pNext);
			}

			return const_iterator();
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(pTail);
		}
		reverse_iterator rend()
		{
			if (pHead != nullptr)
			{
				return reverse_iterator(pHead->pPrev);
			}
			
			return reverse_iterator();
		}

		const_reverse_iterator crbegin()
		{
			return const_reverse_iterator(pTail);
		}
		const_reverse_iterator crend()
		{
			if (pHead != nullptr)
			{
				return const_reverse_iterator(pHead->pPrev);
			}

			return const_reverse_iterator();
		}
	};


	template<class T>
	void list<T>::linkNodes(Node<T> *front, Node<T> *back)
	{
		front->pNext = back;
		back->pPrev = front;
	}

	template<class T>
	list<T>::list(const list &rhs)
	{
		numElements = 0;
		pHead = nullptr;
		pTail = nullptr;

		if (rhs.numElements <= 0)
		{
			return;
		}

		Node<T> *node = rhs.pHead;
		push_back(node->data);

		for (int i = 1; i < rhs.numElements; i++)
		{
			node = node->pNext;
			push_back(node->data);
		}

		numElements = rhs.numElements;
	}

	template<class T>
	list<T> &list<T>::operator=(const list &rhs)
	{
		clear();

		if (rhs.numElements <= 0)
		{
			numElements = 0;
			pHead = nullptr;
			pTail = nullptr;
			return *this;
		}

		Node<T> *node = rhs.pHead;
		push_back(node->data);

		for (int i = 1; i < rhs.numElements; i++)
		{
			node = node->pNext;
			push_back(node->data);
		}

		numElements = rhs.numElements;
		return *this;
	}

	template<class T>
	list<T>::~list()
	{
		clear();
	}

	template<class T>
	void list<T>::clear()
	{
		if (pHead != nullptr)
		{
			while (pHead != pTail)
			{
				pHead = pHead->pNext;
				delete pHead->pPrev;
			}

			delete pHead;
			pHead = nullptr;
			pTail = nullptr;
		}

		numElements = 0;
	}

	template<class T>
	void list<T>::push_back(T t)
	{
		Node<T> *newNode = new Node<T>(t);

		if (pHead == nullptr)
		{
			pHead = newNode;
			pTail = newNode;
		}
		else
		{
			linkNodes(pTail, newNode);
			pTail = newNode;
		}

		numElements++;
	}

	template<class T>
	void list<T>::push_front(T t)
	{
		Node<T> *newNode = new Node<T>(t);
		
		if (pHead == nullptr)
		{
			pHead = newNode;
			pTail = newNode;
		}
		else
		{
			linkNodes(newNode, pHead);
			pHead = newNode;
		}
		
		numElements++;
	}

	template<class T>
	void list<T>::pop_back()
	{
		Node<T> *newTail = pTail->pPrev;
		delete pTail;
		pTail = newTail;
		numElements--;
	}

	template<class T>
	void list<T>::pop_front()
	{
		Node<T> *newHead = pHead->pNext;
		delete pHead;
		pHead = newHead;
		numElements--;
	}

	template<class T>
	T &list<T>::front()
	{
		return pHead->data;
	}

	template<class T>
	const T &list<T>::front() const
	{
		return pHead->data;
	}

	template<class T>
	T &list<T>::back()
	{
		return pTail->data;
	}

	template<class T>
	const T &list<T>::back() const
	{
		return pTail->data;
	}

	template<class T>
	void list<T>::erase(iterator &it)
	{
		//todo
	}

	template<class T>
	void list<T>::insert(iterator it, T t)
	{
		//todo
	}

	//iterators
	template <class T>
	class list <T> ::iterator
	{
	private:
		Node<T> *pNode;

	public:
		iterator() : pNode(nullptr) {}
		iterator(Node<T> *rhs) : pNode(rhs) {}
		iterator(const iterator &rhs) { *this = rhs; }
		iterator &operator = (const iterator &rhs) { pNode = rhs.pNode; return *this; }

		bool operator==(const iterator &rhs) const { return pNode == rhs.pNode; }
		bool operator!=(const iterator &rhs) const { return pNode != rhs.pNode; }
		
		T &operator*()
		{
			if (pNode != nullptr)
			{
				return pNode->data;
			}

			//todo: can't return nullptr?
		}

		iterator &operator++()
		{
			if (pNode != nullptr)
			{
				pNode = pNode->pNext;
			}

			return *this;
		}
		iterator operator++(int postfix)
		{
			iterator tmp(*this);

			if (pNode != nullptr)
			{
				pNode = pNode->pNext;
			}

			return tmp;
		}
		
		iterator &operator--()
		{
			if (pNode != nullptr)
			{
				pNode = pNode->pPrev;
			}

			return *this;
		}
		iterator operator--(int postfix)
		{
			iterator tmp(*this);

			if (pNode != nullptr)
			{
				pNode = pNode->pPrev;
			}

			return tmp;
		}
	};

	template <class T>
	class list <T> ::const_iterator
	{
	private:
		Node<T> *pNode;
	public:
		const_iterator() : pNode(nullptr) {}
		const_iterator(Node<T> *rhs) : pNode(rhs) {}
		const_iterator(const const_iterator &rhs) { *this = rhs; }
		const_iterator &operator=(const const_iterator &rhs) { pNode = rhs.pNode; return *this; }

		bool operator==(const const_iterator &rhs) const { return pNode == rhs.pNode; }
		bool operator!=(const const_iterator &rhs) const { return pNode != rhs.pNode; }
		
		T &operator*()
		{
			if (pNode != nullptr)
			{
				return pNode->data;
			}
			
			//todo: can't return nullptr?
		}

		const_iterator &operator++()
		{
			if (pNode != nullptr)
			{
				pNode = pNode->pNext;
			}

			return *this;
		}
		const_iterator operator++(int postfix)
		{
			const_iterator tmp(*this);

			if (pNode != nullptr)
			{
				pNode = pNode->pNext;
			}

			return tmp;
		}

		const_iterator &operator--()
		{
			if (pNode != nullptr)
			{
				pNode = pNode->pPrev;
			}

			return *this;
		}
		const_iterator operator--(int postfix)
		{
			iterator tmp(*this);

			if (pNode != nullptr)
			{
				pNode = pNode->pPrev;
			}

			return tmp;
		}
	};

	template <class T>
	class list <T> ::reverse_iterator
	{
	private:
		Node<T> *pNode;

	public:
		reverse_iterator() : pNode(nullptr) {}
		reverse_iterator(Node<T> *rhs) : pNode(rhs) {}
		reverse_iterator(const reverse_iterator &rhs) { *this = rhs; }
		reverse_iterator &operator=(const reverse_iterator &rhs) { pNode = rhs.pNode; return *this; }

		bool operator==(const reverse_iterator &rhs) const { return pNode == rhs.pNode; }
		bool operator!=(const reverse_iterator &rhs) const { return pNode != rhs.pNode; }

		T &operator*()
		{
			if (pNode != nullptr)
			{
				return pNode->data;
			}

			//todo: can't return nullptr?
		}

		reverse_iterator &operator++()
		{
			if (pNode != nullptr)
			{
				pNode = pNode->pPrev;
			}

			return *this;
		}
		reverse_iterator operator++(int postfix)
		{
			reverse_iterator tmp(*this);

			if (pNode != nullptr)
			{
				pNode = pNode->pPrev;
			}

			return tmp;
		}

		reverse_iterator &operator--()
		{
			if (pNode != nullptr)
			{
				pNode = pNode->pNext;
			}

			return *this;
		}
		reverse_iterator operator--(int postfix)
		{
			reverse_iterator tmp(*this);

			if (pNode != nullptr)
			{
				pNode = pNode->pNext;
			}

			return tmp;
		}
	};

	template <class T>
	class list <T> ::const_reverse_iterator
	{
	private:
		Node<T> *pNode;

	public:
		const_reverse_iterator() : pNode(nullptr) {}
		const_reverse_iterator(Node<T> *rhs) : pNode(rhs) {}
		const_reverse_iterator(const reverse_iterator &rhs) { *this = rhs; }
		const_reverse_iterator &operator=(const reverse_iterator &rhs) { pNode = rhs.pNode; return *this; }

		bool operator == (const const_reverse_iterator &rhs) const { return pNode == rhs.pNode; }
		bool operator != (const const_reverse_iterator &rhs) const { return pNode != rhs.pNode; }

		T &operator*()
		{
			if (pNode != nullptr)
			{
				return pNode->data;
			}

			//todo: can't return nullptr?
		}
		
		const_reverse_iterator &operator++()
		{
			if (pNode != nullptr)
			{
				pNode = pNode->pPrev;
			}

			return *this;
		}
		const_reverse_iterator operator++ (int postfix)
		{
			const_reverse_iterator tmp(*this);

			if (pNode != nullptr)
			{
				pNode = pNode->pPrev;
			}

			return tmp;
		}

		const_reverse_iterator &operator--()
		{
			if (pNode != nullptr)
			{
				pNode = pNode->pNext;
			}

			return *this;
		}
		const_reverse_iterator operator--(int postfix)
		{
			reverse_iterator tmp(*this);

			if (pNode != nullptr)
			{
				pNode = pNode->pNext;
			}

			return tmp;
		}
	};
}

#endif
