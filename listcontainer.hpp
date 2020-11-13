#ifndef __LISTCONTAINER_HPP__
#define __LISTCONTAINER_HPP__
#include "container.hpp"
#include "sort.hpp"
#include "base.hpp"
#include <list>

class ListContainer : public Container {

public:
	ListContainer() : Container() { };
	ListContainer(Sort* function) : Container(function) { };
	virtual void add_element(Base* element);
	virtual void print();
	virtual void sort();
	virtual void swap(int i, int j);
	virtual Base* at(int i);
	virtual int size();
	Sort* get_sort_function();
private:
	std::list<Base*> listc;

};

#endif
