#pragma once
#ifndef hand_h
#define hand_h
#include <string>
#include "card.h"
#include "deck.h"
#include <iostream>

class hand {
public:
  //constructors
  hand();

  //functions
  void addCard(card c);
  void remCard(card c);

private:
  //data
  card hCards[50];
  int numCards;

};

hand::hand() {
  for (int i = 0; i < 8; i++) {
    //add cards into hand from deck
  }
}

void hand::addCard(card c) {
  //add card into hand from card that was passed in
  numCards++;
  hCards[numCards] = c;
}

void hand::remCard(card c) {
  for (int i = 0; i < numCards; i++) {
    if (c.toStr() == hCards[i].toStr()) {
      for (int j = i; j < numCards; j++) {
        hCards[j] = hCards[j + 1];
      }
    }
  }
}


#endif
