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
// Check if the user input is y or n
bool readResponse() {
    bool isYes = true;
    string answer;
    // Make a variable to help figure out if the input from user is good
    bool isGoodInput = false; // assume NOT good to start
    while (!isGoodInput) {
        cout << "Do you want another card (y/n)? ";
        cin >> answer;
        
        if (answer == "y" || answer == "Y") {
            isYes = true;
            isGoodInput = true;
        }
        
        else if (answer == "n" || answer == "N") {
            isYes = false;
            isGoodInput = true;
        }
        
        else {
            // Ask again because the input is wrong
            isGoodInput = false;
        }
    }
    return isYes;
}

// Stub for main
int main(){
    /* --STATEMENTS-- */
    return 0;
}
