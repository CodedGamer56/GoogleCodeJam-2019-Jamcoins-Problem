// Jamcoins

// MIT License
// Copyright (c) 2022 Trae Parwells

#include <iostream>
#include <string>
#include <cmath>

// func: Digit passed by numToStr(int& num) is converted into a character and returned
char numToChar(int& digit)
{
	int character = digit + 48; // ASCII numbers start from 48 thus adding digit which is from 0-9 will get you the appropriate ASCII character
	return character;
}

// func: Converts cheque value in integer into a string
std::string numToStr(int& num) {	

	int numClone = num;
	int numSize = 1;
	std::string str;

	// loop: You get the appropriate exponent of 10 for the digit at the highest units place
	while (numClone > 0)
	{
		numClone = numClone / 10;
		numSize *= 10;
	}
	// #brief
	// To convert the integer into a string you need to know the number of digits in the integer
	// To get the number of digits you keep dividing numClone by 10 until it becomes < 0
	// Each time you divide numClone you multiply numSize by 10

	numClone = num;
	int numUnit = 0;

	// loop: Converts each integer into a character and adds it to a string
	while (numSize != 1)
	{
		numSize /= 10;
		int digit = numClone / numSize;

		numUnit = digit * numSize;
		numClone -= numUnit;

		str += numToChar(digit);
	}
	// #brief
	// With the number of digits in the integer you would be able to convert the integer into a string
	// You pop the digits of the integer from the highest units place to the lowest units place
	// Each time you pop a digit of the integer you multiply it with the value of the units place and assign the result to numUnit
	// Then you subtract numUnit from numClone to get rid of the units place of the digit popped earlier

	return str;
}

int main() {

	// loop: gets Cheque Value which can be any number > 0
	while (true) {
		std::cout << "Cheque's Value: ";

		int val = 0;
		std::cin >> val;

		if (val < 0) break;

		std::string cheque = numToStr(val);
		int valSplit = 0;

		for (int i = 0; i < cheque.length(); i++) {
			if (cheque[i] == '4') {
				valSplit += 2 * pow(10, (cheque.length() - (i + 1)));
			}
		}

		int chequeOne = val - valSplit;

		std::cout << "Cheques: " << chequeOne << ", " << valSplit << std::endl;
	}
	// #brief
	// After you convert the cheque's value into a string you search the string for the character 4
	// If you find the character 4 you multiply 2 with 4's units place value and add that to valSplit
	// Eventually you subtract valSplit from val to split all the 4s into 2s
	

	// To stop the program input a value < 0
}
