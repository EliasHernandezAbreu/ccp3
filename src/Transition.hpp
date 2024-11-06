/**
 * Complejidad Computacional
 * Practica 3 - Turing machine
 * 
 * @author Elías Hernández Abreu
 * @brief Transition declaration
 */

#pragma once

#include <string>

class Transition {
public:
    /**
    * Represents a transition in the turing machine
    * @param declaration The text with the declaration of the transition
    */
    Transition(const std::string& declaration);

    // Get the initial transition state
    std::string get_from_state() const { return from_state; }
    // Get the symbol to read in the transition
    char get_read_symbol() const { return read_symbol; }
    // Get the final state of the transition
    std::string get_to_state() const { return to_state; }
    // Get the written symbol in the transition
    char get_write_symbol() const { return write_symbol; }
    // Get the movement the head does in the transition
    char get_move() const { return move; }

    /**
    * Prints the transition
    * @param out The output stream
    * @param transition The transition to print
    * @returns The same output stream that was given
    */
    friend std::ostream& operator<<(std::ostream& out, const Transition& transition);

private:
    std::string from_state;
    char read_symbol;
    std::string to_state;
    char write_symbol;
    char move; // 'R' or 'L'
};
