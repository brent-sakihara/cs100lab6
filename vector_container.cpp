#include "vector_container.hpp"
#include "container.hpp"
#include <vector>
#include <iostream>
#include "base.hpp"
#include "sort.hpp"

using namespace std;

void Container::set_sort_function(Sort* sort_function){
	this->sort_function = sort_function;
};

Sort* vectorContainer::getSortFunction(){
	return sort_function;
}; 

void vectorContainer::add_element(Base* element){
	c.push_back(element);
};

void vectorContainer::print(){
	for (int i = 0; i < c.size(); ++i){
		cout << c.at(i)->stringify() << endl;
		totalExpression += c.at(i)->stringify();
	}
};

void vectorContainer::sort(){
	if (sort_function == nullptr){
		throw runtime_error("Sort function is null");
	}
	else{
		cout << "calls on previously set sorting algorithm";
		sort_function->sort(this);
	}
};	

void vectorContainer::swap(int i, int j){
	if (i < 0 || j < 0 || i >= c.size() || j >= c.size()){
		throw out_of_range("Out of range error");
	}
	else{
		Base* temp = c.at(i);
		c.at(i) = c.at(j);
		c.at(j) = temp;
	}
};

Base* vectorContainer::at(int i){
        if (i < 0 || i >= c.size()){
		throw out_of_range("Out of range error");
	}
	else{
		return c.at(i);
	}
};

int vectorContainer::size(){
	return c.size();
};

string vectorContainer::getTotalExpression(){
	return totalExpression;
};

