#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class sudoku
{
public:
	int row , col;
	//declaring 2d pointer for the grid
	int **grid;
	//default constructor
	sudoku();
	//function to read values from the file and load into grid
	int ** patt2grid();
	//function to print the grid
	void Print();
	//main function to execute the code
	void Main();
	//main solve function
	bool solveSudoku(int , int );
	//function to check for safe turn
	bool isSafe(int , int ,int );
	//function for checking safe row
	bool rowSafe(int ,int );
	//function for checking safe column
	bool colSafe(int ,int );
	//function for checking safe subgrid
	bool subGridSafe(int , int ,int );
	
};