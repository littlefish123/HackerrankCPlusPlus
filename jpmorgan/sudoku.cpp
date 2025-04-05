// write a c++ program to check validity of a 9x9 Sudoku board
/*

Checks if the current number is repeated in the row.

Checks if the current number is repeated in the column.

Checks if the current number is repeated in the corresponding 3x3 box.
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool isValid(vector<vector<char>>& board) {

		for (int i = 0; i < 9; i++) {
			unordered_set<char> rows;
			unordered_set<char> cols;
			unordered_set<char> box;

		/*
		The insert method of unordered_set returns a pair, 
		where the first element is an iterator to the inserted element
		(or to the element that prevented the insertion), 
		and the second element is a boolean indicating whether the insertion 
		took place.We are interested in the second element to check if the insertion was successful.
		*/
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.' && !rows.insert(board[i][j]).second )
					return false;
				if (board[j][i] != '.' && !cols.insert(board[j][i]).second )
					return false;
				int boxRow = (int) (3 * (i / 3) + j / 3);
				int boxCol = (int) (3 * (i % 3) + j % 3);
				if (board[boxRow][boxCol] != '.' && !box.insert(board[boxRow][boxCol]).second )
					return false;
			}
		}
	

	return true;
}

int main() {
	/*
	vector<vector<char>> board = {
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '6', '8', '5', '3', '.', '7', '.'},
		{'7', '2', '.', '4', '1', '9', '.', '.', '.'},
		{'.', '6', '.', '.', '.', '2', '8', '.', '.'},
		{'.', '.', '4', '1', '9', '5', '.', '8', '.'},
		{'.', '8', '7', '.', '4', '2', '.', '1'}
	}; */

	vector<vector<char>> board = {
				{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
				{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
				{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
				{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
				{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
				{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
				{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
				{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
				{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
	};

	cout << "Sudoku board: " << (isValid(board) ? "Valid Sudoku" : "Invalid Sudoku") << endl;
}
