#ifndef LIST_H
#define LIST_H

#include "node.h";

namespace custom
{
	template <class T>
	class list
	{
	private:
		Node<T> * pHead;
		Node<T> * pTail;
		int numElements;

	public:
		list() : pHead(nullptr), pTail(nullptr), numElements(0) {};
		list(const list &rhs);
		list &operator= (const list &rhs);
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

		iterator find(T t);

		void erase(iterator &it);
		void insert(iterator it, T t);

		iterator begin();
		iterator end();
	};
	template<class T>
	list<T>::list(const list &rhs)
	{
		//todo
	}
	template<class T>
	list<T> &list<T>::operator=(const list &rhs)
	{
		//todo
		return *this;
	}
	template<class T>
	list<T>::~list()
	{
		//todo
	}
	template<class T>
	void list<T>::clear()
	{
		//todo
	}
	template<class T>
	void list<T>::push_back(T t)
	{
		//todo
	}
	template<class T>
	void list<T>::push_front(T t)
	{
		//todo
	}
	template<class T>
	void list<T>::pop_back()
	{
		//todo
	}
	template<class T>
	void list<T>::pop_front()
	{
		//todo
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
}

#endif