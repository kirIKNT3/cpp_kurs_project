#include <unistd.h>
#include "game.hpp"

int main()
{
  int stady = 1;
  int commandBut = -1;
  bool reboot = true;
  int num = 0;
  int numBut = 4;
  int account = 10000;

  Dealer dealer;
  Deck deck;
  Hand hand[3] = {Hand(1), Hand(2), Hand(3)};

  sf::Texture texture;
  texture.loadFromFile("image/BJ.png");
  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(0, 0);

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      reboot = true;

      if (event.type == sf::Event::Closed)
        window.close();


      if (event.type == sf::Event::MouseButtonPressed)
      {
        if (stady == 1)
        {
          commandBut = -1;

          for (int i = 0; i != 7; i++)
          {
            if ((sf::Mouse::getPosition(window).x >= 10 + 150 * i) && (sf::Mouse::getPosition(window).x <= 130 + 150 * i) &&
                (sf::Mouse::getPosition(window).y >= 930) && (sf::Mouse::getPosition(window).y <= 960))
            {
              commandBut = i;
              break;
            }
          }

          switch (commandBut)
          {
            case 0:
              if (hand[num].bet_ <= 490 && account >= 10)
              {
                account -= 10;
                hand[num].bet_ += 10;
              }
              break;
            case 1:
              if (hand[num].bet_ <= 480 && account >= 20)
              {
                account -= 20;
                hand[num].bet_ += 20;
              }
              break;
            case 2:
              if (hand[num].bet_ <= 450 && account >= 50)
              {
                account -= 50;
                hand[num].bet_ += 50;
              }
              break;
            case 3:
              if (hand[num].bet_ == 0 && account >= 500)
              {
                account -= 500;
                hand[num].bet_ = 500;
              }
              break;
            case 4:
              account += hand[num].bet_;
              hand[num].bet_ = 0;
              break;
            case 5:
              if (num == 2)
              {
                num = 0;
                while (num != 3 && hand[num].bet_==0)
                {
                  num++;
                }
                if (num == 3)
                {
                  num = 0;
                  break;
                }
                stady ++;
                deck.mixDeck();
                for (int i = 0; i != 3; i++)
                {
                  if (hand[i].bet_ != 0) {
                    hand[i].addTwoCard(deck.getCard(), deck.getCard());
                  }
                }
                dealer.addTwoCard(deck.getCard(), deck.getCard());
                if (dealer.cards_.at(0)->rang_ == 10 && dealer.getPriority() == 22)
                {
                  dealer.begin_ = false;
                  stady = 4;
                }
                else if (dealer.cards_.at(0)->rang_ == 10)
                {
                  stady = 2;
                }
                else if (dealer.cards_.at(0)->rang_ == 11)
                {
                  stady = -1;
                }
              }
              else
              {
                num++;
              }
              break;
            case 6:
              num = 0;
              while (num != 3 && hand[num].bet_==0)
              {
                num++;
              }
              if (num == 3)
              {
                num = 0;
                break;
              }
              stady++;
              deck.mixDeck();
              for (int i = 0; i != 3; i++)
              {
                if (hand[i].bet_ != 0) {
                  hand[i].addTwoCard(deck.getCard(), deck.getCard());
                }
              }
              dealer.addTwoCard(deck.getCard(), deck.getCard());
              if (dealer.cards_.at(0)->rang_ == 10 && dealer.getPriority() == 22)
              {
                dealer.begin_ = false;
                stady = 4;
              }
              else if (dealer.cards_.at(0)->rang_ == 10)
              {
                stady = 2;
              }
              else if (dealer.cards_.at(0)->rang_ == 11)
              {
                stady = -1;
              }
              break;
          }
        }
        else if (stady == 2)
        {
          commandBut = -1;

          for (int i = 0; i != numBut; i++)
          {
            if ((sf::Mouse::getPosition(window).x >= 10 + 180 * i) && (sf::Mouse::getPosition(window).x <= 160 + 180 * i) &&
                (sf::Mouse::getPosition(window).y >= 930) && (sf::Mouse::getPosition(window).y <= 960))
            {
              commandBut = i;
              break;
            }
          }

          switch (commandBut)
          {
            case 0:
              numBut = 2;
              if (hand[num].points_ != 21)
              {
                hand[num].addCard(deck.getCard());
              }
              if (hand[num].points_ >= 21)
              {
                numBut = 4;
                num++;
                while ((num != 3 && hand[num].bet_ == 0) || hand[num].points_ == 21)
                {
                  num++;
                }
                if (num == 3)
                {
                  num = 0;
                  stady++;
                  break;
                }
              }
              break;
            case 1:
              numBut = 4;
              num++;
              while ((num != 3 && hand[num].bet_ == 0) || hand[num].points_ == 21)
              {
                num++;
              }
              if (num == 3)
              {
                num = 0;
                stady++;
                break;
              }
              break;
            case 2:
              if (account < hand[num].bet_)
              {
                break;
              }
              if (hand[num].points_ != 21)
              {
                hand[num].addCard(deck.getCard());
                hand[num].bet_ *= 2;
              }
              num++;
              while ((num != 3 && hand[num].bet_ == 0) || hand[num].points_ == 21)
              {
                num++;
              }
              if (num == 3)
              {
                num = 0;
                stady++;
                break;
              }
              break;
            case 3:
              account += hand[num].bet_ / 2;
              hand[num].clearHand();
              num++;
              while ((num != 3 && hand[num].bet_ == 0) || hand[num].points_ == 21)
              {
                num++;
              }
              if (num == 3)
              {
                num = 0;
                stady++;
                break;
              }
              break;
          }
        }
        else if(stady == 4)
        {
          for (int i = 0; i != 3; i++)
          {
            account += hand[i].getBet(dealer.getPriority());
            hand[i].clearHand();
          }

          dealer.clearDealer();
          deck.collectDeck();

          stady = 1;
        }
        else if(stady == -1)
        {
          commandBut = -1;

          for (int i = 0; i != 2; i++)
          {
            if ((sf::Mouse::getPosition(window).x >= 10 + 180 * i) && (sf::Mouse::getPosition(window).x <= 160 + 180 * i) &&
                (sf::Mouse::getPosition(window).y >= 930) && (sf::Mouse::getPosition(window).y <= 960))
            {
              commandBut = i;
              break;
            }
          }

          switch(commandBut)
          {
            case 0:
              if (account < hand[num].bet_ / 2)
              {
                break;
              }
              account -= 0.5 * hand[num].bet_;
              hand[num].bet_ *= 1.5;
              hand[num].insurance = true;
              num++;
              while (num != 3 && hand[num].bet_==0)
              {
                num++;
              }
              break;
            case 1:
              num++;
              while (num != 3 && hand[num].bet_==0)
              {
                num++;
              }
              break;
          }

          if (num == 3)
          {
            if (dealer.getPriority() == 22)
            {
              dealer.begin_ = false;

              stady = -2;
              num = 0;
            }
            else
            {
              num = 0;
              while (num != 3 && hand[num].bet_==0)
              {
                num++;
              }
              for (int i = 0; i != 3; i++)
              {
                if (hand[i].insurance)
                {
                  hand[i].bet_ = hand[i].bet_ / 1.5;
                  hand[i].insurance = false;
                }
              }

              stady = 2;
            }


          }

        }
        else if (stady == -2)
        {
          for (int i = 0; i != 3; i++)
          {
            if (hand[i].insurance)
            {
              account += hand[i].bet_;
            }
            else
            {
              account += hand[i].getBet(dealer.getPriority());
            }

            hand[i].clearHand();
          }

          dealer.clearDealer();
          deck.collectDeck();

          stady = 1;
        }
      }
    }

    if (!reboot) { continue; }

    window.clear();

    window.draw (sprite) ;

    for (Hand h:hand)
    {
      printCards(h);
    }

    printDealer(dealer);
    printAccount(account);
    pointer(num);

    switch (stady)
    {
      case 1:
        buttonCase1();
        break;
      case 2:
        buttonCase2(numBut);
        break;
      case -1:
        buttonCaseInsurance();
        break;
    }

    window.display();

    reboot = false;

    if (stady == 3)
    {
      if (dealer.begin_)
      {
        dealer.begin_ = false;
      }
      else
      {
        if (dealer.points_ < 17)
        {
          dealer.addCard(deck.getCard());
        }
        else
        {
          stady++;
        }
      }
      reboot = true;
      sleep(2);
    }

  }


  return 0;
}