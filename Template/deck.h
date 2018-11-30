#pragma once
#ifndef deck_h
#define deck_h
#include "stdafx.h"
#include "randgen.h"
#include "card.h"
#include <string>

class deck {
  friend class hand;
public:
  //constructors
  deck(); //default - fill 52 cards
  deck(int n); //fill - fill that number of cards randomly
          
  void shuffle(int n);
  void printStr(int n);
  void printArt(int n);


private:
  //data
  card dCards[100];

};

deck::deck() {           //52 card fill
  int f = 0;
  while (f < 52) {
    for (int j = 3; j < 7; j++) {
      for (int k = 1; k < 13; k++) {
        dCards[f].setSuit(j);
        dCards[f].setValue(k);
        f++;
      }
    }
  }
}

deck::deck(int n) {    //random fill that number of cards
  RandGen rd;
  int i = 0;
  while (i <n){
    int j = rd.RandInt(3, 6);
    int k = rd.RandInt(1, 12);
    dCards[i].setSuit(j);
    dCards[i].setValue(k);
        i++;
  }
}


void deck::shuffle(int n) {
  int i = 0;
  card temp;
  RandGen r;
  int rand;
  while (i < n) {
    rand = r.RandInt(1, n);
    temp = dCards[i];
    dCards[i] = dCards[rand];
    dCards[rand] = temp;
    i++;
  }
}

void deck::printStr(int n) {
  for (int p = 0; p < n; p++) {
    std::cout << dCards[p].toStr() << std::endl;
  }
}

void deck::printArt(int n) {
  for (int p = 0; p < n; p++) {
    std::cout << dCards[p].printArt(dCards[p]) << std::endl;
  }
}

#endif