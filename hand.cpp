#include <numeric>
#include "hand.hpp"

Hand::Hand(const int number):
x_(385 * number - 50),
y_(500),
points_(0),
count_(0),
bet_(0),
countT_(0),
insurance(false)
{
  if (number != 2)
  {
    y_ -= 50;
  }
}

void Hand::addCard(const int nCard)
{
  cards_.push_back(std::make_shared<Card>(nCard));
  count_ ++;

  if (nCard >= 49)
  {
    countT_++;
  }

  points_ = std::accumulate(cards_.begin(), cards_.end(), 0, [](int sum, std::shared_ptr<Card> card)
  {
    return sum + card->rang_;
  });

  if (points_ > 21)
  {
    points_ -= countT_ * 10;
  }
}

void Hand::addTwoCard(const int c1, const int c2)
{
  this->addCard(c1);
  this->addCard(c2);
}

void Hand::clearHand()
{
  count_ = 0;
  bet_ = 0;
  points_ = 0;
  cards_.clear();
  countT_ = 0;
  insurance = false;
}

int Hand::getPriority()
{
  if (points_ == 21 && count_ == 2)
  {
    return 22;
  }
  else if (points_ > 21)
  {
    return 0;
  }
  else
  {
    return points_;
  }
}

int Hand::getBet(const int d)
{
  const int h = this->getPriority();

  if (h == d)
  {
    return this->bet_;
  }

  if (h > d && h == 22)
  {
    return (this->bet_ * 5 / 2);
  }

  if (h > d)
  {
    return (this->bet_ * 2);
  }

  return 0;
}
