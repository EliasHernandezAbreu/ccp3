#pragma once

#include <set>

template <class T>
class Alphabet {
public:
  void add(T letter);
  bool has(T letter) const;
private:
    std::set<T> letters;
};
