//
//  main.cpp
//  card_game
//
//  Created by Johan Moon on 6/10/18.
//  Copyright © 2018 Johan Moon. All rights reserved.
//
#include "cards.h"
#include <cstdlib>
#include <iostream>

/*
 You might or might not need these two extra libraries
 #include <iomanip>
 #include <algorithm>
 */


/* *************************************************
 Card class
 ************************************************* */

/*
 Default constructor for the Card class.
 It could give repeated cards. This is OK.
 Most variations of Blackjack are played with
 several decks of cards at the same time.
 */
Card::Card(){
    int r = 1 + rand() % 4;
    switch (r) {
        case 1: suit = OROS; break;
        case 2: suit = COPAS; break;
        case 3: suit = ESPADAS; break;
        case 4: suit = BASTOS; break;
        default: break;
    }
    
    r = 1 + rand() % 10;
    switch (r) {
        case  1: rank = AS; break;
        case  2: rank = DOS; break;
        case  3: rank = TRES; break;
        case  4: rank = CUATRO; break;
        case  5: rank = CINCO; break;
        case  6: rank = SEIS; break;
        case  7: rank = SIETE; break;
        case  8: rank = SOTA; break;
        case  9: rank = CABALLO; break;
        case 10: rank = REY; break;
        default: break;
    }
}

// Accessor: returns a string with the suit of the card in Spanish
string Card::get_spanish_suit() const {
    string suitName;
    switch (suit) {
        case OROS:
            suitName = "oros";
            break;
        case COPAS:
            suitName = "copas";
            break;
        case ESPADAS:
            suitName = "espadas";
            break;
        case BASTOS:
            suitName = "bastos";
            break;
        default: break;
    }
    return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish
string Card::get_spanish_rank() const {
    string rankName;
    switch (rank) {
        case AS:
            rankName = "As";
            break;
        case DOS:
            rankName = "Dos";
            break;
        case TRES:
            rankName = "Tres";
            break;
        case CUATRO:
            rankName = "Cuatro";
            break;
        case CINCO:
            rankName = "Cinco";
            break;
        case SEIS:
            rankName = "Seis";
            break;
        case SIETE:
            rankName = "Siete";
            break;
        case SOTA:
            rankName = "Sota";
            break;
        case CABALLO:
            rankName = "Caballo";
            break;
        case REY:
            rankName = "Rey";
            break;
        default: break;
    }
    return rankName;
}



// Accessor: returns a string with the suit of the card in English
// This is just a stub! Modify it to your liking.
string Card::get_english_suit() const {
    string eng_suitName;
    switch (suit){
        case OROS:
            eng_suitName = "coins";
            break;
        case COPAS:
            eng_suitName = "cups";
            break;
        case ESPADAS:
            eng_suitName = "swords";
            break;
        case BASTOS:
            eng_suitName = "clubs";
            break;
        default: break;
    }
    return eng_suitName;
}


// Accessor: returns a string with the rank of the card in English
// This is just a stub! Modify it to your liking.
string Card::get_english_rank() const {
    string eng_rank;
    switch (rank) {
        case AS:
            eng_rank = "Ace";
            break;
        case DOS:
            eng_rank = "Two";
            break;
        case TRES:
            eng_rank = "Three";
            break;
        case CUATRO:
            eng_rank = "Four";
            break;
        case CINCO:
            eng_rank = "Five";
            break;
        case SEIS:
            eng_rank = "Six";
            break;
        case SIETE:
            eng_rank = "Seven";
            break;
        case SOTA:
            eng_rank = "Jack";
            break;
        case CABALLO:
            eng_rank = "Horse";
            break;
        case REY:
            eng_rank = "King";
            break;
        default: break;
            
    }
    return eng_rank;
}

void Card::draw_card() const
{
    //spanish version
    cout << "\t" << get_spanish_rank() << " de " << get_spanish_suit();
    //english version
    cout << " (" << get_english_rank() << " of " << get_spanish_suit() << ")." << endl;
    
}


// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
    return static_cast<int>(rank) + 1 ;
}

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
    return rank < card2.rank;
}




/* *************************************************
 Hand class
 ************************************************* */
// Implemente the member functions of the Hand class here.

//Default constructor
Hand::Hand()
{
    now = vector<Card>();
    currentSum = 0;
}

//pushback Card C decks to current hand
void Hand::add_card(Card c)
{
    now.push_back(c);
}

//compute the value of the card by ranking
void Hand::add_total(double val)
{
    if(val > 7)     //if ranking is above 7, add 0.5 to currentSum
        currentSum += 0.5;
    else            // if not, add currentSum based on the ranking of the card
        currentSum += val;
    
}

//reset hand to zero
void Hand::discard()
{
    currentSum = 0;
}

//print the current cards using draw_card function
void Hand::print_hand()
{
    for(int i=0; i< now.size(); i++)
    {
        now[i].draw_card();
    }
}

//return sum of cards in current hand
double Hand::get_sum()
{
    return currentSum;
}


/* *************************************************
 Player class
 ************************************************* */
// Implemente the member functions of the Player class here.

//constructor
//parameter m is the starting money
Player::Player(int m)
{
    money = m;
}

//accessor
//returns the current budget
int Player::get_money()
{
    return money;
}

//update player's new budget to the private variable
void Player::update_money(int newAmt)
{
    money = newAmt;
}

