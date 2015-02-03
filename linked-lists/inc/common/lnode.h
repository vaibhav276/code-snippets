#ifndef __LNODE_H
#define __LNODE_H

#include <iostream>

template <typename T>
class LNode {
	private:
		T *m_data;
		LNode<T> *m_next;
		int m_sizeOfList;
	public:
		LNode(T d) {
			m_data = new T(d);
			m_next = NULL;
			m_sizeOfList = sizeof(LNode<T>);
		}
		T* getData() {
			return m_data;
		}
		void setNext(LNode *n) {
			m_next = n;
		}
		LNode<T> *getNext() {
			return m_next;
		}
		
		template <typename U>
		friend std::ostream& operator << (std::ostream&, LNode<U>*);
};

template <typename T>
std::ostream& operator << (std::ostream& os, LNode<T> *list) {
		LNode<int> *curr = list;
		int sizeOfList = 0;
		while(NULL != curr && NULL != curr->getNext()) {
			os<<*(curr->getData())<<"->";
			sizeOfList += sizeof(LNode<T>);
			curr = curr->getNext();
		}
		os<<*(curr->getData());
		sizeOfList += sizeof(LNode<T>);
		os<<" ("<<sizeOfList<<" bytes)";
		
		return os;
}

#endif