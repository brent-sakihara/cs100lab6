#ifndef __SELECTION_SORT_HPP__
#define __SELECTION_SORT_HPP__

#include "container.hpp"
#include "sort.hpp"

//class Container;

class selectionSort : public Sort{
    public:

        selectionSort() {};

        void sort(Container* container);
};

#endif //__SELECTION_SORT_HPP__

