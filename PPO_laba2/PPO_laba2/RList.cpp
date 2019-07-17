#include "RList.h"

template <typename T>
RList<T>::RList()
{
	this->list = nullptr;

}


//template<typename T>
//Void RList<T>::Add(T elem)
//{
//	if (list == nullptr)	// пусто
//	{
//		list = gcnew List<T>();
//		list->data = elem;
//		list->nextPtr = nullptr;
//		return;
//	}
//	
//	List<T> ^checker = list;	// пойдём по списку
//	while (true)
//	{
//		if (checker->nextPtr == nullptr)
//		{
//			checker->nextPtr = gcnew List<T>();
//			checker->nextPtr->data = elem;
//			checker->nextPtr->nextPtr = nullptr;
//		}
//		else
//			checker = checker->nextPtr;
//	}
//}

