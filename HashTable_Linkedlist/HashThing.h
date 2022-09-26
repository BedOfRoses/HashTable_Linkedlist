#pragma once
#include <iostream>
#include "DoublyLinkedList.h"

template <typename T>
class Hash
{
private:
	int bucket;
	std::vector<T> table;

public:
	Hash(int Value);
	Hash();
	~Hash();

	void insertItem(int key);

	int hashFunction(int x) const {
		return (x % bucket);
	}

	void DisplayHash();

	std::vector<DoublyLinkedList<T>> bucketlist;

	void deleteItem(int key);

};

template<typename T>
Hash<T>::Hash(int value) : bucket(1), bucketlist(value)
{
	this->bucket = value;
	std::vector<T> table(bucket);
	//table = new DoublyLinkedList<T>[bucket];

}

template<typename T>
Hash<T>::Hash() : bucket(0)
{
}

template<typename T>
Hash<T>::~Hash()
{
}

template<typename T>
void Hash<T>::insertItem(int key)
{
	int index = hashFunction(key);
	std::cout << " index : " << index << " Key: " << key << std::endl;
	bucketlist[index].AddToTail(key);
	//table[index].AddToTail(key);

}

template<typename T>
void Hash<T>::deleteItem(int key)
{

	int index = hashFunction(key);
	std::cout << " REMOVE-index : " << index << " REMOVE-Key: " << key << std::endl;
	

	//bucketlist[index].~DoublyLinkedList<T>();
	//bucketlist.at(index)
	
	int timesToPop = bucketlist[index].NumberOfElements();

	for (int i = 0; i < timesToPop; i++)
	{
		bucketlist[index].Pop();
	}


	//bucketlist[index].Pop();
	//bucketlist.erase(bucketlist.at(index));

}


template<typename T>
void Hash<T>::DisplayHash()
{

	for (int i = 0; i < bucket; i++)
	{
		std::cout << i;
	}
	std::cout << std::endl;

	for (int i = 0; i < bucket; i++)
	{
		std::cout << "i : ";/*<< std::endl;*/
		bucketlist[i].PrintFromHead();
		std::cout << std::endl;
	}

}