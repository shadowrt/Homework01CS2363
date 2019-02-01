//============================================================================
// Name        : HW1CS2363.cpp
// Author      : R. Bruce Tuckey    CS2363-TS02S
// Version     :
// Copyright   : Dr. Goulden         Mon 5:30-8:00
// Description : Roman Numeral <-> Integer converter
//               Simple program to convert between Roman Numerals and Decimal Integers
//============================================================================

#include <iostream>
#include <string>
#include <sstream>
using namespace std;



bool	isValidDecimalNumber(string s);
	// Checks for valid positive integer to 3,999,999 which is all I can easily find in the googles
	//@param s your input string
	//@return true or false if its a valid decimal number

bool	isValidRomanNumber(string s);
	// make sure it has valid Roman numerals...
	// And I guess make sure they are in the correct order since it's not a real number if it's not right..
	//@param s your input string
	//@return true or false if its a valid Roman Numeral

string	convertRomanToDecimal(string s);
	// convert Roman numbers to decimal
	//@param s a valid Roman numeral
	//@return a string with the decimal equivalent

string	convertDecimalToRoman(string s);
	// convert decimal numbers to Roman
	//@param s a valid decimal numeral
	//@return a string with the Roman numeral equivalent

int main() {
	string myInput;							// a string to use as input
	string romanValue;						// a string to hold the Roman numeral
	int validRomans = 0, validDecimals = 0; // counters for Roman numeral and decimal conversions

	while ((myInput != "0") && (myInput != "O")) {

		cout << "Welcome to Roman Number Conversion!" << endl;
		cout << " NOTE: no Pig Roman allowed..." << endl;
		cout << "Please enter a value to convert: " ;

		cin >> myInput;
		if(myInput != "0" && myInput != "O") {
		if(isValidRomanNumber(myInput)){
			validRomans++;
			cout << myInput << " (Roman) is "  << convertRomanToDecimal(myInput) << " (Decimal)." << endl;
		}
		else if(isValidDecimalNumber(myInput)){
			int localNumber = 0;
			stringstream mynumber(myInput);
			mynumber >> localNumber;
			if(localNumber > 3999999){     // error out on four million
					cout << "Not coded to four million, please inform Dr. Goulden of my failure as a human..." << endl;
			}else {
					validDecimals++;
					cout << myInput << " (Decimal) is " << convertDecimalToRoman(myInput) << " (Roman)." << endl;
					romanValue = convertDecimalToRoman(myInput);
			}
		}
		else cout << "I did not understand input " << myInput << endl;
		}
	}

	cout << validRomans + validDecimals << " numbers were converted (";
	cout << validDecimals << " Decimal to Roman, ";
	cout << validRomans << " Roman to Decimal)" << endl;
	cout << "Thank You for playing Roman Number Conversion!" << endl; //  always subtract one for exit input
	return 0;

}

string convertDecimalToRoman(string decimal){
	int localNumber = 0;			// my local number to work upon
	string romanReturn = "";		// the roman numeral I will generate
	stringstream mynumber(decimal); // setup to convert the string to a "real" number
	mynumber >> localNumber;        // store the integer in my local variable

	while (localNumber > 999999){	// over a million
		romanReturn += "M\u0305";
		localNumber -=1000000;
	}
	if (localNumber > 899999){		// nine hundred thousand exception
		romanReturn += "C\u0305M\u0305";
		localNumber -=900000;
	}
	while (localNumber > 499999){	// over five hundred thousand
		romanReturn += "D\u0305";
		localNumber -=500000;
	}
	if (localNumber > 399999){		// four hundred thousand exception
		romanReturn += "C\u0305D\u0305";
		localNumber -=400000;
	}
	while (localNumber > 99999){	// over one hundred thousand
		romanReturn += "C\u0305";
		localNumber -=100000;
	}
	if (localNumber > 89999){		// ninety thousand exception
		romanReturn += "X\u0305C\u0305";
		localNumber -=90000;
	}
	while (localNumber > 49999){	// over fifty thousand
		romanReturn += "L\u0305";
		localNumber -=50000;
	}
	if (localNumber > 39999){		// fourty thousand exception
		romanReturn += "X\u0305L\u0305";
		localNumber -=40000;
	}
	while (localNumber > 9999){		// over ten thousand
		romanReturn += "X\u0305";
		localNumber -=10000;
	}
	if (localNumber > 8999){		// nine thousand exception
		romanReturn += "MX\u0305";
		localNumber -=9000;
	}
	while (localNumber > 4999){		// over five thousand
		romanReturn += "V\u0305";
		localNumber -=5000;
	}
	if (localNumber > 3999){		// four thousand exception
		romanReturn += "MV\u0305";
		localNumber -=4000;
	}
	while (localNumber > 999){		// over a thousand
		romanReturn += 'M';
		localNumber -=1000;
	}
	if (localNumber > 899) {		// nine hundred exception
		romanReturn += "CM";
		localNumber -= 900;
	}
	while (localNumber > 499){		// over five hundred
		romanReturn += 'D';
		localNumber -=500;
	}
	if (localNumber > 399){			// four hundred exception
		romanReturn += "CD";
		localNumber -=400;
	}
	while (localNumber > 99){		// over one hundred
		romanReturn += 'C';
		localNumber -=100;
	}
	if (localNumber > 89){			// ninety exception
		romanReturn +="XC";
		localNumber -= 90;
	}
	while (localNumber > 49){		// over fifty
		romanReturn += 'L';
		localNumber -=50;
	}
	if(localNumber > 39){			// forty exception
		romanReturn += "XL";
		localNumber -= 40;
	}
	while (localNumber > 9){		// over ten
		romanReturn += 'X';
		localNumber -=10;
	}
	if (localNumber > 8){			// nine exception
		romanReturn +="IX";
		localNumber -= 9;
	}
	while (localNumber > 4){		// over five
		romanReturn += 'V';
		localNumber -=5;
	}
	if(localNumber > 3){			// four exception
		romanReturn += "IV";
		localNumber -= 4;
	}
	while (localNumber > 0){		// over zero
		romanReturn += 'I';
		localNumber -=1;
	}

	//
	//  I probably should have continued with the while and if loop, I'm lazy.
	//  maybe some day when I'm rich and famous I will look back and think...  I'm going to fix that.
	//  It won't be today though, I'm still deeply troubled by the harsh reality that it would take
	//  far too long to put proper checks on the roman number input to validate TRUE roman numerals.
	//
/*	if(localNumber == 9) romanReturn += "IX";
	if(localNumber == 8) romanReturn += "VIII";
	if(localNumber == 7) romanReturn += "VII";
	if(localNumber == 6) romanReturn += "VI";
	if(localNumber == 5) romanReturn += "V";
	if(localNumber == 4) romanReturn += "IV";
	if(localNumber == 3) romanReturn += "III";
	if(localNumber == 2) romanReturn += "II";
	if(localNumber == 1) romanReturn += "I";
*/
	//
	// OK so I got with the program and did it the right way..  Are ya happy now?
	//
	return romanReturn;
}

