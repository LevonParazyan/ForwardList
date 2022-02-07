#include "forward_list.h"


template <typename L>
Forward_List::List<L>::List()
	:head{nullptr},size{}
{}

template <typename L>
Forward_List::List<L>::List(const List<L>& rhs) {
	this->size = rhs.size;
    for(int i{}; i < size; ++i)
        this -> push_back(rhs[i]);
}

template <typename L>
Forward_List::List<L>::~List() {
	clear();
}

template <typename L>
void Forward_List::List<L>::push_front(L data) {
	head = new Node<L>(data, head);
	++size;
}

template<typename L>
void Forward_List::List<L>::push_back(L data) {
	if(head == nullptr) {
			head = new Node<L>(data);
	}
	else {
		Node<L>* current = this->head;
		while(current->nextNode != nullptr) {
			current = current->nextNode;
		}
		current->nextNode = new Node<L>(data);
	}
	++size;
}

template <typename L>
void Forward_List::List<L>::removeAt(int index) {
	if(index == 0) {
		pop_front();
	} else if(index == size - 1) {
 		pop_back();
	} else {	
		Node<L>* current = this->head;
		for(int i{}; i < index - 1; ++i) {
			current = current -> nextNode;
		}
		Node<L>*del = current->nextNode;
		current->nextNode = del->nextNode;
		delete del; 
		--size;
	}
}

template <typename L>
int Forward_List::List<L>::getSize() const{
	return this->size;
}

template <typename L>
void Forward_List::List<L>::pop_front() {
	Node<L>* tmp = head;
	head = head->nextNode;
	delete tmp;
	--size;
}

template <typename L>
void Forward_List::List<L>::pop_back() {
	int tmp = size;
	Node<L>* current = head;
	while(tmp != 1) {
		--tmp;
		current = current -> nextNode;
	}
	current -> nextNode = nullptr;
	delete current -> nextNode;
	--size;
}

template <typename L>
void Forward_List::List<L>::insert(L data,int index) {
	if(index == 0) {
		push_front(data);
	} else {
		Node<L>* previous = this->head;
		for(int i{}; i < index-1; ++i) {
			previous = previous->nextNode;
		}
		Node<L>* newNode = new Node<L>(data,previous->nextNode);
		previous->nextNode = newNode;
		++size;
	}
}

template<typename L>
void Forward_List::List<L>::clear() {
	while(size) {
		pop_front();
	}
}

template <typename L>
L& Forward_List::List<L>::operator[](const int index) {
	int count = 0;
	Node<L>* current = this->head;
	while(current != nullptr) {
		if(count == index) {
			return current->nodeData;
		}
		current = current->nextNode;
		++count;
	}
	return current->nodeData;
}