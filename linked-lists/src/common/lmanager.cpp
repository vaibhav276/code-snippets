#include "../../inc/common/lmanager.h"

using namespace std;

template <typename T>
bool LManager<T>::buildListFromArray(T data[], int len) {
	
	if(m_linkedList != NULL) {
		return false; // An existing list is being already managed by this manager
	}
	
	LNode<T> *linkedList = NULL;
	LNode<T> *curr = linkedList;
	LNode<T> *newNode = NULL;

	int allocatedMemory = 0;

    if(isDebugging()) cout<<"Adding "<<len<<" nodes"<<endl;

	for(int i = 0; i < len; i++) {
		if(isDebugging()) cout<<endl<<"Creating new node for data :"<<data[i];
		newNode = new LNode<T>(data[i]);
		allocatedMemory += sizeof(LNode<T>);
		if(linkedList == NULL) { // First node
			linkedList = newNode;
			curr = linkedList;
		} else {
			curr->setNext(newNode);
			curr = newNode;
		}
	}
	if(isDebugging()) cout<<endl<<"Total Memory Allocated :" <<allocatedMemory<<" bytes";
	
	m_linkedList = linkedList;
	return true;
}

template <typename T>
bool LManager<T>::deleteList() {
	if(m_linkedList == NULL) {
		return false;
	}
	
	int releasedMemory = 0;
	if(isDebugging()) cout<<endl<<"Releasing memory...";
	LNode<T> *curr = m_linkedList;
	while(NULL != curr && NULL != curr->getNext()) {
		LNode<int> *nextNode = curr->getNext();
		delete curr;
		releasedMemory += sizeof(LNode<int>);
		curr = nextNode;
	}
	if(NULL != curr) {
		delete curr;
		releasedMemory += sizeof(LNode<int>);
	}
	if(isDebugging()) cout<<endl<<"Total Memory Released :" <<releasedMemory<<" bytes";
	
	return true;
}
