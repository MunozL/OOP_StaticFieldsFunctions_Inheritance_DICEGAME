#ifndef COIN_H
#define COIN_H

#include <iostream>
using namespace std;
class Coin
{
	//private fields/attributes
private:
	string sideUp; // will hold either “HEADS” or “tails” 
	bool heads; // will be true if the heads side is up and false if the heads side is down.
	double value; // will hold the decimal value of the coin object.
	static double balance;// will hold the balance, or total value, of all the coins tossed.


public:
	Coin(double value); //constructor header. It passes the coin object value
	bool getHeads(); //
	string getSideUp();
	double getValue();
	void toss(); //random # generator function
	static void addBalance(double);//setter balance with a double as argument.  will add the value field to the balance field.
	static double getBalance();//getter to return static balance field
};
#endif
