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
void dTurn(player P, player De, card & topCard, int & turn, int & cCard, deck & D);  //dealerTurn
void printPHand(player P);
void printDHand(player De);
void printTopCard(card & topCard);

int main() {
  int turn = 0;     //0 or 1 if player or dealer's turn
  int cCard = 0;   //numbered position of current card in deck
  int winner = 0; //1 if there is a winner, tested every single time
  card topCard;    //top card that is displayed and plays are tested against
  player Player;
  player Dealer;
  deck D;
  D.shuffle(52);
  cCard = Player.pHand.fillPHand(D, cCard);  //returns current position in deck
  cCard = Dealer.pHand.fillDHand(D, cCard);  //so we can continue where we left off with topcard
  cCard++;
  topCard = D.dCards[cCard];    //top card is equal to next card in the deck


  do {
    if (turn == 0) {   //player
      printGame(Player, Dealer, topCard);
      pTurn(Player, Dealer, topCard, turn, cCard, D);
    }
    else if (turn ==1) {    //dealer
      printDHand(Dealer);
      printTopCard(topCard);
      dTurn(Player, Dealer, topCard, turn, cCard, D);
    }
  } while (winner == 0);

  if (winner == 1) {
    std::cout << "someone won the game!";
  }
  
  
  return 0;
}

void printTopCard(card & topCard) {
  std::cout << topCard.printArt(topCard) << "\n" << "\n";   //print art of top card and player card header
}

void printPHand(player P) {
  std::cout << "Player\n" << P.pHand.nHandCards;
  for (int i = 0; i < P.pHand.nHandCards; i++) {    //output player's hand of cards as two character strings - value and suit
    std::cout << P.pHand.hCards[i].toStr() << "   ";
  }
  std::cout << "\n";
}

void printDHand(player De) {
  std::cout << "Dealer\n";
  for (int i = 0; i < De.pHand.nHandCards; i++) {   //loop and output a question mark for each card in the hand
    std::cout << "  ?  ";
  }
  std::cout << "\n";
}

void printGame(player P, player De, card & topCard) {
                                             //print out name of game, dealer name, and dealer cards, formatted as a 
  std::cout << "Crazy Eights\n" << "\n";      //number of question marks so you can't see what cards the dealer has
  printDHand(De);
  printTopCard(topCard);
  printPHand(P);

  std::cout << "\n" << "\n";
  
}

void pTurn(player P, player De, card & topCard, int & turn, int & cCard, deck & D) {

  std::string play="";                                    //used to get input from user in form of a string - two characters for a card or "draw"

  std::cout << "Type in the card you would like to play, or type \"draw\" to add a card to your hand\n";

  std::getline(std::cin, play);

  //get input from user and test
  if (play == "draw") {
    cCard++;
    P.pHand.nHandCards++;
    P.pHand.addCard(D.dCards[cCard]);
    
    system("CLS");
    printGame(P, De, topCard);
    pTurn(P, De, topCard, turn, cCard, D);

  }
  else {
    for (int i = 0; i < P.pHand.nHandCards; i++) {
      if (play == P.pHand.hCards[i].toStr()) {
        if (P.pHand.hCards[i].getSuit() == topCard.getSuit() || P.pHand.hCards[i].getValue() == topCard.getValue()) {
          topCard = P.pHand.hCards[i];
          P.pHand.remCard(P.pHand.hCards[i], i);
          break;
        }
      }
    }
  }
}

void dTurn(player P, player De, card & topCard, int & turn, int & cCard, deck & D) {
  int match = 0;
  int i = 0;
  std::cout << "\n" << "\n";
  do {
    do {
      if (De.pHand.hCards[i].getSuit() == topCard.getSuit() || De.pHand.hCards[i].getValue() == topCard.getValue()) {
          topCard = De.pHand.hCards[i];
          De.pHand.remCard(De.pHand.hCards[i], i);
            match = 1;
            std::cout << "match";
            break;
         }
      i++;
    } while (i < De.pHand.nHandCards);
      if (match == 0) {
        De.pHand.nHandCards++;
        cCard++;
        De.pHand.addCard(D.dCards[cCard]);

        
      }
  } while (match == 0);



  turn = 0;
  std::cout << "\n";
  system("Pause");
  system("CLS");
}