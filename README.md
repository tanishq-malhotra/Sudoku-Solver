Sudoku Solver using backtracking algorithm.

Backtracking algorithm uses recursion for implementation in which a feedback
is provided to previous recursion call.

I start with row and col with value 0 and increment them just like iterating in a loop.

Used isSafe function to check if the number is valid and then recursivly checks that the number is suitable for that position or not.

Input is stored in the input.txt file without spaces. Example input is already
given.

To compile use command:-

g++ *.cpp -o main