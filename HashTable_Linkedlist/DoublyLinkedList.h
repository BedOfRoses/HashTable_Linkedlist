#pragma once



#include <iostream>
#include <vector>


template <typename T>
class Node {
public:
	T Data{};
	Node<T>* Next; //	next element
	Node<T>* Prev; //	previous element
	
	Node() : Next(nullptr), Prev(nullptr) {
		/*Prev = nullptr;
		Next = nullptr;*/
		//Data = NULL;
	}
	~Node(){}

};



template <typename T>
class DoublyLinkedList : Node<T> {
public:

	Node<T>* Head;
	Node<T>* Tail;

	//constructor / intialize
	DoublyLinkedList<T>();

	void AddToTail(T element);
	void AddToHead(T element);
	void PrintFromHead();
	void PrintFromTail();
	void InsertAt(int index, T data);
	int NumberOfElements();
	void Pop();
	void Pop_front();
	void InsertNewNodeAt(int index, T data);
	void SelectionSort();
	void RemoveAt(int index);

	void cleanUpDoubles();

	~DoublyLinkedList<T>() {};

};

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	Head = nullptr;
	Tail = nullptr;
	//Head = Tail;'	
}

template<typename T>
void DoublyLinkedList<T>::AddToTail(T element)
{

	Node<T>* newNode = new Node<T>(); // create new node
	newNode->Data = element; // insert data in node
	newNode->Next = nullptr;
	newNode->Prev = nullptr;


	//if there is nothing in the tail or it is the head
	if (Tail == nullptr)
	{
		Head = newNode;
		Tail = Head;
	}
	// other wise we will put elements to the tail
	else
	{
		Tail->Next = newNode; // tails next location is the location of newnode
		newNode->Prev = Tail; // newnode's previous location is where tail is
		Tail = newNode; // move the tail to the newnode position
	}
	

}

template<typename T>
void DoublyLinkedList<T>::AddToHead(T element)
{
	Node<T>* newNode = new Node<T>();
	newNode->Data = element;
	newNode->Next = nullptr;
	newNode->Prev = nullptr;

	Node<T>* h = Head;

	if(Head == nullptr)
	{
		delete newNode;
		AddToTail(element);
	}
	else
	{
		Head->Prev = newNode;
		newNode->Next = Head;
		Head = newNode;

	


	}



}

template<typename T>
void DoublyLinkedList<T>::PrintFromHead()
{

	/*PRECATION*/
	if (NumberOfElements() == 0) {
		std::cout << "Queue is empty" << std::endl;
		return;
	}

	Node<T>* ptr = Head;

	while (ptr != nullptr)
	{
		std::cout << ptr->Data << " ";
		ptr = ptr->Next;

	}


}

template<typename T>
void DoublyLinkedList<T>::PrintFromTail()
{
	Node<T>* ptr = Tail;

	/*PRECATION*/
	if (NumberOfElements() == 0) {
		std::cout << "Queue is empty" << std::endl;
		return;
	}

	while (ptr != nullptr)
	{
		std::cout << ptr->Data << " ";
		ptr = ptr->Prev;
	}


}

template<typename T>
void DoublyLinkedList<T>::InsertAt(int index, T data)
{
	int i = 0;
	Node<T>* ptr = Head; // start from the beginning

	if (index == i) {
		//ptr->Data = data;

		AddToHead(data);
		return;
	}

	else if (index >= NumberOfElements())
	{
		AddToTail(data);
		return;
		
		/*ptr = ptr->Next;
		i++;*/
	}

	else
	{
		Node<T>* p = Head;
		Node<T>* newNode = new Node<T>();
		newNode->Data = data;
		int i = 0;

		while (i < index - 1) 
		{
			p = p->Next;
			i++;
		}

		newNode->Next = p->Next; //ok
		newNode->Prev = p; // ok

		p->Next->Prev = newNode; // ok
		p->Next = newNode; // ok

		//delete p; // error?

		/*i = 0;

		while (index != i)
		{
			ptr = ptr->Next;
			i++;
		}
		ptr->Data = data;*/
	}
}
	

