#pragma once
#ifndef player_h
#define player_h
#include "stdafx.h"
#include <string>
#include <iostream>
#include "randgen.h"
#include "hand.h"



class player {
public:
  //constructors
  player(); //default - fill
  player(int n); //fill with given name

                 //functions
  int fillHand(deck d, int n);
  void showHand();
  
  int score;
  std::string name;
  hand pHand;

private:


};

player::player() {
  name = "player";
  score = 0;
}

player::player(int n) {
  score = 0;
}

int player::fillHand(deck d, int n) {
  int r = pHand.fillHand(d, n);
  return r;
}

void player::showHand() {
  
}

#endif
