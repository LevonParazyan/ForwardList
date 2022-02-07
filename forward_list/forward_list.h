#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

#include <iostream>

namespace Forward_List {
    template <typename L>
    class List {
    public:
        List();
        List(L);
        List(const List<L>&);
        ~List();
    public:
        void push_back(L);
		void push_front(L);
		void pop_back();
		void pop_front();
		void insert(L,int);
		void removeAt(int);
		void erase(int);
		void clear();
		int getSize()const;
        L& operator[](const int index);
    private:
        template <typename N>
        class Node {
            public:
                N nodeData;
                Node* nextNode;
                Node(N data = N(),Node* pNext = nullptr)
				:nodeData{data},nextNode{pNext}
			    {}
        };
        private:
            int size;
            Node<L>* head;
    };
#include "forward_list.tpp"
} // namespace Forward_List

#endif // FORWARD_LIST_H