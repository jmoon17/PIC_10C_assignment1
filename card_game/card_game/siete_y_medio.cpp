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
bool readResponse();

// Non member functions implementations (if any)
//bool readResponse() {
//    bool isYes = true;
//    string answer;
//    // Make a variable to help figure out if the input from user is good
//    bool isGoodInput = false; // assume NOT good to start
//    while (!isGoodInput) {
//        cout << "Do you want another card (y/n)? ";
//        cin >> answer;
//
//        if (answer == "y" || answer == "Y") {
//            isYes = true;
//            isGoodInput = true;
//        }
//
//        else if (answer == "n" || answer == "N") {
//            isYes = false;
//            isGoodInput = true;
//        }
//
//        else {
//            // Ask again because the input is wrong
//            isGoodInput = false;
//        }
//    }
//    return isYes;
//}

// Stub for main
int main()
{
    srand((int)(time(0)));
    
    Player p(100);
    int bet;
    bool yesOrno = true;
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


    }
    cout << "You have $0. GAME OVER!" <<"\n";
    cout << "Comeback when you have more money." << "\n";
    cout << "Bye!" <<endl;
    
    return 0;
}


