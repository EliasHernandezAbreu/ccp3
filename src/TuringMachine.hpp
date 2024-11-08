/**
 * Complejidad Computacional
 * Practica 3 - Turing machine
 * 
 * @author Elías Hernández Abreu
 * @brief Turing machine header
 */

#pragma once

#include <string>
#include <vector>

#include "Alphabet.hpp"
#include "Transition.hpp"

class TuringMachine {
public:
    /**
    * Reads a turing machine from a string
    * @param declaration The string with the declaration
    */
    TuringMachine(const std::string& declaration);

    /**
    * Runs the turing machine for a word
    * @param word The word tu run for
    * @returns True if the turing machine stops at a final state, false if not
    */
    bool run(const std::string& word) const;

private:
    /**
    * Gets the next transition given a state and a tape read
    * @param state The current state
    * @param read The read symbol in the tape
    * @return The index of the next transition or -1 if not available
    */
    int get_next_transition(const std::string& state, char read) const;

    Alphabet<std::string> states;
    Alphabet<char> input_alphabet;
    Alphabet<char> tape_alphabet;
    std::string initial_state;
    char blank_symbol;
    Alphabet<std::string> final_states;
    std::vector<Transition> transitions;
};

