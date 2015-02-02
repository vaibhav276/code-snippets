#include "../../inc/common/lnode.h"

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
}