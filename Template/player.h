#pragma once
#ifndef player_h
#define player_h
#include "stdafx.h"
#include <string>
#include <iostream>
#include "randgen.h"
#include "deck.h"
#include "hand.h"
#include "card.h"


class player {
  friend class hand;
  friend class card;
  friend class deck;
public:
  //constructors
  player(); //default - fill
  player(int n); //fill with given name

  //functions
  int fillHand(deck d, int n);

private:
  int score;
  std::string name;
  hand pHand;
};

player::player() {         
  name += "player";
  score = 0;
}

player::player(int n) {    
  score = 0;
}

int player::fillHand(deck d, int n) {
  int r = pHand.fillHand(d, n);
  return r;
}


#endif

/*#pragma once
#ifndef player_h
#define player_h
#include "stdafx.h"
#include "randgen.h"
#include "hand.h"
#include "deck.h"
#include <string>
#include <iostream>

class player {
public:
  //constructors
  player(); //default
  player(std::string n); //fill

                         //functions
  int fillHand(deck d, int n);

private:
  friend class hand;
  friend class deck;
  //data
  hand pHand;
  std::string name;
  int score;

};

player::player() {           //random fill
  name = "Player1";
  score = 0;

}

player::player(std::string n) {
  name = n;
  score = 0;
}

int player::fillHand(deck d, int n) {
  int r = pHand.fillHand(d, n);
  return r;
}
#endif*/