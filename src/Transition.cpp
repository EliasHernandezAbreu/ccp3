/**
 * Complejidad Computacional
 * Practica 3 - Turing machine
 * 
 * @author Elías Hernández Abreu
 * @brief Transition definition
 */

#include <sstream>
#include <iostream>
#include <stdexcept>

#include "Transition.hpp"

Transition::Transition(const std::string& declaration) {
    std::stringstream declaration_stream(declaration);
    declaration_stream >> from_state;
    declaration_stream >> read_symbol;
    declaration_stream >> to_state;
    declaration_stream >> write_symbol;
    declaration_stream >> move;

    if (move != 'R' && move != 'L')
        throw std::runtime_error("Move instruction invalid");
}

std::ostream& operator<<(std::ostream& out, const Transition& transition) {
    out << "{" << transition.from_state << " x " << transition.read_symbol << " -> "
              << transition.to_state << ", " << transition.write_symbol << ", " 
              << transition.move << "}";
    return out; 
}

