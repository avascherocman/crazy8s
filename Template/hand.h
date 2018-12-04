#pragma once
#ifndef hand_h
#define hand_h
#include "stdafx.h"
#include <string>
#include "deck.h"
#include <iostream>

class hand {
  friend class deck;
public:
  //constructors
  hand();

  //functions
  int fillHand(deck d, int n);
  void addCard(card c);
  void remCard(card c);
  void showHand();

  card hCards[50];
  int nHandCards;
private:
  //data


};

hand::hand() {
  nHandCards = 0;
}

int hand::fillHand(deck d, int n) {
  //yes, I'm aware this is absolutely horrifying and NOT the way to do it. however, I was having problems with variables
  //incrementing randomly when using a loop. unfortunately this is the only way
  hCards[0] = d.dCards[0];
  hCards[1] = d.dCards[1];
  hCards[2] = d.dCards[2];
  nHandCards = 2;
  return nHandCards;
}

void hand::addCard(card c) {
  //add card into hand from card that was passed in
  nHandCards++;
  hCards[nHandCards] = c;
}

void hand::remCard(card c) {
  for (int i = 0; i < nHandCards; i++) {
    if (c.toStr() == hCards[i].toStr()) {
      for (int j = i; j < nHandCards; j++) {
        hCards[j] = hCards[j + 1];
      }
    }
  }
}

void hand::showHand() {
  for (int i = 0; i < nHandCards; i++) {
    std::cout << hCards[i].printArt(hCards[i]);
  }
}
#endif
