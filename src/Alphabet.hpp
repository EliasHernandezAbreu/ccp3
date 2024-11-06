#pragma once

#include <set>

template <class T>
class Alphabet {
public:
    void add(T letter) {
        letters.insert(letter);
    }

    bool has(T letter) const {
        return letters.find(letter) != letters.end();
    }

    typename std::set<T>::iterator begin() const { return letters.begin(); }
    typename std::set<T>::iterator end() const { return letters.end(); }
    

private:
    std::set<T> letters;
};
