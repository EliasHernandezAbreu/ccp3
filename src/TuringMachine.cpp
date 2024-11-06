#include <sstream>
#include <string>

#include "TuringMachine.hpp"

TuringMachine::TuringMachine(const std::string& declaration) {
    std::stringstream input_stream(declaration);
}
