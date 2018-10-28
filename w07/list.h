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
	inline list<T>::list()
	{
		//todo
	}
	template<class T>
	inline list<T>::list(const list & rhs)
	{
		//todo
	}
	template<class T>
	inline list<T>::~list()
	{
		//todo
	}
	template<class T>
	inline void list<T>::clear()
	{
		//todo
	}
	template<class T>
	inline void list<T>::push_back(T t)
	{
		//todo
	}
	template<class T>
	inline void list<T>::push_front(T t)
	{
		//todo
	}
	template<class T>
	inline void list<T>::pop_back()
	{
		//todo
	}
	template<class T>
	inline void list<T>::pop_front()
	{
		//todo
	}
	template<class T>
	inline T & list<T>::front()
	{
		//todo
		return T();
	}
	template<class T>
	inline const T & list<T>::front() const
	{
		//todo
		return T();
	}
	template<class T>
	inline T & list<T>::back()
	{
		//todo
		return T();
	}
	template<class T>
	inline const T & list<T>::back() const
	{
		//todo
		return T();
	}
	template<class T>
	inline void list<T>::erase(iterator & it)
	{
		//todo
	}
	template<class T>
	inline void list<T>::insert(iterator it, T t)
	{
		//todo
	}
}

#endif