#include <iostream>
#include "linked-lists/lmanager.h"
#include "linked-lists/lnode.h"

using namespace std;

template <typename T>
LNode<T> *reverseList(LNode<T> *start) {
	if(start == NULL) {
		return NULL;
	}
	LNode<T> *prev = start;
	LNode<T> *curr = prev->getNext();
	if(curr == NULL) {
		// Only one node, so its already reversed
		return prev;
	}
	
	LNode<T> *after = curr->getNext();
	if(after == NULL) {
		// Only two nodes, trivial to reverse
		curr->setNext(prev);
		prev->setNext(NULL);
		return curr;
	}
	
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
	
	//lManager->enableDebugging();
	
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
