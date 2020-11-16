#include "selection_sort.hpp"
#include "container.hpp"
#include <iostream>

using namespace std;


void selectionSort::sort(Container* container){
	int first;
	
	for (int i = 0; i < container->size(); ++i){
		first = i;
		for (int j = i + 1; j < container->size(); j++){
			if (container->at(j)->evaluate() < container->at(first)->evaluate())
				first = j;
		}
		container->swap(first, i);
	}
	return; 
};

