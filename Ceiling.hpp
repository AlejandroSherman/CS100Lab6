#ifndef __CEILING_HPP__
#define __CEILING_HPP__

#include "sort.hpp"
#include "base.hpp"
#include "Decorator.hpp"


class Sort;
class Base;

class Ceil : Decorator {
    protected:
    public:
    Ceil () : Decorator(Base*);
    double evaluate(){return ceil(value->evaluate())};

};
    #endif
