#pragma once

#include <string>

class Transition {
public:
    Transition(const std::string& declaration);

    std::string get_from_state() const { return from_state; }
    char get_read_symbol() const { return read_symbol; }
    std::string get_to_state() const { return to_state; }
    char get_write_symbol() const { return write_symbol; }
    char get_move() const { return move; }

    friend std::ostream& operator<<(std::ostream& out, const Transition& transition);

private:
    std::string from_state;
    char read_symbol;
    std::string to_state;
    char write_symbol;
    char move; // 'R' or 'L'
};
