//============================================================================
// Name        : Homework01CS2363.cpp
// Author      : R. Bruce Tuckey    CS2363-TS02S
// Version     :
// Copyright   : Dr. Goulden         Mon 5:30-8:00
// Description : Roman numeral and decimal converter
// accepts string input and converts to either decimal or Roman numerals based on input
// Complete re-write that allows "Pig Roman".  Also included extended decimal to Roman
// conversion to 3,999,999 as a hopeful bonus point option.
// the original more complicated non-Pig roman version is in my github
//============================================================================

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Required functions
bool   isValidDecimalNumber(string s);
// Checks for valid positive integer to 3,999,999 which is all I can easily find in the googles
//@param s your input string
//@return true or false if its a valid decimal number

bool   isValidRomanNumber(string s);
// make sure it has valid Roman numerals... without regard to proper precedence.
//@param s your input string
//@return true or false if its a valid Roman Numeral

string convertRomanToDecimal(string s);
// convert Roman numbers to decimal
//@param s a valid Roman numeral
//@return a string with the decimal equivalent

string convertDecimalToRoman(string s);
// convert decimal numbers to Roman
//@param s a valid decimal numeral
//@return a string with the Roman numeral equivalent

int main() {
	string myInput; 							// string for input
	int goodDecimal = 0, goodRoman = 0;			// Our counters for good decimal and Roman input

	while(myInput != "0" && myInput != "O"){

		cout << "Welcome to Roman Number Conversion!" << endl;
		cout << "Please enter a value to convert: " ;
		cin >> myInput;

		if(myInput != "0" && myInput != "O"){	// looks funny but keeps from counting exit 0 as decimal
			if(isValidRomanNumber(myInput)){	// you got a roman numeral
				goodRoman+=1;					// bump your counter then do the needful conversion/output
				cout << myInput << " (Roman) = "<< convertRomanToDecimal(myInput) << " (Decimal)" << endl;
			} else if(isValidDecimalNumber(myInput)){	// Yippee!  I got a decimal
				goodDecimal +=1;						// bump said counter and convert/print
				cout << myInput << " (Decimal) is " << convertDecimalToRoman(myInput) << " (Roman)" << endl;
			}else cout << "I did not understand input " << myInput << endl;	// Sacrilege! Off with your head!
			// I continue running in observance of the example which is contrary to the instructions that say to exit.
			// If you want to subtract points for this that's fine.
		}
	}

	// Puke out the summary at the user
	cout << goodRoman + goodDecimal << " numbers were converted (" << goodDecimal;
	cout << " Decimal to Roman, " << goodRoman << " Roman to Decimal)" << endl;
	cout << "Thank You for playing Roman Number Conversion!" << endl;

	return 0;
}


bool   isValidDecimalNumber(string s){
	bool localBoo = true;							// use a local boolean so we dont have multiple returns
	for(int x = 0; x < s.size(); x++){				// walk the string input and verify actual digits are there
		if(s[x] != '0' && s[x] != '1' && s[x] != '2' && s[x] != '3' && s[x] != '4'
				&& s[x] != '5' && s[x] != '6' && s[x] != '7' && s[x] != '8'
				&& s[x] != '9') localBoo = false;	// Nope not a real decimal number
	}

	return localBoo;								// send the bool back
}


bool isValidRomanNumber(string s){
	bool localBoo = true;							// use a local boolean so we dont have multiple returns
	for(int x = 0; x < s.size(); x++){				// walk the string input to verify actual Roman numerals are there
		if(s[x] != 'I' && s[x] != 'V' && s[x] != 'X' && s[x] != 'L'
				&& s[x] != 'C' && s[x] != 'D' && s[x] != 'M') localBoo = false; // Bummer, not a Roman numeral
	}
	return localBoo;								// send the bool back
}


