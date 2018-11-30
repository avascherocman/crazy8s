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

void printGame(player P, player D, card & cCards);

int main() {
  int cCard = 0;
  card topCard;
  player Player;
  player Dealer;
  deck D;
  D.shuffle(52);
  cCard = Player.fillHand(D, cCard);
  cCard = Dealer.fillHand(D, cCard);
  topCard = D.dCards[cCard];
  printGame(Player, Dealer, topCard);
  
  
  system("Pause");


  return 0;
}

void printGame(player D, player P, card & topCard) {
  std::cout << "Crazy Eights\n" << "\n";
  std::cout << "Dealer\n";
  char box = 3;
  std::cout << "  ?  "  <<"  ?  "  << "  ?  "   << "  ?  "  << "  ?  "  << "  ?  " << "  ?  "  << "  ?  "  <<"\n"<<"\n";
  std::cout << topCard.printArt(topCard) << "\n" << "\n" << "Player\n"<<"  ";
  for (int i = 0; i < P.pHand.nHandCards; i++) {
    std::cout << P.pHand.hCards[i].toStr() << "   ";
  }
  std::cout << "\n" <<"\n"<< "Type in the card you would like to play, or type \"draw\" to add a card to your hand\n";

}
