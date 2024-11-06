#include "Alphabet.hpp"

template <class T>
void Alphabet<T>::add(T letter) {
    letters.insert(letter);
}

template <class T>
bool Alphabet<T>::has(T letter) const {
    return letters.find(letter) != letters.end();
}
