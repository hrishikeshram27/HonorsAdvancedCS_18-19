// testxy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "pch.h"
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <string>

using namespace std;

COORD coord = { 0,0 }; // this is global variable
									/*center of axis is set to the top left cornor of the screen*/
void gotoxy(int x, int y)
{
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
	gotoxy(10, 20);
    cout << "Hello World!\n";
	gotoxy(40, 0);
	cout << "test me    column - 40,  row 0\n";
	int xinput;
	int yinput;
	string stringinput;
	cout << "Input x -coord \n";
	cin >> xinput;
	system("CLS");
	cout << "input y-coord \n";
	gotoxy(0, 0);
	cin >> yinput;
	cout << "input phrase \n";
	cin>>stringinput;
	gotoxy(xinput, yinput);
	cout << stringinput;
	cin >> stringinput;
	system("CLS");


	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
