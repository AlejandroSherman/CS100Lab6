#ifndef __BUBBLESORT_HPP
#define __BUBBLESORT_HPP

#include "container.hpp"
#include "sort.hpp"

class Sort;

class BubbleSort : public Sort{
private:
public:
   void sort(Container* container);
};
#endif
