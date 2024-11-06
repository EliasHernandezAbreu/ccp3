/**
 * Complejidad Computacional
 * Practica 3 - Turing machine
 * 
 * @author Elías Hernández Abreu
 * @brief Automaton header
 */

#pragma once

#include <string>
#include <vector>

#include "Alphabet.hpp"
#include "Transition.hpp"

class TuringMachine {
public:

    /**
    * Reads an automaton from a string
    * @param declaration The string with the declaration
    */
    TuringMachine(const std::string& declaration);

private:
    Alphabet<std::string> states;
    Alphabet<char> input_alphabet;
    Alphabet<char> tape_alphabet;
    std::string initial_state;
    char blank_symbol;
    Alphabet<std::string> accepting_states;
    std::vector<Transition> transitions;
};

