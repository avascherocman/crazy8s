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
void printGame(player& Player, player & Dealer, card & topCard);
void pTurn(player & Player, player & Dealer, card & topCard, int & turn, int & cCard, deck & D, int & win, player & winner);  //playerTurn
void dTurn(player & Player, player & Dealer, card & topCard, int & turn, int & cCard, deck & D, int & win, player & winner);  //dealerTurn
void printPHand(player & Player);
void printDHand(player &Dealer);
void printTopCard(card & topCard);

int main() {
  int turn = 0;     //0 or 1 if player or dealer's turn
  int cCard = 0;   //numbered position of current card in deck
  int win = 0; //1 if there is a winner, tested every single time
  player winner;
  card topCard;    //top card that is displayed and plays are tested against
  player Player;
  player Dealer;
  deck D;
  D.shuffle(52);
  cCard = Player.pHand.fillPHand(D, cCard);  //returns current position in deck
  cCard = Dealer.pHand.fillDHand(D, cCard);  //so we can continue where we left off with topcard
  cCard++;
  topCard = D.dCards[cCard];    //top card is equal to next card in the deck
  
  if (cCard == 52) {
    D.shuffle(52);
    cCard = 0;
  }
  do {
    if (turn == 0) {   //player
      printGame(Player, Dealer, topCard);
      pTurn(Player, Dealer, topCard, turn, cCard, D, win, winner);
    }
    else if (turn ==1) {    //dealer
      printDHand(Dealer);
      printTopCard(topCard);
      dTurn(Player, Dealer, topCard, turn, cCard, D, win, winner);
    }
  } while (win == 0);

  if (win == 1) {
    if (winner.name == Player.name) {
      std::cout << "you won the game!";
    }
    else {
      std::cout << "the dealer won the game!";
    }

  }
  
  
  return 0;
}

void printTopCard(card & topCard) {
  std::cout << topCard.printArt(topCard) << "\n" << "\n";   //print art of top card and player card header
}

void printPHand(player & Player) {
  std::cout << "Player\n";
  for (int i = 0; i < Player.pHand.nHandCards; i++) {    //output player's hand of cards as two character strings - value and suit
    std::cout << Player.pHand.hCards[i].toStr() << "   ";
  }
  std::cout << "\n";
}

void printDHand(player &Dealer) {
  std::cout << "Dealer\n";
  for (int i = 0; i < Dealer.pHand.nHandCards; i++) {   //loop and output a question mark for each card in the hand
    std::cout << "  ?  ";
  }
  std::cout << "\n";
}

void printGame(player &Player, player& Dealer, card & topCard) {
                                             //print out name of game, dealer name, and dealer cards, formatted as a 
  std::cout << "Crazy Eights\n" << "\n";      //number of question marks so you can't see what cards the dealer has
  printDHand(Dealer);
  printTopCard(topCard);
  printPHand(Player);

  std::cout << "\n" << "\n";
  
}

void pTurn(player & Player, player & Dealer, card & topCard, int & turn, int & cCard, deck & D, int & win, player & winner) {

  std::string play="";                                    //used to get input from user in form of a string - two characters for a card or "draw"

  std::cout << "Type in the card you would like to play, or type \"draw\" to add a card to your hand\n";

  std::getline(std::cin, play);

  //get input from user and test
  if (play == "draw") {
    cCard++;
    Player.pHand.addCard(D.dCards[cCard]);
    
    system("CLS");
    printGame(Player, Dealer, topCard);
    pTurn(Player, Dealer, topCard, turn, cCard, D, win, winner);

  }
  else {
    for (int i = 0; i < Player.pHand.nHandCards; i++) {
      if (play == Player.pHand.hCards[i].toStr()) {
        if (Player.pHand.hCards[i].getSuit() == topCard.getSuit() || Player.pHand.hCards[i].getValue() == topCard.getValue()) {
          topCard = Player.pHand.hCards[i];
          Player.pHand.remCard(Player.pHand.hCards[i], i);
          turn = 1;
          system("CLS");
          if (Player.pHand.nHandCards == 0) {
            win = 1;
            winner.name = "player";
            
          }
          break;
        }
      }
    }
  }
}

void dTurn(player & Player, player & Dealer, card & topCard, int & turn, int & cCard, deck & D, int & win, player & winner) {
  int match = 0;
  int i = 0;
  std::cout << "\n" << "\n";
  do {
    do {
      if (Dealer.pHand.hCards[i].getSuit() == topCard.getSuit() || Dealer.pHand.hCards[i].getValue() == topCard.getValue()) {
          topCard = Dealer.pHand.hCards[i];
          Dealer.pHand.remCard(Dealer.pHand.hCards[i], i);
            match = 1;
            break;
         }
      i++;
    } while (i < Dealer.pHand.nHandCards);
      if (match == 0) {
        Dealer.pHand.nHandCards++;
        cCard++;
        Dealer.pHand.addCard(D.dCards[cCard]);

        
      }
  } while (match == 0);



  turn = 0;
  std::cout << "\n";
  system("Pause");
  system("CLS");
}