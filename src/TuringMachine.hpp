/**
 * Complejidad Computacional
 * Practica 3 - Turing machine
 * 
 * @author Elías Hernández Abreu
 * @brief Automaton header
 */

#pragma once

#include <set>
#include <string>
#include <vector>
#include "Transition.hpp"

class TuringMachine {
public:

    /**
    * Reads an automaton from a string
    * @param declaration The string with the declaration
    */
    TuringMachine(const std::string& declaration);

private:
    std::set<std::string> states;
    std::set<char> input_alphabet;
    std::set<char> tape_alphabet;
    std::string initial_state;
    char blank_symbol;
    std::set<std::string> accepting_states;
    std::vector<Transition> transitions;
};

