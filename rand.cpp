#include "op.hpp"

double Rand::evaluate() {
        return random;
}

std::string Rand::stringify() {
        return std::to_string(random);
}

