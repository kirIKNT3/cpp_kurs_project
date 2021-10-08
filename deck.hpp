#ifndef KURS_DECK_HPP
#define KURS_DECK_HPP


#include <vector>

class Deck {
public:
  Deck();

  int getCard();
  void collectDeck();
  void mixDeck();


  ~Deck() = default;
private:
  std::vector<int> deck_;
  std::vector<int> deckReturn_;
};


#endif
