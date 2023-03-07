// Munoz_Assignment7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <ctime>
#include <string>
#include <iomanip>
#include "Coin.h"
#include "Quarter.h"
#include "Nickel.h"
#include "Dime.h"
using namespace std;

double Coin::balance = 0.00;//Initializes static balance field in class Coin to 0.00
void evaluateToss(Coin* coin);//Prototype 
const double WinningBalance = 1.00;//constant variable to set the winning value

int main()
{
	srand(time(0));//Need this in order to be able to use random #

	//Instances of each child class
	Quarter quarter;
	Nickel nickel;
	Dime dime;

	//Call the class name(COIN) where my static function is, by using Coin:: and then add the function that you need
	cout << setprecision(2) << fixed;
	cout << "Start balance: $" << Coin::getBalance() << endl;


	//Iterate through loop until balance of coins is greater than WinningBalance(1.00)
	while (Coin::getBalance() < WinningBalance) {

		// call function  evaluateToss() that is in main and pass a reference of each of the objects
		evaluateToss(&quarter);
		evaluateToss(&nickel);
		evaluateToss(&dime);

		//if statements to decide if the user wins or loses based off total balance
		//that is being tracked in static function addBalance in Coin class
		if (Coin::getBalance() == WinningBalance) {
			cout << "Your tosses add up to $" << Coin::getBalance() << " So you win the game." << endl;
		}
		else if (Coin::getBalance() > WinningBalance) {
			cout << "Your tosses add up to $" << Coin::getBalance() << " So you lose the game." << endl;
		}
	}
	return 0;
}



//function that takes a pointer reference of the Coin class ->coin
//This function uses the pointer coin to call getters and setters from superclass Coin
//Called toss() then I used if statements to compare if it is heads or tails. If it is heads then I 
// called getValue to show the value on the screen and then I called the static function addBalance
//which can only be called by using the name of the class that it belongs to.
// After using the name of the class you add the method... -->Coin::addBalance()
//I passed coin->getValue()inside of Coin::addBalance() setter as the argument to be able to add the value every time.

void evaluateToss(Coin* coin) {
	coin->toss();
	if (coin->getHeads()) {  // check if it's heads
		cout << "HEADS ...$" << coin->getValue() << endl;//print value
		Coin::addBalance(coin->getValue());// add value to balance;
	}
	else {
		cout << "tails" << endl;
	}
}


