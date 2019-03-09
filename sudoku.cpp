#include "sudoku.hpp"

sudoku::sudoku():row(0),col(0)
{
//getting grid from the function
grid = patt2grid();
}

//function to read values from the file and load into grid
int ** sudoku::patt2grid()
{
	//creating file object
	fstream file;
	//opening the file
	file.open("input.txt");
	//alocationg memory to the grid
	int **g = new int*[9];
	for(int i = 0; i < 9; i++) g[i] = new int[9];
	int j = 0;
	string line;
	//looping line by line and storing into grid
	while(getline(file,line))
	{
		for(int i = 0; i < line.length(); i++)
			g[j][i] = (line[i] - '0');
		j += 1;
	}
	file.close();
	//returning the grid
	return g;
}

//function to print the grid
void sudoku::Print()
{
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
			cout<<grid[i][j]<<"  ";
		cout<<endl<<endl;
	}
}

//main function to execute the code
void sudoku::Main()
{
	//if sudoku is solved then print it
	if (solveSudoku(0, 0))
		Print();
	else
		cout << "no possible combinations"<<endl;
	
}
//solve function, row and col initially set to 0
bool sudoku::solveSudoku(int row, int col)
	{
	//if col is 9 means we finish our column
	if (col == 9)
	{
		//we set col to zero and we increment the row 
		col = 0; row += 1;
	}
	//if row is 9 means our grid is finished
	if (row == 9) return true;
	//if grid is zero then only moving otherwise we call the recursion with col + 1
	if (grid[row][col] == 0)
	{
		//iterating to get a number between 1 and 9
		for (int i = 1; i <= 9; i++)
		{
			//calling isSafe function to check if the num is valid
			if (isSafe(row, col, i))
			{
				//if it is valid we set
				grid[row][col] = i;
				//we again call recursion to check that the move we made is correct or not
				if (solveSudoku(row, col + 1)) return true;
			}
		}
	}
	//if the grid is not zero at row and col we increment the col and call recursion
	else return solveSudoku(row, col + 1);
	//if none of the number is valid we set the grid[row][col] to 0
	grid[row][col] = 0;
	//and we return false to backtrack 
	//returning false will act as the feedback for the previous recursion call
	//and it will now try to fill the previous position with new value
	//if again it is not valid we again return false and again fill for the cell
	//and this continues until grid is filled
	//if no combination is possible false is returned
	return false;
}

//function to check for safe turn
bool sudoku::isSafe(int r, int c,int num)
{
	//if all are safe the return true else false
	return rowSafe(r,num) && colSafe(c,num) && subGridSafe(r,c,num);
}

//function for checking safe row
bool sudoku::rowSafe(int r,int num)
{
	//row check
	for(int i = 0; i < 9; i++)
		if(grid[r][i] == num)
			return false;
return true;
}

//function for checking safe column
bool sudoku::colSafe(int c, int num)
{
	//coll check
	for(int i = 0; i < 9; i++)
		if(grid[i][c] == num)
		return false;
return true;
}

//function for checking safe subgrid
bool sudoku::subGridSafe(int r, int c,int num)
{
	int a, b, n, m;

	//creating the row and col values for subgrid
	if(r <= 2) { a = 0; b = 2;}
	else if(r >= 3 && r <= 5) { a = 3; b = 5;}
	else { a = 6; b = 8; }

	if(c <= 2) { n = 0; m = 2;}
	else if(c >= 3 && c <= 5) { n = 3; m = 5;}
	else { n = 6; m = 8; }
	
	//we check for num in the subgrid
	for(int i = a; i <= b; i++)
		for(int j = n; j <= m; j++) 
			if(grid[i][j] == num)
				return false;
return true;	
}