/**
 * Complejidad Computacional
 * Practica 3 - Turing machine
 * 
 * @author Elías Hernández Abreu
 * @brief Tape definition
 */

#include "Tape.hpp"

Tape::Tape(const Alphabet<char>& alphabet, char blank, const std::string& starting_string) {
    blank_symbol = blank;
    tape_alphabet = alphabet;
    positive_tape.resize(starting_string.size());
    for (int i = 0; i < starting_string.size(); i++) {
        positive_tape[i] = starting_string[i];
    }
}

char Tape::read(int pos) const {
    int index = pos;
    bool is_negative = false;
    if (pos < 0) {
        index = 1 - pos;
        is_negative = true;
    }
    if (is_negative) {
        if (negative_tape.size() <= index) return blank_symbol;
        return negative_tape[index];
    } else {
        if (positive_tape.size() <= index) return blank_symbol;
        return positive_tape[index];
    }
}

bool Tape::write(int pos, char value) {
    if (!tape_alphabet.has(value)) return false;
    int index = pos;
    bool is_negative = false;
    if (pos < 0) {
        index = 1 - pos;
        is_negative = true;
    }
    if (is_negative) {
        if (negative_tape.size() <= index) {
            negative_tape.resize(index + 1);
        }
        negative_tape[index] = value;
    } else {
        if (positive_tape.size() <= index) {
            positive_tape.resize(index + 1);
        }
        positive_tape[index] = value;
    }
    return true;
}

std::ostream& operator<<(std::ostream& out, const Tape& tape) {
    out << '|';
    for (int i = tape.negative_tape.size() - 1; i >= 0; i--) {
        out << tape.negative_tape[i];
    }
    for (int i = 0; i < tape.positive_tape.size(); i++) {
        out << tape.positive_tape[i];
    }
    out << '|';
    return out;
}