// walk the array and check for only 0-9 numbers
bool isValidDecimalNumber(string s){
	bool localBoo = true;			// used locally so we dont have multiple exits and cleanup our memory
	int localNumber = 0;
	stringstream mynumber(s);
	mynumber >> localNumber;
	for(int x = 0; x < s.size(); x++){
		if(s[x] != '0' && s[x] != '1' && s[x] != '2' && s[x] != '3'
				&& s[x] != '4' && s[x] != '5' && s[x] != '6'
				&& s[x] != '7' && s[x] != '8' && s[x] != '9')
			localBoo = false;
	}
	// finished so array must be valid decimal numbers
	return localBoo;
}

// walk the array and check for only Roman numerals
//  I really should set a flag internal to this routine so I only have one exit
// for true and one exit for false.  Perhaps if I have time.
bool isValidRomanNumber(string s){
	string romanChar = "IVXLCDM";	// used check for 4 of any character in sequence - violating Roman numerals
	bool localBoo = true;			// used locally so we dont have multiple exits and cleanup our memory
	for(int x = 0; x < s.size(); x++){
		if(s[x] != 'M' && s[x] != 'D' && s[x] != 'C' && s[x] != 'X'
				&& s[x] != 'L' && s[x] != 'V' && s[x] != 'I')
			localBoo = false;
	}
	// finished the array so we have Roman characters
	// And now comes the task of validating it's a real Roman numeral and not gibberish like IM.
	// ie we institute the subtractive rules
	//
	for(int x = 0; x < s.size(); x++){
		if(s[x] == 'I' && (s[x + 1] == 'L' || s[x + 1] == 'C' || s[x + 1] == 'D' || s[x + 1] == 'M' )) localBoo = false;
		if(s[x] == 'V' && (s[x + 1] == 'V' || s[x + 1] == 'X' || s[x + 1] == 'L'
				|| s[x + 1] == 'C' || s[x + 1] == 'D' || s[x +1] == 'M' )) localBoo = false;
		if(s[x] == 'X' && (s[x + 1] == 'D' || s[x + 1] == 'M' || s[x + 2] == 'X')) localBoo = false;
		if(s[x] == 'L' && (s[x + 1] == 'L' || s[x + 1] == 'C' || s[x + 1] == 'D' || s[x + 1] == 'M' )) localBoo = false;
		if(s[x] == 'C' && (s[x + 2] == 'C')) localBoo = false;
		if(s[x] == 'D' && (s[x + 1] == 'D' || s[x + 1] == 'M' )) localBoo = false;
	}
	// So we know we have proper subtraction rules done
	// Now lets run through and make sure we don't have more than three
	// same numeral next to each other in the string.
	int myCharCount = 0;
	for(int x = 0; x < romanChar.size(); x++){
		for(int y = 0; y < s.size(); y++){
			if(s[y] == romanChar[x] && s[y + 1] == s[y]) myCharCount++;
		}
		if(myCharCount > 3) localBoo = false;
		myCharCount = 0;
	}
	return localBoo;
}

// convertRomanToDecimal from http://www.cpluscplus.com/forum/beginner/78047/
// Used that as a starting place but heavily modified to work with proper order.
string convertRomanToDecimal(string roman){
	int decimal = 0;
	string theNumber;
	enum romans {I=1, V=5, X=10, L=50, C=100, D=500, M=1000};
	for (int i=0; i < roman.size(); i++) {
		switch (roman[i]) // based on this character in the string
		{
			case 'M': decimal +=M; break;
			case 'D': decimal +=D;break;
			case 'C':
				if (roman[i + 1] != 'D' && roman[i + 1] != 'M' )
					decimal +=C;
				else
					decimal -=C;
				break;
			case 'L': decimal +=L; break;
			case 'X':
				if (roman[i + 1] != 'L' && roman[i + 1] != 'C' )
					decimal +=X;
				else
					decimal -=X;
				break;
			case 'V': decimal +=V; break;
			case 'I':
				if (roman[i +1] != 'V' && roman[i + 1] != 'X' )
					decimal+=1;
				else
					decimal-=1;
				break;

		}
	}
	return std::to_string(decimal);
}


