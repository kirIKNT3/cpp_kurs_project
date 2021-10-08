#include <numeric>
#include "dealer.hpp"

Dealer::Dealer():
count_(0),
points_(0),
begin_(true),
countT_(0)
{

}

void Dealer::addCard(const int nCard)
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

void Dealer::addTwoCard(const int c1, const int c2)
{
  this->addCard(c1);
  this->addCard(c2);
}

void Dealer::clearDealer()
{
  count_ = 0;
  points_ = 0;
  begin_ = true;
  countT_ = 0;
  cards_.clear();
}

int Dealer::getPriority()
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
