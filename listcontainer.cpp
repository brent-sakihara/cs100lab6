#include "listcontainer.hpp"
#include <list>
#include <iostream>
/* Non Virtual Functions */
void Container::set_sort_function(Sort* sort_function) {
	this->sort_function = sort_function;
}

/* Pure Virtual Functions */
// push the top pointer of the tree into container
void ListContainer::add_element(Base* element) {
	listc.push_back(element);
}

// iterate through trees and output the expressions (use stringify())
void ListContainer::print() {
	for (std::list<Base*>::iterator it = listc.begin(); it!= listc.end(); ++it){
		std::cout << (*it)->stringify();
	}
}

// calls on the previously set sorting-algorithm. Checks if sort_function is not
// null, throw exception if otherwise
void ListContainer::sort() {
	if (sort_function == nullptr){
		throw std::runtime_error("sort function is not set");
	}
	else{
		sort_function->sort(this);
	}
}

//switch tree locations
void ListContainer::swap (int i, int j) {
	std::list<Base*>::iterator it = listc.begin();
	advance(it,i);
	std::list<Base*>::iterator it2 = listc.begin();
	advance(it2,j);
	Base* temp = *it;
	*it = *it2;
	*it2 = temp;
}

// get top ptr of tree at index i
Base* ListContainer::at(int i) {
	std::list<Base*>::iterator it = listc.begin();
	advance(it,i);
	return *it;
}

// return container size
int ListContainer::size() {
	return listc.size();
}

Sort* ListContainer::get_sort_function(){
	return sort_function;
}
