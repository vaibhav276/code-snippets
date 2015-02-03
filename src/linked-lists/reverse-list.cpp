/**
 * reverse-list.cpp
 * Contains method and client code to reverse a singly linked list
 * Author: Vaibhav Pujari
 * Last Updated: Feb 3, 2015
 * Updated By: Vaibhav Pujari
 */

#include <iostream>
#include "linked-lists/lmanager.h"
#include "linked-lists/lnode.h"

using namespace std;

/**
 * Function - reverseList
 * Function to reverse a singly linked list 
 * Inputs: Pointer to first node of a singly linked list
 * Outputs: Pointer to first node of reversed singly linked list
 * Complexity: O(n)
 */
template <typename T>
LNode<T> *reverseList(LNode<T> *start) {
	if(start == NULL) {
		// Reverse of nothing is nothing
		return NULL;
	}
	LNode<T> *prev = start;
	LNode<T> *curr = prev->getNext();
	if(curr == NULL) {
		// Only one node, so reverse is same as original
		return prev;
	}
	
	LNode<T> *after = curr->getNext();
	if(after == NULL) {
		// Only two nodes, trivial to reverse
		curr->setNext(prev);
		prev->setNext(NULL);
		return curr;
	}
	
	// Iterate to reverse one link at a time
	while(after != NULL) {
		curr->setNext(prev);
		prev = curr;
		curr = after;
		after = after->getNext();
	}
	curr->setNext(prev);
	start->setNext(NULL);
	
	return curr;
}

int main() {
	int data[] = {1, 5, 9, 10, 3, 78, 2};
	
	LManager<int> *lManager = new LManager<int>();
	int len = sizeof(data)/sizeof(int);
	
	//lManager->enableDebugging(); // Let's you see more details on console
	
	cout<<endl<<"Start";
	lManager->buildListFromArray(data, len);
	
	cout<<endl<<"Printing linked list"<<endl;
	cout<<lManager->getList();
	
	cout<<endl<<"Reversing list...";
	LNode<int> *rList = reverseList(lManager->getList());
	
	lManager->setHead(rList);
	
	cout<<endl<<"Printing linked list"<<endl;
	cout<<lManager->getList();
	
	cout<<endl<<"Deleting list";
	
	lManager->deleteList();
	cout<<endl<<"Done"<<endl;
	return 0;
}
