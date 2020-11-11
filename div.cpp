#include "arithmetic_operations.hpp"

#include "base.hpp"

#include <stdexcept>

double Div::evaluate(){
	if (right->evaluate() == 0.0){
		throw std::runtime_error("Divide by Zero Exception");
	}
	return (left->evaluate() / right->evaluate());
}

std::string Div::stringify(){
	return ("(" + left->stringify() + " / " + right->stringify() + ")");
}

