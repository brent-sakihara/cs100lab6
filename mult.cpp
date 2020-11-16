
#include "arithmetic_operations.hpp"
#include "base.hpp"

double Mult::evaluate() {
	return left->evaluate() * right->evaluate();
}

std::string Mult::stringify() {
	return "(" + left->stringify() + " * " + right->stringify() + ")";
}

