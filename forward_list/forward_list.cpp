#include <iostream>
#include "forward_list.h"

int main() {
	Forward_List::List<int> list;
	list.push_front(20);
	list.push_back(10);
	list.removeAt(0);
	// list.insert(15, 0);
	// list.clear();
	for(int i{}; i < list.getSize(); ++i) {
		std::cout << list[i] << std::endl;
	}
}
