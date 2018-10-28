#ifndef LIST_H
#define LIST_H

#include "node.h";

namespace custom
{
	template <class T>
	class list
	{
	private:
		Node<T> pHead;
		Node<T> pTail;
		int numElements;

	public:
		list();
		list(const list &rhs);
		list &operartor= (const list &rhs);
		~list();

		int size() const;
		bool empty() const;
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
}

#endif