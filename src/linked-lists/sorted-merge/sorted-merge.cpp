/**
 * sorted-merge.cpp
 * Contains method and client code to merge twwo singly linked lists
 * Author: Vaibhav Pujari
 * Last Updated: Feb 4, 2015
 * Updated By: Vaibhav Pujari
 */
 
#include <iostream>
#include <common/lmanager.h>
#include <common/lnode.h>

using namespace std;

/**
 * Function - sortedMergeR
 * Function to recursively merge two singly linked lists
 * Inputs: Pointers to first nodes of two singly linked list
 * Outputs: Pointer to first node of merged singly linked list
 * Complexity: O(n)
 */
template <typename T>
LNode<T> *sortedMergeR(LNode<T> *a, LNode<T> *b) {
    LNode<T> *res = NULL;
    
    if(NULL == a) return b;
    if(NULL == b) return a;
    if(*(a->getData()) <= *(b->getData())) {
    	res = a;
    	res->setNext(sortedMergeR(a->getNext(), b));
    } else {
    	res = b;
    	res->setNext(sortedMergeR(b->getNext(), a));
    }
    
    return res;
}

int main() {
	int a[] = {1, 5, 9, 10, 13, 78, 102};
	int b[] = {1, 15, 29, 100, 134, 798, 1024};
	
	LManager<int> *lManagerA = new LManager<int>();
	LManager<int> *lManagerB = new LManager<int>();
	int lenA = sizeof(a)/sizeof(int);
	int lenB = sizeof(b)/sizeof(int);
	
	//lManagerA->enableDebugging(); // Let's you see more details on console
	//lManagerB->enableDebugging(); // Let's you see more details on console
	
	cout<<endl<<"Start";
	lManagerA->buildListFromArray(a, lenA);
	lManagerB->buildListFromArray(b, lenB);
	
	cout<<endl<<"Printing linked list A"<<endl;
	cout<<lManagerA->getList();
	cout<<endl<<"Printing linked list B"<<endl;
	cout<<lManagerB->getList();
	
	cout<<endl<<"Merging lists...";
	LNode<int> *mergedList = sortedMergeR(lManagerA->getList(), lManagerB->getList());
	
	LManager<int> *lManagerC = new LManager<int>();
	lManagerC->setHead(mergedList);
	
	cout<<endl<<"Printing merged linked list"<<endl;
	cout<<lManagerC->getList();
	
	cout<<endl<<"Deleting lists";
	
	lManagerA->deleteList();
	lManagerB->deleteList();
	lManagerC->deleteList();
	
	cout<<endl<<"Done"<<endl;
	return 0;
}
