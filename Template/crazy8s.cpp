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
  cCard = Player.fillHand(D, cCard);  //returns current position in deck
  cCard = Dealer.fillHand(D, cCard);  //so we can continue where we left off with topcard
  topCard = D.dCards[cCard + 1];    //top card is equal to next card in the deck
  cCard++;
  
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
  std::cout << "Player\n";
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

  std::string play;   //used to get input from user in form of a string - two characters for a card or "draw"
  std::cout << "Type in the card you would like to play, or type \"draw\" to add a card to your hand\n";
  std::getline(std::cin, play);

  //get input from user and test
  if (play == "draw") {
    P.pHand.nHandCards++;     //add one to number of hand cards
    P.pHand.hCards[P.pHand.nHandCards] = D.dCards[cCard]; //set that position in the array to the next card in the deck
    cCard++;                  //add one to counter for num cards used in the deck
    system("CLS");            //refresh screen so new card will show up
    printGame(P, De, topCard);
    pTurn(P, De, topCard, turn, cCard, D);

  }
  else { //if play is not draw
    int i = 0;
    int match = 0;
    do {
      if (play == P.pHand.hCards[i].toStr()) {    //test if the inputted matches a card in the player's hand
        if (P.pHand.hCards[i].getSuit() == topCard.getSuit() || P.pHand.hCards[i].getValue() == topCard.getValue()) {  //if either the suit or the value of the card matches that of the top card in the pile, it can be played
          topCard = P.pHand.hCards[i];        //top card is now that card in the hand
          for (int k = i; k < P.pHand.nHandCards; k++) {
            P.pHand.hCards[k] = P.pHand.hCards[k + 1];      //move every card back one in the hand so that a card is removed
          }

          system("CLS");
          std::cout << "\nMatch! Dealer's turn.\n";
          match = 1;
          turn = 1;
          break;
        }
      }
      else {    //if the inputted string doesn't match a card in the player's hand
        i++;    //increment i and try again
      }
    } while (i < P.pHand.nHandCards);     //do this until i > number of cards in the hand

    if (match == 0) {
      std::cout << "Not a match. Dealer's turn.\n";       //card inputted is not a match
      turn = 1;
    }
    system("Pause");
  }
}

void dTurn(player P, player De, card & topCard, int & turn, int & cCard, deck & D) {
  int match = 0;
  do {
    std::cout << "\n" << "\n";
    for (int i = 0; i < De.pHand.nHandCards; i++) {
      if (De.pHand.hCards[i].getSuit() == topCard.getSuit() || De.pHand.hCards[i].getValue() == topCard.getValue()) {
        topCard = De.pHand.hCards[i];
        for (int k = i; k < De.pHand.nHandCards; k++) {
          De.pHand.hCards[k] = De.pHand.hCards[k + 1];
          De.pHand.nHandCards--;
          match = 1;
        }
      }

      if (match == 0) {
        De.pHand.nHandCards++;
        De.pHand.hCards[De.pHand.nHandCards] = D.dCards[cCard];
        cCard++;
        
      }
    } 


  } while (match == 0);
  turn = 0;
  std::cout << "\n";
  system("Pause");
  system("CLS");
}