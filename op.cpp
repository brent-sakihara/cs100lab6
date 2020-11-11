#include "op.hpp"

double Op::evaluate() {
	return num;
}

std::string Op::stringify() {
	return std::to_string(num);
}
