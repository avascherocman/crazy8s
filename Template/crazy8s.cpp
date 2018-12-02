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
void pTurn(player P, card & topCard, int & turn);
void dTurn(player D, card & topCard, int & turn);

int main() {
  int turn = 0;
  int cCard = 0;
  card topCard;
  player Player;
  player Dealer;
  deck D;
  D.shuffle(52);
  cCard = Player.fillHand(D, cCard);
  cCard = Dealer.fillHand(D, cCard);
  topCard = D.dCards[cCard+1];
  printGame(Player, Dealer, topCard);
  
  if (turn == 0) {
    pTurn(Player, topCard, turn);
  }
  else {
    dTurn(Dealer,topCard, turn);
  }
  
  
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

  std::cout << "\n" << "\n";


}

void pTurn(player P, card & topCard, int & turn) {
  for (int i = 0; i < P.pHand.nHandCards; i++) {
    std::cout << P.pHand.hCards[i].toStr() << "   ";
  }
  std::string play;
std::cout<< "Type in the card you would like to play, or type \"draw\" to add a card to your hand\n";
  std::getline(std::cin, play);
  if (play == "draw") {


  }
  else {
    int i = 0;

    do {
      if (play == P.pHand.hCards[i].toStr()) {
        if (P.pHand.hCards[i].getSuit() == topCard.getSuit() || P.pHand.hCards[i].getValue() ==topCard.getValue()) {
          topCard = P.pHand.hCards[i];
          system("CLS");
          std::cout << "Match! Dealer's turn.\n";
          
          break;
        }
      }
      else {
        i++;
      }
    } while (i < P.pHand.nHandCards);
  }
  std::cout << topCard.printArt(topCard);
  turn == 1;
  system("Pause");

}

void dTurn(player D, card & topCard, int & turn) {

}