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
  int fillDHand(deck d, int n);
  int fillPHand(deck d, int n);
  void addCard(card c);
  void remCard(card c, int p);
  void showHand();

  card hCards[50];
  int nHandCards;
private:
  //data


};

hand::hand() {
  nHandCards = 0;
}

int hand::fillPHand(deck d, int n) {
  int i = 0;
  do {
    hCards[i] = d.dCards[i];
    i++;
  } while (i < ( n + 9));
  nHandCards = 8;
  return nHandCards;
}

int hand::fillDHand(deck d, int n) {
  int i = 0;
  int k = 8;
  do {
    hCards[i] = d.dCards[k];
    i++;
    k++;
  } while (i < (8));
  nHandCards = 8;
  return 16;
}

void hand::addCard(card c) {
  //add card into hand from card that was passed in
  nHandCards++;
  hCards[nHandCards] = c;
}

void hand::remCard(card c, int p) {
  if (p == nHandCards) {
    nHandCards--;
  }
  else {
    for (int i = p; i < nHandCards; i++) {
      if (c.toStr() == hCards[i].toStr()) {
        for (int j = i; j < nHandCards; j++) {
          hCards[j] = hCards[j + 1];
        }
        break;
      }
    }
    nHandCards--;
  }
}

void hand::showHand() {
  for (int i = 0; i < nHandCards; i++) {
    std::cout << hCards[i].printArt(hCards[i]);
  }
}
#endif
