#pragma once

#include <string>

#include "Movement.hpp"

class Transition {
private:
    std::string from_state;
    char read_symbol;
    char write_symbol;
    std::string to_state;
    Movement move;
};
