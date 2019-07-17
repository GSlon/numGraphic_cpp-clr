#pragma once

#include <cliext/algorithm>
#include <cliext/vector>
#include <iostream>

using namespace System;
using namespace cliext;

template <typename T>
ref struct List
{
	T data;
	List<T> ^nextPtr, ^prevPtr;
};

template <typename T>
ref class RList
{
private:
	List<T> ^list;		// head
	int size;
	
public:
	ref class Iterator;

	RList();
	
	Void add(const T& );
	Void erase();					// удалить последний элемент
	Void erase(const T& );			// удалить заданный элемент
	Void clear();
	bool existence(const T& );
	vector<T> getElem();
	int Size();
	RList^ operator=(const RList^ );

	Iterator^ begin()		// в кольцевом списке начало и конец - это одно и то же (head)
	{
		if (list == nullptr)
			throw gcnew IndexOutOfRangeException();

		Iterator ^beginIter = gcnew Iterator(list);
		return beginIter;
	}

	// с помощью итераторов сможем перегруппировать элементы для решения задачи из ТЗ
	ref class Iterator
	{
	private:
		List<T> ^listptr;				// на что указывает наш итератор
		
	public:
		Iterator() : listptr(nullptr) { };
		Iterator(List<T> ^lptr) : listptr(lptr) { };
		Iterator(Iterator ^iter) : listptr(iter) { };

		Iterator^ operator=(const Iterator^ iter)		// префиксный оператор
		{
			if (iter == nullptr)
				this->listptr = nullptr;
			else
				this->listptr = iter->listptr;

			return this;
		}

		// список односвязный -> ходим только вперёд
		Iterator^ operator++()	// префиксный оператор
		{
			if (this->listptr->nextPtr == nullptr)
				throw gcnew IndexOutOfRangeException();
			else
				this->listptr = this->listptr->nextPtr;

			return this;
		}

		T% operator*()					// можно будет менять данные
		{
			if (listptr == nullptr)		// пустой List
				throw gcnew IndexOutOfRangeException();

			return listptr->data;
		}

		bool operator!=(const Iterator ^iter2)
		{
			if (this->listptr != iter2->listptr)
				return true;
			else
				return false;
		}
	};
};


////
template <typename T>
RList<T>::RList(): list(nullptr), size(0) { }		// пустой список

template<typename T>
Void RList<T>::add(const T &elem)
{
	if (list == nullptr)		// пусто
	{
		list = gcnew List<T>();	// сделали "голову"
		list->data = elem;
		list->nextPtr = list;	// замкнули кольцо из одного элемента
		list->prevPtr = list;
		size = 1;
		return;
	}

	List<T> ^checker = list;	// пойдём по списку
	while (true)
	{
		if (checker->nextPtr == list)			// дошли до последнего элемента (следующий - голова, ведь список кольцевой)
		{
			checker->nextPtr = gcnew List<T>();
			checker->nextPtr->data = elem;
			checker->nextPtr->nextPtr = list;	// замкнули кольцо
			list->prevPtr = checker->nextPtr;
			checker->nextPtr->prevPtr = checker;
			++size;
			break;
		}
		else
			checker = checker->nextPtr;
	}
}

template<typename T>
inline Void RList<T>::erase()
{
	if (list == nullptr)
		return;
	else
		if (size == 1)
		{
			list = nullptr;
			size = 0;
			return;
		}

	List<T> ^checker = list;
	checker = checker->prevPtr;		// шаг 'назад'
	list->prevPtr = checker->prevPtr;
	checker->prevPtr->nextPtr = list;
	--size;
}

template<typename T>
inline Void RList<T>::erase(const T &elem)
{
	if (list == nullptr)
		return;
	else
		if (size == 1)		// если элемент один - решаем по-быстрому
		{
			if (list->data == elem)
			{
				list = nullptr;
				size = 0;
			}
			return;
		}

	List<T> ^checker = list;			// пойдём по списку
	while (true)
	{
		if (checker->data == elem)
		{
			if (checker == list)		// если удалили голову
				list = checker->prevPtr;

			checker->prevPtr->nextPtr = checker->nextPtr;
			checker->nextPtr->prevPtr = checker->prevPtr;
			--size;
			return;
		}

		if (checker->nextPtr == list)	// последний элемент
			return;
		else
			checker = checker->nextPtr;
	}
}

template<typename T>
Void RList<T>::clear()
{
	list = nullptr;		// garbage collector сам почистит 
	size = 0;
}

template<typename T>
inline bool RList<T>::existence(const T &elem)
{
	if (size == 0)
		return false;

	List<T> ^checker = list;	// пойдём по списку
	while (true)
	{
		if (checker->data == elem)
			return true;
		
		if (checker->nextPtr == list)	// последний элемент
			return false;
		else
			checker = checker->nextPtr;
	}
}

template<typename T>
inline vector<T> RList<T>::getElem()
{
	if (size == 0)
		return vector<T>();

	vector<T> elems;
	
	auto iter = this->begin();
	auto end = this->begin();
	do
	{
		elems.push_back(*iter);
		++iter;
	} 
	while (iter != end);

	return elems;
}

template<typename T>
int RList<T>::Size()
{
	return size;
}

template<typename T>
inline RList<T>^ RList<T>::operator=(const RList<T> ^list)
{
	this->list = list->list;
	this->size = list->size;

	return this;
}


