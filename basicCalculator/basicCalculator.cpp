

#include "pch.h"
#include <iostream>

typedef double(*calculator)(double, double);


// Define operations
double add(double x, double y) {
	return x + y;
}

double subtract(double x, double y) {
	return x - y;
}

double multiply(double x, double y) {
	return x * y;
}

double divide(double x, double y) {
	return (static_cast<double>(x) / static_cast<double>(y));
}


//To choose the function based off user input
calculator getFunction(char op) {
	if (op == '+') {
		return add;
	}
	else if (op == '-') {
		return subtract;
	}
	else if (op == '*') {
		return multiply;
	}
	else {
		return divide;
	}
}

//Get number from user
double number() {
	while (true) { // Loop until valid input
		std::cout << "Please enter a number." << '\n';
		double x;
		std::cin >> x;

		if (std::cin.fail()) { // Invalid input
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Error, invalid input, try again." << '\n';
		}
		else { // Valid input
			std::cin.ignore(32767, '\n');
			return x;
		}
	}
}

//Get operation from user
char operation() {
	while (true) {
		std::cout << "Please enter an operation +-*/." << '\n';
		char op;
		std::cin >> op;

		std::cin.ignore(32767, '\n');

		//Check for invalid input
		if (op == '+' || op == '-' || op == '*' || op == '/') {
			return op;
		}
		else {
			std::cout << "Error, invalid operation, try again." << '\n';
		}
	}
}

int main()
{
	bool on = true;

	do {
		double x = number();
		char op = operation();
		double y = number();
		calculator function = getFunction(op);

		std::cout << x << ' ' << op << ' ' << y << " = " << function(x, y) << '\n';

		//Check if user would like to calculate again
		std::cout << "Would you like to calculate again? Y/N" << '\n';
		char decision;
		std::cin >> decision;

		std::cin.ignore(32767, '\n');
		if (decision == 'Y' || decision == 'y') {
			on = true;
		}
		else {
			on = false;
		}

	} while (on == true);
	return 0;
	
}