template<typename T>
void DoublyLinkedList<T>::RemoveAt(int index)
{

	Node<T>* ptr = Head;
	

	//*SAFETY PRECATION*/
	 if (ptr == nullptr) {
	 std::cout << "Queue is empty, function::RemoveAt(int index)" << std::endl;
	 delete ptr;
	 return;

	}
	
	 if (index == 0) // i = 0 / start/ head
	 {
		 std::cout << "removed at front" << std::endl;
		 Pop_front();
		 return;
	 }

	 if (index >= NumberOfElements() - 1) // addded -1
	 {
		 std::cout << "removed at back" << std::endl;
		 Pop();
		 return;
	 }


	
		int i = 1;
		// 1 < 1
	while (i < index)
	{
		// for debugging
		//std::cout << "ptr data is: " << ptr->Data << " and next is : " << ptr->Next << std::endl;
		ptr = ptr->Next;
		i++;
	}



	Node<T>* del = ptr;

		//ptr = ptr->Prev; // step 1 back;

		del = ptr->Next; // same pos literally

		del->Next->Prev = ptr;
		ptr->Next = del->Next;
		delete del;
	





	/*int i = 0;

	while (index < i)
	{
		ptr = ptr->Next;
		i++;
	}

	if(ptr->Next == Tail)
	{
		Node<T>* tmpTail = Tail->Prev;

	}



	Node<T>* tempNext = ptr->Next->Next;
	tempNext->Prev = ptr->Prev;

	delete ptr;*/
	

}



template<typename T>
int DoublyLinkedList<T>::NumberOfElements()
{
	Node<T>* ptr = Head; // start

	int numOfElements{};

	while (ptr != nullptr)
	{
		numOfElements++;

		//if (ptr->Next == nullptr)
			ptr = ptr->Next;

	}
	delete ptr;

	return numOfElements;
}

template<typename T>
void DoublyLinkedList<T>::Pop()
{
	/*if (Tail->Prev == nullptr) {
		return;
	}*/

	/*
		if (Tail->Prev == nulptr)
			return;
	*/

	Node<T>* newNode = Tail;
	
	if(newNode == nullptr)
	{
		std::cout << "Queue is empty" << std::endl;
		Tail = Head;
		delete newNode;
	}
	if(newNode == Head)
	{
		std::cout << "queue is empty" << std::endl;
		newNode = Tail;
		Tail = Tail->Prev;
		Head = Tail;
		delete newNode;
	}
	else
	{
		newNode = Tail;
		Tail = Tail->Prev;
		Tail->Next = nullptr;
		delete newNode;
	}
	

	
}

template<typename T>
void DoublyLinkedList<T>::Pop_front()
{
	Node<T>* ptr = Head;
	if (ptr == nullptr)
	{
		std::cout << "Queue is empty" << std::endl;
		Head = Tail;
		delete ptr;
	}
	else
	{
		ptr = Head;
		Head = Head->Next;
		Head->Prev = nullptr;
		delete ptr;
	}

}

template<typename T>
void DoublyLinkedList<T>::cleanUpDoubles()
{
	SelectionSort();

	Node<T>* p = Head;
	Node<T>* temp;
	
	if (Head == nullptr)
		return;

	
	while (p->Next != nullptr)
	{

		if(p->Data == p->Next->Data && p->Next == Tail)
		{
			temp = Tail->Prev;
			delete Tail;
			Tail = temp;
			Tail->Next = nullptr;
			return;
		}

		// Check if the current data is the same as the next data
		if(p->Data == p->Next->Data)
		{
			//Save the next of the next, so that we can delete the current next
			temp = p->Next->Next;
			


			// Delete the duplicate node
			delete p->Next;

			temp->Prev = p;
			p->Next = temp;


		}
		//Other wise, we move forward/ next element
		else
		{
			p = p->Next;
		}
	}


}


template<typename T>
void DoublyLinkedList<T>::SelectionSort() 
{

	int n = NumberOfElements();

	T* data = new T[NumberOfElements()];

	Node<T>* ptr = Head;
	
	// save everything into the newly made array
	for (int k = 0; k < n; k++)
	{
		data[k] = ptr->Data;
		ptr = ptr->Next;
	}



	int min_index = 0;

	for (int i = 0; i < n-1; i++)
	{
		min_index = i;

		for (int j = i+1; j < n; j++)
		{
			if (data[j] < data[min_index]) 
			{
				min_index = j;
			}
		}
		std::swap(data[min_index], data[i]);

	}

	ptr = Head;

	for (int i = 0; i < n; i++)
	{
		ptr->Data = data[i];
		ptr = ptr->Next;	
	}
	delete ptr;
	delete[] data;

}