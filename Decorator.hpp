#ifndef __DECORATOR_HPP__
#define __DECORATOR_HPP__

#include "sort.hpp"
#include "base.hpp"

class Sort;
class Base;

class Decorator {
    protected:
      Base* value;
    public:
    Decorator(Base* incoming) {value = incoming };
    virtual double evaluate();
    virtual  std::string stringify();

};
    #endif
