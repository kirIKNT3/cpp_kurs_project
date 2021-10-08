#include <cmath>
#include "card.hpp"

Card::Card(const int n):
num_(n)
{
  if (n < 37)
  {
    rang_ = std::trunc((n - 1) / 4) + 2;
  }
  else if (n < 49)
  {
    rang_ = 10;
  }
  else
  {
    rang_ = 11;
  }
}
