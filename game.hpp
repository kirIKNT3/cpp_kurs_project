#ifndef KURS_GAME_HPP
#define KURS_GAME_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "deck.hpp"
#include "hand.hpp"
#include "dealer.hpp"

sf::RenderWindow window(sf::VideoMode(1600, 970), "Blackjack");

void pointer(const int n)
{
  sf::CircleShape triangle(30.f, 3);
  triangle.setFillColor(sf::Color::Blue);
  triangle.setPosition(385 * (n + 1), 800);
  window.draw(triangle);
}

void printAccount(const int a)
{
  sf::Font f;
  f.loadFromFile("font.otf");
  sf::Text t;
  t.setFont(f);
  t.setString("Account "+std::to_string(a));
  t.setFillColor(sf::Color::Red);
  t.setCharacterSize(20);
  t.setPosition(1400,930);
  window.draw(t);
}

void printCards(const Hand& h)
{
  sf::Font f;
  f.loadFromFile("font.otf");
  sf::Text point;
  point.setFont(f);
  point.setString(std::to_string(h.points_));
  point.setFillColor(sf::Color::Black);
  point.setCharacterSize(24);
  point.setPosition(h.x_ - 20, h.y_ - 20);

  sf::Text bet;
  bet.setFont(f);
  bet.setString("BET " + std::to_string(h.bet_));
  bet.setFillColor(sf::Color::Black);
  bet.setCharacterSize(24);
  bet.setPosition(h.x_ + 50, h.y_ + 240);

  int dx = 0;
  std::for_each(h.cards_.begin(), h.cards_.end(), [&](std::shared_ptr<Card> c)
  {
    sf::Texture t;
    t.loadFromFile("image/"+std::to_string(c->num_)+".png");
    sf::Sprite k;
    k.setTexture(t);
    k.setPosition(h.x_ + dx, h.y_);
    dx += 30;
    window.draw(k);
  });

  window.draw(point);
  window.draw(bet);
}

void printDealer(const Dealer& d)
{
  if (d.cards_.empty())
  {
    return;
  }

  if (d.begin_)
  {
    sf::Texture firstCard;
    sf::Texture secondCard;
    firstCard.loadFromFile("image/" + std::to_string(d.cards_.at(0)->num_) + ".png");
    secondCard.loadFromFile("image/shirt.png");
    sf::Sprite k;
    k.setTexture(firstCard);
    k.setPosition(d.x_, d.y_);
    window.draw(k);
    k.setTexture(secondCard);
    k.setPosition(d.x_ + 30, d.y_);
    window.draw(k);
    return;
  }


  sf::Font f;
  f.loadFromFile("font.otf");
  sf::Text point;
  point.setFont(f);
  point.setString(std::to_string(d.points_));
  point.setFillColor(sf::Color::Black);
  point.setCharacterSize(24);
  point.setPosition(d.x_ - 20, d.y_ - 20);

  int dx = 0;
  std::for_each(d.cards_.begin(), d.cards_.end(), [&](std::shared_ptr<Card> c)
  {
    sf::Texture t;
    t.loadFromFile("image/"+std::to_string(c->num_)+".png");
    sf::Sprite k;
    k.setTexture(t);
    k.setPosition(d.x_ + dx, d.y_);
    dx += 30;
    window.draw(k);
  });

  window.draw(point);
}

void buttonCase1()
{
  sf::Font font;
  font.loadFromFile("font.otf");
  sf::Text text;
  text.setFont(font);
  text.setCharacterSize(16);
  text.setFillColor(sf::Color::Red);

  sf::RectangleShape r(sf::Vector2f(120, 30));
  r.setFillColor(sf::Color::White);
  for (int i = 0; i != 7; i++)
  {
    r.setPosition(10 + 150 * i, 930);
    window.draw(r);

    switch(i)
    {
      case 0:
        text.setString("10");
        text.setPosition(29 + 150 * i, 935);
        break;
      case 1:
        text.setString("20");
        text.setPosition(29 + 150 * i, 935);
        break;
      case 2:
        text.setString("50");
        text.setPosition(29 + 150 * i, 935);
        break;
      case 3:
        text.setString("500");
        text.setPosition(26 + 150 * i, 935);
        break;
      case 4:
        text.setString("Clear");
        text.setPosition(24 + 150 * i, 935);
        break;
      case 5:
        text.setString("Next");
        text.setPosition(18 + 150 * i, 935);
        break;
      case 6:
        text.setString("Hand out");
        text.setPosition(18 + 150 * i, 935);
        break;
    }

    window.draw(text);
  }
}

void buttonCase2(const int st)
{
  sf::Font font;
  font.loadFromFile("font.otf");
  sf::Text text;
  text.setFont(font);
  text.setCharacterSize(16);
  text.setFillColor(sf::Color::Red);

  sf::RectangleShape r(sf::Vector2f(150, 30));
  r.setFillColor(sf::Color::White);
  for (int i = 0; i != st; i++)
  {
    r.setPosition(10 + 180 * i, 930);
    window.draw(r);

    switch(i)
    {
      case 0:
        text.setString("Hit");
        text.setPosition(60 + 180 * i, 935);
        break;
      case 1:
        text.setString("Stand");
        text.setPosition(56 + 180 * i, 935);
        break;
      case 2:
        text.setString("Double");
        text.setPosition(54 + 180 * i, 935);
        break;
      case 3:
        text.setString("Surrender");
        text.setPosition(38 + 180 * i, 935);
        break;
    }

    window.draw(text);
  }
}

void buttonCaseInsurance()
{
  sf::Font font;
  font.loadFromFile("font.otf");
  sf::Text text;
  text.setFont(font);
  text.setCharacterSize(16);
  text.setFillColor(sf::Color::Red);

  sf::RectangleShape r(sf::Vector2f(150, 30));
  r.setFillColor(sf::Color::White);
  for (int i = 0; i != 2; i++)
  {
    r.setPosition(10 + 180 * i, 930);
    window.draw(r);

    switch(i)
    {
      case 0:
        text.setString("Insurance");
        text.setPosition(40 + 180 * i, 935);
        break;
      case 1:
        text.setString("Skip");
        text.setPosition(56 + 180 * i, 935);
        break;
    }

    window.draw(text);
  }
}

#endif
