#include <random>
#include <algorithm>
#include "deck.hpp"


Deck::Deck()
{
  for (int i = 1; i < 53; i++)
  {
    deck_.push_back(i);
  }
}

int Deck::getCard()
{
  const int tmp = *(std::prev(deck_.end()));
  deck_.pop_back();
  deckReturn_.push_back(tmp);

  return tmp;
}

void Deck::mixDeck()
{
  std::random_device rd;
  std::default_random_engine re(rd());

  std::shuffle(deck_.begin(), deck_.end(), re);
}

void Deck::collectDeck()
{
  deck_.reserve(deck_.size()+deckReturn_.size());
  deck_.insert(deck_.end(), deckReturn_.begin(), deckReturn_.end());
  deckReturn_.clear();
}
