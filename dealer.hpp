#ifndef KURS_DEALER_HPP
#define KURS_DEALER_HPP

#include <vector>
#include <memory>
#include "card.hpp"

class Dealer {
public:
  Dealer();

  std::vector<std::shared_ptr<Card>> cards_;
  void addCard(const int);
  void addTwoCard(const int, const int);
  int getPriority();
  void clearDealer();

  const int x_ = 700;
  const int y_ = 100;

  int points_;
  bool begin_;

  ~Dealer() = default;

private:
  int count_;
  int countT_;
};

#endif