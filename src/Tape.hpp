/**
 * Complejidad Computacional
 * Practica 3 - Turing machine
 * 
 * @author Elías Hernández Abreu
 * @brief Tape declaration
 */

#pragma once

#include <ostream>
#include <string>
#include <vector>

#include "Alphabet.hpp"

class Tape {
public:
    /**
    * Builds a tape with a tape alphabet, blank character and starting string
    * @param alphabet The alphabet
    * @param blank The blank symbol
    * @param starting_string The starting string of the tape
    */
    Tape(const Alphabet<char>& alphabet, char blank, const std::string& starting_string);

    /**
    * Reads a symbol from the tape
    * @param pos The position to read from
    * @returns The symbol read
    */
    char read(int pos) const;

    /**
    * Writes a symbol to the tape
    * @param pos The position to write to
    * @param value The symbol to write
    */
    bool write(int pos, char value);

    /**
    * Prints the tape
    * @param out The output stream
    * @param tape The tape to print
    * @returns The output stream
    */
    friend std::ostream& operator<<(std::ostream& out, const Tape& tape);

private:
    char blank_symbol;
    Alphabet<char> tape_alphabet;
    std::vector<char> positive_tape;
    std::vector<char> negative_tape;
};
