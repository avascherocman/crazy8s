/* Ava Scherocman
Crazy 8s Project
11/24/18
*/
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include "card.h"         //card, deck, hand, and player also made by me
#include "deck.h"
#include "hand.h"
#include "player.h"

//function prototypes
void printGame(player P, player De, card & topCard);
void pTurn(player P, player De, card & topCard, int & turn, int & cCard, deck & D);  //playerTurn
void dTurn(player D, card & topCard, int & turn);  //dealerTurn

int main() {
  int turn = 0;     //0 or 1 if player or dealer's turn
  int cCard = 0;   //numbered position of current card in deck
  card topCard;    //top card that is displayed and plays are tested against
  player Player;  
  player Dealer;
  deck D;
  D.shuffle(52);
  cCard = Player.fillHand(D, cCard);  //returns current position in deck
  cCard = Dealer.fillHand(D, cCard);  //so we can continue where we left off with topcard
  topCard = D.dCards[cCard+1];    //top card is equal to next card in the deck
  cCard++;
  printGame(Player, Dealer, topCard); 
  
  if (turn == 0) {   //player
    pTurn(Player, Dealer, topCard, turn, cCard, D);
  }
  else {    //dealer
    dTurn(Dealer,topCard, turn);
  }
  
  
  return 0;
}

void printGame(player P, player De, card & topCard) {
 

                                            //print out name of game, dealer name, and dealer cards, formatted as a 
  std::cout << "Crazy Eights\n" << "\n";      //number of question marks so you can't see what cards the dealer has
  std::cout << "Dealer\n";

  for (int i = 0; i < De.pHand.nHandCards; i++) {   //loop and output a question mark for each card in the hand
    std::cout << "  ?  ";
  }
  std::cout <<"\n"<<"\n";
  std::cout << topCard.printArt(topCard) << "\n" << "\n" << "Player\n"<<"  ";   //print art of top card and player card header

}

void pTurn(player P, player De, card & topCard, int & turn, int & cCard, deck & D) {
  for (int i = 0; i < P.pHand.nHandCards; i++) {    //output player's hand of cards as two character strings - value and suit
    std::cout << P.pHand.hCards[i].toStr() << "   ";
  }
  std::cout << "\n" << "\n";

  std::string play;   //used to get input from user in form of a string - two characters for a card or "draw"
  std::cout<< "Type in the card you would like to play, or type \"draw\" to add a card to your hand\n";
  std::getline(std::cin, play);
  if (play == "draw") {           //get input from user and test
    P.pHand.nHandCards++;
    P.pHand.hCards[P.pHand.nHandCards] = D.dCards[cCard];
    cCard++;
    system("CLS");
    printGame(P, De, topCard);
    pTurn(P, De, topCard, turn, cCard, D);

  }
  else {
    int i = 0;
    int match = 0;
    do {
      if (play == P.pHand.hCards[i].toStr()) {
        if (P.pHand.hCards[i].getSuit() == topCard.getSuit() || P.pHand.hCards[i].getValue() ==topCard.getValue()) {
          topCard = P.pHand.hCards[i];
          for (int k = i; k < P.pHand.nHandCards; k++) {
            P.pHand.hCards[k] = P.pHand.hCards[k + 1];
          }

          system("CLS");
          for (int i = 0; i < P.pHand.nHandCards; i++) {
            std::cout << P.pHand.hCards[i].toStr() << "   ";
          }
          std::cout << "\nMatch! Dealer's turn.\n";
          match = 1;
          break;
        }
      }
      else {
        i++;
      }
    } while (i < P.pHand.nHandCards);
    if (match == 0){
      std::cout << "Not a match. Dealer's turn.\n";
      for (int i = 0; i < P.pHand.nHandCards; i++) {
        std::cout << P.pHand.hCards[i].toStr() << "   ";
      }
    }
  }
  std::cout << topCard.printArt(topCard);
  turn = 1;
  system("Pause");

}

void dTurn(player D, card & topCard, int & turn) {

}