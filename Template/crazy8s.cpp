/* Ava Scherocman
Crazy 8s Project
11/24/18
*/
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include "card.h"
#include "deck.h"
#include "hand.h"
#include "player.h"

card pPlay();
card dPlay();

int main() {
  int cCard = 0;
  card topCard;
  player Player;
  player Dealer;
  deck D;
  D.shuffle(52);
  Player.fillHand(D, cCard);
  Dealer.fillHand(D, cCard);
  Player.showHand();



  return 0;
}

