#ifndef __SELECTIONSORT_HPP
#define __SELECTIONSORT_HPP

#include "container.hpp"
#include "sort.hpp"

class SelectionSort : public Sort{
private:
public:
    SelectionSort(){}
    void sort(Container* container);
};
#endif
