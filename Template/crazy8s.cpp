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

void printGame(player P, player D);

int main() {
  int cCard = 0;
  card topCard;
  player Player;
  player Dealer;
  deck D;
  D.shuffle(52);
  Player.fillHand(D, cCard);
  Dealer.fillHand(D, cCard);
  printGame(Player, Dealer);

  
  system("Pause");


  return 0;
}

void printGame(player D, player P, card & topCard) {
  std::cout << "Crazy Eights\n" << "\n";
  std::cout << "Dealer\n";
  char box = 3;
  std::cout << box << " "<<box <<" "<< box << " " << box<<" " << box<<" " << box <<" "<< box <<" "<< box <<"\n"<<"\n";
  std::cout<<

}
