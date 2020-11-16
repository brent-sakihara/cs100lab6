#include "arithmetic_operations.hpp"
#include "base.hpp"

double Sub::evaluate(){
	return left->evaluate() - right->evaluate();
}

std::string Sub::stringify(){
	return "(" + left->stringify() + " - " + right->stringify() + ")"; 
}

