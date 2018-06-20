# PIC_10C_assignment1

/*****************************
*******GAME DESCRIPTION*******
*****************************/

Seven and a Half is a gambling game that is popular in Italy (as Sette e Mezzo), in Spain (as Siete y Media) in Brazil (as Sete e Meio) and probably in other places as well. In Italy it is traditionally played around Christmas. The objective is to collect cards that total as near as possible to 7½ without exceeding that number. 

A 40-card pack is used. It is possible to use a standard 52-card pack from which the 8's, 9's and 10's have been removed, but in Spain and parts of Italy it is customary to use a Latin-suited 40-card pack, with suits of Coins, Cups, Clubs and Swords. In any case, each suit consists of A, 2, 3, 4, 5, 6, 7 and three picture cards worth. The point values of the cards are:

Aces:	1 point each

2 to 7:	Face value

Picture cards:	Half a point each


The number of players is limited only by the size of the pack and the number of seats that can be fitted around the table. Deal and play are counter-clockwise.

/*****************************
*******EXAMPLE OF PLAYS*******
*****************************/

You have $100.         Enter the bet: 10

Your cards:     Rey de espadas (King of spades)

Your total is 0.5

Do you want another card (y/n)? y

New card: 

    Tres de espadas (Three of spades)
    
Your cards: 

    Rey de espadas (King of spades)
    Tres de espadas (Three of spades)
    
Your total is 3.5

Do you want another card (y/n)? n

Dealer's cards: 

    Sota de espadas (Jack of spades)
    
The dealer's total is 0.5.

New card: 

    Siete de copas (Seven of cups)
    
Dealer's cards: 

    Sota de espadas (Jack of spades)
    Siete de copas (Seven of cups)
    
The dealer's total is 7.5.

Too bad. You lose $10.

You have $90.



/*****************************
*******SOURCE FILES***********
*****************************/

cards.h: declaration of card class, hand class, player class

cards.cpp: implementation of card class, hand class, player class

siete_y_medio.cpp: declaration and implementation of non-member function checkWinner(), and implementation of actual game.



