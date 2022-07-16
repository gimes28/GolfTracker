#pragma once
#ifndef LINKEDLIST_h
#define LINKEDLIST_h

/*
* This class is the data structure used to store and
* sort the rounds of golf read from the GolfInfo.txt
* file. The structure is a linked list sorting the 
* round based on the players score. Next version of
* this program will include a data structure of a
* LinkedList of a LinkedList. Storing rounds by name,
* then sort those rounds by score. 
*/

#include <iostream>
#include "Exception.h"
#include "DataClass.h"

using namespace std;

template <class T>
class LinkedList {
private:
	struct Node {
		T* data = nullptr;
		struct Node* next = nullptr;
	};
	Node* head;
	int size;
public:
	LinkedList();
	~LinkedList();
	void AddItem(T*);
	T* GetItem(T*);
	T* SeeItem(int);
	bool IsInList(T*);
	bool IsEmpty();
	int GetSize();
	void DisplayList();

	bool operator == (const DataClass&);
	bool operator < (const DataClass&);
	bool operator > (const DataClass&);
};

template<class T>
LinkedList<T>::LinkedList() {
	int size = 0;
	head = nullptr;
}

template<class T>
LinkedList<T>::~LinkedList() {
	Node* nn = new Node;
	Node* np;

	nn = head;

	while (nn != nullptr) {
		np = nn->next;
		delete nn;
		nn = np;
	}
}

template<class T>
void LinkedList<T>::AddItem(T* item) {
	Node* nn = new Node;
	Node* np;

	nn->data = item;

	if (!head) {
		head = nn;
	}
	else {
		if (*item < *head->data) {
			nn->next = head;
			head = nn;
			size++;
			return;
		}
		np = head;
		while (np->next != NULL && *np->next->data < *item) {
			np = np->next;
		}
		nn->next = np->next;
		np->next = nn;
	}
	size++;
}

template<class T>
T* LinkedList<T>::GetItem(T* item) {
	if (IsEmpty()) {
		return nullptr;
	}
	Node* np = head;
	if (head->data == item) {
		Node* oh = head;
		T* retval = head->data;
		head = head->next;
		delete oh;
		size--;
		return retval;
	}
	while (np->next != NULL && np->next->data != item) {
		np = np->next;
	}
	if (np->next == nullptr) {
		cout << "--Item not found--" << endl;
		return nullptr;
	}
	Node* dp = np->next;
	np->next = dp->next;
	if (dp->next != nullptr) {
		np = dp->next;
	}
	else {
		np->next = nullptr;
	}
	T* retval = dp->data;
	delete dp;
	size--;
	return retval;
}
template<class T>
T* LinkedList<T>::SeeItem(int index) {
	Node* np = head;
	int place = 0;
	while (place != index && place < size) {
		np = np->next;
		place++;
	}
	return np->data;

}

template<class T>
bool LinkedList<T>::IsInList(T* item) {
	Node* np = head;
	if (IsEmpty()) {
		throw Exception("List Underflow Error");
	}
	if (head->data == item) {
		return true;
	}
	while (np->next != NULL && np->next->data != item) {
		np = np->next;
	}
	if (np->next == nullptr) {
		return false;
	}
	else {
		return true;
	}
}

template<class T>
bool LinkedList<T>::IsEmpty() {
	return size == 0;
}

template<class T>
int LinkedList<T>::GetSize() {
	return size;
};

template<class T>
void LinkedList<T>::DisplayList() {
	int posCount = 0; 
	Node* np = head;
	if (IsEmpty()) {
		throw Exception("List Underflow Error");
	}
	if (head->next == nullptr) {
		np->data->Display();
	}
	else {
		while (np->next != NULL && posCount <= size) {
			np->data->Display();
			cout << "\t   /\\ \n";
			cout << "\t   ||  \n";
			cout << "\t   ||  \n";
			cout << "\t   ||  \n";
			cout << "\t   \\/  \n";
			np = np->next;
			posCount++;
		}
		np->data->Display();
	}
	cout << endl;
}

template<class T>
bool LinkedList<T>::operator == (const DataClass& item) {
	return item.GetPlayerScore() == this->DataClass.GetPlayerScore();
}

template<class T>
bool LinkedList<T>::operator < (const DataClass& item) {
	return item.GetPlayerScore() < this->DataClass.GetPlayerScore();
}

template<class T>
bool LinkedList<T>::operator > (const DataClass& item) {
	return item.GetPlayerScore() > this->DataClass.GetPlayerScore();
}

#endif
