/**
 * Complejidad Computacional
 * Practica 3 - Turing machine
 * 
 * @author Elías Hernández Abreu
 * @brief Turing machine definition
 */

#include <regex>
#include <sstream>
#include <string>
#include <iostream>

#include "TuringMachine.hpp"
#include "Tape.hpp"

#define LOG

TuringMachine::TuringMachine(const std::string& declaration) {
    std::stringstream declaration_stream;
    std::regex comment_regex("#.*\\n");
    declaration_stream << std::regex_replace(declaration, comment_regex, "");

    std::string states_line;
    std::string input_alphabet_line;
    std::string tape_alphabet_line;
    std::string initial_state_line;
    std::string blank_symbol_line;
    std::string final_states_line;

    std::getline(declaration_stream, states_line);
    std::getline(declaration_stream, input_alphabet_line);
    std::getline(declaration_stream, tape_alphabet_line);
    std::getline(declaration_stream, initial_state_line);
    std::getline(declaration_stream, blank_symbol_line);
    std::getline(declaration_stream, final_states_line);

    input_alphabet_line.erase(std::remove_if(input_alphabet_line.begin(), input_alphabet_line.end(), ::isspace),
                              input_alphabet_line.end());
    tape_alphabet_line.erase(std::remove_if(tape_alphabet_line.begin(), tape_alphabet_line.end(), ::isspace),
                             tape_alphabet_line.end());
    initial_state_line.erase(std::remove_if(initial_state_line.begin(), initial_state_line.end(), ::isspace),
                             initial_state_line.end());
    blank_symbol_line.erase(std::remove_if(blank_symbol_line.begin(), blank_symbol_line.end(), ::isspace),
                            blank_symbol_line.end());

    std::stringstream states_stream(states_line);
    std::stringstream input_alphabet_stream(input_alphabet_line);
    std::stringstream tape_alphabet_stream(tape_alphabet_line);
    std::stringstream initial_state_stream(initial_state_line);
    std::stringstream blank_symbol_stream(blank_symbol_line);
    std::stringstream final_states_stream(final_states_line);

    std::string tmp_str;
    char tmp_chr;

    while (states_stream >> tmp_str) states.add(tmp_str);
    while (input_alphabet_stream >> tmp_chr) input_alphabet.add(tmp_chr);
    while (tape_alphabet_stream >> tmp_chr) tape_alphabet.add(tmp_chr);
    initial_state_stream >> initial_state;
    blank_symbol_stream >> blank_symbol;
    while (final_states_stream >> tmp_str) final_states.add(tmp_str);

    std::string transition_line;
    while (std::getline(declaration_stream, transition_line)) {
        Transition transition(transition_line);
        transitions.push_back(transition);
    }

    if (!states.has(initial_state))
        throw std::runtime_error("Initial state not in states");
    if (!tape_alphabet.has(blank_symbol))
        throw std::runtime_error("Blank symbol not in tape alphabet");
    if (input_alphabet.has(blank_symbol))
        throw std::runtime_error("Blank symbol is in input alphabet");

    for (std::string final_state : final_states) {
        if (!states.has(final_state))
            throw std::runtime_error("Final state not in states");
    }

    for (char input_symbol : input_alphabet) {
        if (!tape_alphabet.has(input_symbol))
            throw std::runtime_error("Input symbol not in tape alphabet");
    }

    for (Transition tr : transitions) {
        if (!states.has(tr.get_from_state()))
            throw std::runtime_error("Transition initial state not in states");
        if (!states.has(tr.get_to_state()))
            throw std::runtime_error("Transition final state not in states");
        if (!tape_alphabet.has(tr.get_read_symbol()))
            throw std::runtime_error("Read symbol not in tape alphabet");
        if (!tape_alphabet.has(tr.get_write_symbol()))
            throw std::runtime_error("Write symbol not in tape alphabet");
    }


#ifdef LOG
    std::cout << "Reading correct? " << states_stream.eof() << input_alphabet_stream.eof()
              << tape_alphabet_stream.eof() << initial_state_stream.eof()
              << final_states_stream.eof()
              << (blank_symbol_line.size() == 1) << "\n";
    printf("states: [ ");
    for (std::string str : states) printf("%s ", str.c_str());

    printf("]\ninput alphabet: [ ");
    for (char c : input_alphabet) printf("%c ", c);

    printf("]\ntape alphabet: [ ");
    for (char c : tape_alphabet) printf("%c ", c);

    printf("]\ninitial state: %s\n", initial_state.c_str());
    printf("blank symbol: %c\n", blank_symbol);
    printf("final states: [ ");
    for (std::string str : final_states) printf("%s ", str.c_str());

    printf("]\ntransitions: [\n");
    for (Transition t : transitions) std::cout << t << "\n";
    printf("]\n");
#endif
}

bool TuringMachine::run(const std::string& word) const {
    for (char c : word) {
        if (!input_alphabet.has(c)) return false;
    }
    Tape tape(tape_alphabet, blank_symbol, word);
    int head = 0;
    std::string current_state = initial_state;
    char current_read = tape.read(head);
    int tr_index = get_next_transition(current_state, current_read);
    while (tr_index != -1) {
        const Transition& current_transition = transitions[tr_index];
        tape.write(head, current_transition.get_write_symbol());
        head += current_transition.get_move() == 'R' ? 1 : -1;
        current_state = current_transition.get_to_state();
        current_read = tape.read(head);
        tr_index = get_next_transition(current_state, current_read);
    }
    std::cout << tape;
    if (final_states.has(current_state)) return true;
    return false;
}

int TuringMachine::get_next_transition(const std::string& state, char read) const {
    for (int i = 0; i < transitions.size(); i++) {
        if (transitions[i].get_from_state() == state && transitions[i].get_read_symbol() == read)
            return i;
    }
    return -1;
}
