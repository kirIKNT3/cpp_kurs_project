#ifndef KURS_CARD_HPP
#define KURS_CARD_HPP

#include <SFML/Graphics.hpp>

class Card {
public:
  Card(const int);

  int rang_;
  int num_;

  ~Card() = default;
};


#endif
