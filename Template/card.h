#pragma once
#ifndef card_h
#define card_h
#include "randgen.h"
#include <string>
#include <iostream>

class card {
public:
  //constructors
  card(); //default
  card(int v, int s); //fill

  //functions
  void setValue(int v);
  int getValue();
  void setSuit(int s);
  char getSuit();
  std::string printArt(card &c);
  std::string toStrLet();
  std::string toStr();
 


private:
  //data
  int value; //1 to 12
  int suit; //3 to 6 - hearts, diamonds, clubs, spades

};

card::card() {           //random fill
  RandGen r;
  suit = r.RandInt(3, 6);
  value = r.RandInt(1, 12);

}

card::card(int v, int s) {
  value = v;
  suit = s;                      //fill
}

void card::setValue(int v) {
  value = v;
}

void card::setSuit(int s) {
  suit = s;
}

int card::getValue() {
  return value;
}

char card::getSuit() {
  return suit;
}

std::string card::printArt(card & c){
  std::string s;
  int v = c.getValue();
  std::string val;
  switch (v) {
  default:
    val = std::to_string(v);
    break;
  case 10:
    val = "J";
    break;
  case 11:
    val = "Q";
    break;
  case 12:
    val = "K";
    break;
  }
  char box = 3;

  s = "    _____       _____ \n   |" + val + "   " + val + "|" +
    "     | "  + box + box + box +  " |\n   |  " + c.toStrLet() + "  |     |" + box + box + box + box + box +
    "|\n   |  " + c.toStrLet() + "  |     |" + box + box + box + box + box + "|  " +
    "\n   |" + val + "___" + val + "|     |" + "_"+box + box + box + "_|\n";
   return s;  
}

std::string card::toStrLet() {
  std::string s;
  switch (suit) {
    case 3:
    s = "H";
    break;
  case 4:
    s = "D";
    break;
  case 5:
    s = "C";
    break;
  case 6:
    s = "S";
    break;
  }
  return s;
}

std::string card::toStr() {
  std::string s = std::to_string(value);
  switch (suit) {
  case 3:
    s += "H";
    break;
  case 4:
    s += "D";
    break;
  case 5:
    s += "C";
    break;
  case 6:
    s += "S";
    break;
  }
  return s;
}

#endif
