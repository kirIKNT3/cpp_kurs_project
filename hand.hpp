#ifndef KURS_HAND_HPP
#define KURS_HAND_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include "card.hpp"

class Hand {
public:
  Hand(const int);

  std::vector<std::shared_ptr<Card>> cards_;
  void addCard(const int);
  void addTwoCard(const int, const int);
  void clearHand();
  int getPriority();
  int getBet(const int);

  int x_;
  int y_;

  int points_;
  int bet_;

  bool insurance;

  ~Hand() = default;

private:
  int count_;
  int countT_;
};


#endif
