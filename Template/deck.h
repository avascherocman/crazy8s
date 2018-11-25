#pragma once
#ifndef deck_h
#define deck_h
#include "randgen.h"
#include "card.h"
#include <string>
#include <iostream>

class deck {
public:
  //constructors
  deck(); //default - fill 52 dCards
  deck(int n); //fill - fill that number of dCards randomly
          
  void shuffle(int n);
  void printW(int n);
  void printP(int n);


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

deck::deck(int n) {    //random fill that number of dCards
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

void deck::printW(int n) {
  for (int p = 0; p < n; p++) {
  std::cout << dCards[p].toStr() << std::endl;
  }
}

void deck::printP(int n) {
  for (int p = 0; p < n; p++) {
   std::cout << dCards[p].printCard(dCards[p]) << std::endl;
  }
}

#endif