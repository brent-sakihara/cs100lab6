#include "pow.hpp"
#include <math.h>

double Pow::evaluate() {
	return pow(op->evaluate(), op2->evaluate());
} 

std::string Pow::stringify() {
	std::string result = "(" + op->stringify() + " ** " + op2->stringify() + ")";
	return result;
}
