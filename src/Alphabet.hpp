/**
 * Complejidad Computacional
 * Practica 3 - Turing machine
 * 
 * @author Elías Hernández Abreu
 * @brief Alphabet declaration and definition (templates are funny)
 */

#pragma once

#include <set>

template <class T>
class Alphabet {
public:
    /**
    * Adds a letter to the alphabet
    * @param letter The letter to add
    */
    void add(T letter) {
        letters.insert(letter);
    }

    /**
    * Checks if the alphabet has a letter
    * @param letter The letter to check
    * @returns True if it has it, false if not
    */
    bool has(T letter) const {
        return letters.find(letter) != letters.end();
    }

    /**
    * Returns the begin iterator (for the for_each loop)
    * @returns The begin iterator
    */
    typename std::set<T>::iterator begin() const { return letters.begin(); }

    /**
    * Returns the end iterator (for the for_each loop)
    * @returns The end iterator
    */
    typename std::set<T>::iterator end() const { return letters.end(); }
    

private:
    std::set<T> letters;
};
