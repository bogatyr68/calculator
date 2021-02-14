//peasantcalc.cpp
//Peasant calculator. A calculator, developed by a peasant, so that other peasants may calculate yet more peasants

#include <iostream>
#include <fstream>

using namespace std;

float peasantThink(float, char, float);

int main()
{
	bool activeProgram = true;
	float numberA = 0;
	float numberB = 0;
	char operate = ' ';
	cout << "Peasant calculator. Like a normal calculator, except for peasants. Use Q or E to exit the program after a calculation." << endl;

	ofstream scribe;

	scribe.open("number record.txt");

	cin >> numberA;
	cin >> operate;

	while (activeProgram != false)
	{
		cin >> numberB;
		cout << endl;

		scribe << "\t" << numberA << endl;
		scribe << "\t" << operate << numberB << endl;
		scribe << "__________" << endl;

		numberA = peasantThink(numberA, operate, numberB);
		scribe << "\t" << numberA << endl << endl << endl;
		cout << numberA << endl;

		cin >> operate;
	}

	switch (operate)
	{
		case 'q':
		case 'Q':
		case 'e':
		case 'E':
			activeProgram = false;
			break;
	}

	cout << "Program ending.";
	scribe.close();
}

float peasantThink(float numberAlpha, char mdas, float numberBeta)
{
	//need a method to check to make sure the user's in put is an actual number.
	switch (mdas)
	{
	case '+':
		numberBeta = numberAlpha + numberBeta;
		return numberBeta;
		break;
	case '-':
		numberBeta = numberAlpha - numberBeta;
		return numberBeta;
		break;
	case '*':
		numberBeta = numberAlpha * numberBeta;
		return numberBeta;
		break;
	case '/':
		if (numberBeta == 0)
		{
			cout << "42. Proof: Douglas Adams Law of Everything. As division by zero falls under the category of \"everything,\", the result is 42." << endl;
			return numberBeta;
		}
		else
		{
			numberBeta = numberAlpha / numberBeta;
			return numberBeta;
		}
		break;
	default:
		cout << "Please enter an operation involving +, -, /, or *. Do not divide by zero." << endl;
		break;
	}
}