#include "Coin.h"
#include <ctime>
#include <iostream>
#include <string>
#include <cstdlib>

Coin::Coin(double value) : value(value) {
	heads = true;
	value = 0;
}


//assigns heads or tails to sideUp
bool Coin::getHeads()
{
	if (sideUp == "heads") {
		heads = true;
	}
	else
		if (sideUp == "tails") {
			heads = false;
		}
	return heads;
}

//returns sideup 
string Coin::getSideUp()
{
	return sideUp;
}

//returns the coin object value. Nickel, dime or quarter
double Coin::getValue()
{
	return value;
}

//creates a random #. If # is 1 it will assing heads to sideup. Else it will assing tails to sideup 
//I tried __ heads =rand() %2 +1 ___  but it does not work. I can't figure out why.
void Coin::toss()
{
	heads = rand() % 2;
	if (heads == 1) {
		sideUp = "heads";
	}

	else
		sideUp = "tails";
}

void Coin::addBalance(double value) //setter function to pass value and add it to balance
{
	balance += value;
}

double Coin::getBalance()//getter to return balance
{
	return balance;
}
