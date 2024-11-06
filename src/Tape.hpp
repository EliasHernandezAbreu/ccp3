#pragma once

#include <ostream>
#include <string>
#include <vector>

#include "Alphabet.hpp"

class Tape {
public:
    Tape(const Alphabet<char>& alphabet, char blank, const std::string& starting_string);

    char read(int pos) const;
    bool write(int pos, char value);

    friend std::ostream& operator<<(std::ostream& out, const Tape& tape);
private:
    char blank_symbol;
    Alphabet<char> tape_alphabet;
    std::vector<char> positive_tape;
    std::vector<char> negative_tape;
};
