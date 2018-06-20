//
//  siete_y_medio.cpp
//  card_game
//
//  Created by Johan Moon on 6/10/18.
//  Copyright © 2018 Johan Moon. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;

// Global constants (if any)

// Non member functions declarations (if any)
int checkWinner(double player, double dealer);

// Non member functions implementations (if any)
int checkWinner(double player, double dealer)
{
    int win = 1;
    int lose = 2;
    int draw = 3;
    
    // Both player and dealer have the same total and neither player busts
    if(dealer == player && (player <= 7.5 && dealer <= 7.5)){
        return draw;
    }
    
    // Else if player's total exceeds 21.
    else if( player > 7.5){
        return lose;
    }
    
    // else if player comes closer to 21
    else if( player <= 7.5) {
        
        // The dealer busts, player wins
        if(dealer >7.5){
            return win;
        }
        
        // The player comes closer to 21 than the dealer
        else if(player >dealer){
            return win;
        }
        
        // The dealer comes closer to 21 than the player
        else if(player < dealer){
            return lose;
        }
    }

    return 0;
}


// Stub for main
int main()
{
    srand((int)(time(0)));
    
    Player p(100);
    int bet;

    string response;
    
    while(p.get_money()>0)
    {
        //run the loop until the bet exceeds current budget
        do{
        cout << "you have: $" <<p.get_money();
        cout << ". Enter bet: ";
        cin >> bet;
        }while(bet > p.get_money());
     
    
        //initiate game
        Hand h;
        h.discard();    //reset
        Card c;
            
        //add card to the hand and compute the total value of the card
        h.add_card(c);
        h.compute_total(c.get_rank());
            
        cout << "your cards: " << "\n" << "\t";
        h.print_hand();
            
        cout << "Your total is " << h.get_sum() <<". ";
        
        do{
            cout << "Do you want another card (y/n)? ";
            cin >> response;
        }   while ((response != "y") && (response != "n"));
        
        while (response == "y")
        {
            Card c2;
            h.add_card(c2);
            
            cout << "New card: " << endl;
            c2.draw_card();
            
            cout << "Your cards: " << endl;
            h.print_hand();
            
            h.compute_total(c2.get_rank());
            cout << "Your total is " << h.get_sum() << endl;
            do{
                cout << "Do you want another card (y/n)? ";
                cin >> response;
            }   while ((response != "y") && (response != "n"));
        }
        
        Hand dealer;
        dealer.discard();   //reset hand
        
        Card d1;
        dealer.add_card(d1);
        dealer.compute_total(d1.get_rank());
        
        cout << "Dealer's card: " << "\n" << "\t";
        dealer.print_hand();
        
        cout << "The dealer's total is " << dealer.get_sum() <<". " <<endl;
        
        while(dealer.get_sum() < 5.5)
        {
            Card d2;
            dealer.add_card(d2);
            dealer.compute_total(d2.get_rank());
            cout << "New card: " << endl;
            d2.draw_card();
            
            cout << "Dealer's card: " << endl;
            dealer.print_hand();

            cout << "Your total is " << dealer.get_sum() << endl;
        }

    }
    cout << "You have $0. GAME OVER!" <<"\n";
    cout << "Comeback when you have more money." << "\n";
    cout << "Bye!" <<endl;
    
    return 0;
}


