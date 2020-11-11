#include "arithmetic_operations.hpp"
#include "base.hpp"

double Add::evaluate(){
	return left->evaluate() + right->evaluate();
}

std::string Add::stringify(){
	return "(" + left->stringify() + " + " + right->stringify() + ")";
}

