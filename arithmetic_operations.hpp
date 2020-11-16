#ifndef __Arithmetic_Operations_HPP__
#define __Arithmetic_Operations_HPP__

#include "base.hpp"

class Mult : public Base {
    public:
        Mult(Base* leftN, Base* rightN) : Base() {left = leftN; right = rightN; }
        virtual double evaluate();
        virtual std::string stringify();

    private:
	Base* left;
	Base* right;

};


class Div : public Base {
    public:
        Div (Base* leftN, Base* rightN) : Base() {left = leftN; right = rightN; }
        virtual double evaluate();
        virtual std::string stringify();

    private:
	Base* left;
	Base* right;
};


class Add : public Base {
    public:
	Add (Base* leftN, Base* rightN) : Base() {left = leftN, right = rightN; }
        virtual double evaluate();
        virtual std::string stringify();

    private:
	Base* left;
	Base* right;
};


class Sub : public Base {
    public:
        Sub(Base* leftN, Base* rightN) : Base() {left = leftN, right = rightN; }
        virtual double evaluate();
        virtual std::string stringify();
    
    private:
	Base* left;
	Base* right;
};


#endif

