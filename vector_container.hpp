#ifndef VECTOR_CONTAINER_HPP
#define VECTOR_CONTAINER_HPP

#include "container.hpp"
#include "base.hpp"
#include "sort.hpp"
#include <vector>

using namespace std;

//class Sort;
//class Base;

class vectorContainer: public Container {
    public:
	vectorContainer() : Container() {
	   totalExpression = "";
	};
	vectorContainer(Sort* function) : Container(function) {
	   totalExpression = "";
	};
	Sort* getSortFunction();
	void add_element(Base* element);
	void print();
	void sort();
	void swap(int i, int j);
	Base* at(int i);
	int size();
	string getTotalExpression();

   private:
	vector<Base*> c;
        string totalExpression;
};

#endif
