#ifndef __LMANAGER_H
#define __LMANAGER_H

#include "debuggable.h"
#include "lnode.h"

template <typename T>
class LManager : public Debuggable {
	private:
		LNode<T> *m_linkedList;
	public:
		LManager(): m_linkedList(NULL) {
		}
		LManager(LNode<T> *linkedList): m_linkedList(linkedList) {
		}
		void setHead(LNode<T> *newHead) {
			m_linkedList = newHead;
		}
		bool buildListFromArray(T data[], int len);
		
		bool deleteList();
		
		LNode<T> *getList() {
			return m_linkedList;
		}
};
#endif
