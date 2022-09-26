#include <iostream>
//#include "DoublyLinkedList.h"

#include "HashThing.h"

	
int main() {


	int keys[] = { 3,15,23,14,17,10,9 };

	int n = sizeof(keys) / sizeof(keys[0]);

	Hash<int> h(10);
	
	for (int i = 0; i < n; i++)
	{
		h.insertItem(keys[i]);
	}

	h.DisplayHash();
	
	//h.deleteItem(3);
	h.deleteItemSpecific(3, 0);

	std::cout << "Display again" << std::endl;

	h.DisplayHash();

	return 0;
}