#pragma 
#pragma once
#ifndef player_h
#define player_h
#include "randgen.h"
#include "hand.h"
#include <string>
#include <iostream>

class player {
public:
  //constructors
  player(); //default
  player(std::string n); //fill

                //functions
private:
  //data
  hand Hand;
  std::string name;
  int score;

};

player::player() {           //random fill
  name = "Player1";
  score = 0;

}

player::player(std::string n) {
  name = name;
  score = 0;
}


#endif