#ifndef __DECORATOR_HPP__
#define __DECORATOR_HPP__

#include "base.hpp"

class Base;

class Decorator {
    protected:
      Base* value;
    public:
    //Decorator(Base* incoming) {value = incoming ;}
    Decorator() { };
    virtual double evaluate();
    //virtual std::string stringify();

};
    #endif
