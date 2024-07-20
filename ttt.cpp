#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Function prototypes
void initializeBoard(vector<vector<char>>& board);

void displayBoard(const vector<vector<char>>& board);
bool makeMove(vector<vector<char>>& board, int row, int col, char currentPlayer);
bool checkWin(const vector<vector<char>>& board, char currentPlayer);
bool checkDraw(const vector<vector<char>>& board);
bool isValidMove(const vector<vector<char>>& board, int row, int col);
bool playAgain();

int main() {
    bool play = true;
    while (play) {
        vector<vector<char>> board(3, vector<char>(3, ' '));
        bool gameOver = false;
        char currentPlayer = 'X';

        initializeBoard(board);
        displayBoard(board);

        while (!gameOver) {
            int move;
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;

            // Convert move number (1-9) to row and column
            int row = (move - 1) / 3;
            int col = (move - 1) % 3;

            if (isValidMove(board, row, col)) {
                if (makeMove(board, row, col, currentPlayer)) {
                    displayBoard(board);
                    if (checkWin(board, currentPlayer)) {
                        cout << "Player " << currentPlayer << " wins!" << endl;
                        gameOver = true;
                    } else if (checkDraw(board)) {
                        cout << "It's a draw!" << endl;
                        gameOver = true;
                    } else {
                        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                    }
                } else {
                    cout << "That position is already taken. Try again." << endl;
                }
            } else {
                cout << "Invalid move. Please enter a number between 1-9 and choose an empty spot." << endl;
            }
        }

        play = playAgain();
    }

    cout << "Thanks for playing Tic-Tac-Toe!" << endl;

    return 0;
}

// Initialize the board with empty spaces
void initializeBoard(vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

// Display the current state of the board
void displayBoard(const vector<vector<char>>& board) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

// Make a move on the board
bool makeMove(vector<vector<char>>& board, int row, int col, char currentPlayer) {
    if (board[row][col] == ' ') {
        board[row][col] = currentPlayer;
        cout << "Player " << currentPlayer << " has placed " << currentPlayer << " at position " << (row * 3 + col + 1) << endl;
        return true;
    }
    return false;
}

// Check if the current player has won
bool checkWin(const vector<vector<char>>& board, char currentPlayer) {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
            return true;
        }
    }
    // Check columns
    for (int j = 0; j < 3; ++j) {
        if (board[0][j] == currentPlayer && board[1][j] == currentPlayer && board[2][j] == currentPlayer) {
            return true;
        }
    }
    // Check diagonals
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
        return true;
    }
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
        return true;
    }
    return false;
}

// Check if the game is a draw
bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false; // There is an empty space, game is not draw
            }
        }
    }
    return true; // All spaces are filled, game is a draw
}

// Check if the move is valid
bool isValidMove(const vector<vector<char>>& board, int row, int col) {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}

// Ask if players want to play again
bool playAgain() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}