string convertRomanToDecimal(string roman){
	int myDecimal = 0;											// keep adding or subtracting to make the number
	enum romans {I=1, V=5, X=10, L=50, C=100, D=500, M=1000};	// build a table?  I know it's not a table but I think of it that way

	for(int x = 0; x < roman.size(); x++){						// Walk the input string
		switch(roman[x]){ 										// based on char in the string do the needful
		case 'M': myDecimal +=M; break;
		case 'D': myDecimal +=D; break;
		case 'C':
			if(roman[x+1] != 'M' && roman[x+1] != 'D')
				myDecimal +=C;
			else
				myDecimal -=C;									// subtract if it precedes a M or D.
			break;
		case 'L': myDecimal +=L; break;
		case 'X':
			if(roman[x+1] != 'C' && roman[x+1] != 'L' && roman[x+1] != 'D' && roman[x+1] != 'M' )
				myDecimal +=X;
			else
				myDecimal -=X;									// subtract if it precedes C, L, D, or M.
			break;
		case 'V': myDecimal +=V; break;
		case 'I':
			if(roman[x+1] != 'X' && roman[x+1] != 'V' && roman[x+1] != 'L' && roman[x+1] != 'C' && roman[x+1] != 'D' && roman[x+1] != 'M')
				myDecimal +=I;
			else
				myDecimal -=I;									// subtract if it precedes X, V, L, C, D, or M. (simple pig Roman)
			break;
		}
	}
	return std::to_string(myDecimal);							// cast it to a string and return the decimal. I know its not cast but again I think of it that way.
}

string convertDecimalToRoman(string s){
	int localNumber = 0;			// my local number to work upon
	string romanReturn = "";		// the roman numeral I will generate
	// I had to look these next two lines up to get it done, sadly there is no std::to_decimal()
	stringstream mynumber(s); 		// setup to convert the string to a "real" number
	mynumber >> localNumber;        // store the integer in my local variable

  // This looks ok on non-windwers machines.
	// This whole section seams like there should be a shorter way, I just can't come up with it.
	while(localNumber > 999999){	// This is the millions
		romanReturn += "M\u0305";
		localNumber -=1000000;
	}
	if(localNumber > 899999){		// this is the nine hundred thousands
		romanReturn +="C\u0305M\u0305";
		localNumber -=900000;
	}
	if(localNumber > 499999){		// this is the five hundred thousands
		romanReturn +="D\u0305";
		localNumber -=500000;
	}
	if(localNumber > 399999){		// this is the four hundred thousands
		romanReturn +="C\u0305D\u0305";
		localNumber -=400000;
	}
	while(localNumber > 99999){		// This is the hundred thousands
		romanReturn += "C\u0305";
		localNumber -=100000;
	}
	if(localNumber > 89999){		// this is the ninety thousands
		romanReturn +="X\u0305C\u0305";
		localNumber -=90000;
	}
	if(localNumber > 49999){		// this is the fifty thousands
		romanReturn +="L\u0305";
		localNumber -=50000;
	}
	if(localNumber > 39999){		// this is the forty thousands
		romanReturn +="X\u0305L\u0305";
		localNumber -=40000;
	}
	while(localNumber > 9999){		// This is the ten thousands
		romanReturn += "X\u0305";
		localNumber -=10000;
	}
	if(localNumber > 8999){			// this is the nine thousands
		romanReturn +="MX\u0305";
		localNumber -=9000;
	}
	if(localNumber > 4999){			// this is the five thousands
		romanReturn +="V\u0305";
		localNumber -=5000;
	}
	if(localNumber > 3999){			// this is the four thousands
		romanReturn +="MV\u0305";
		localNumber -=4000;
	}
	while(localNumber > 999){		// This is the one thousands
		romanReturn += "M";
		localNumber -=1000;
	}
	if(localNumber > 899){			// this is the nine hundreds
		romanReturn +="CM";
		localNumber -=900;
	}
	if(localNumber > 499){			// this is the five hundreds
		romanReturn +="D";
		localNumber -=500;
	}
	if(localNumber > 399){			// this is the four hundreds
		romanReturn +="CD";
		localNumber -=400;
	}
	while(localNumber > 99){		// This is the one hundreds
		romanReturn += "C";
		localNumber -=100;
	}
	if(localNumber > 89){			// this is the nineties
		romanReturn +="XC";
		localNumber -=90;
	}
	if(localNumber > 49){			// this is the fifties
		romanReturn +="L";
		localNumber -=50;
	}
	if(localNumber > 39){			// this is the forties
		romanReturn +="XL";
		localNumber -=40;
	}
	while(localNumber > 9){			// This is the tens
		romanReturn += "X";
		localNumber -=10;
	}
	if(localNumber > 8){			// this is the nines
		romanReturn +="IX";
		localNumber -=9;
	}
	if(localNumber > 4){			// this is the fives
		romanReturn +="V";
		localNumber -=5;
	}
	if(localNumber > 3) {			// this is the fours
		romanReturn +="IV";
		localNumber -=4;
	}
	while(localNumber > 0){			// this is the ones
		romanReturn +="I";
		localNumber -=1;
	}
	return romanReturn;				// send that Roman numeral back to main... or from whence it came.
}

