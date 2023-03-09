#include <iostream>
#include <cstring>
using namespace std;

const int ROWS = 3;
const int COLS = 3;
const char EMPTY = ' ';
const char X = 'X';
const char O = 'O';

void drawBoard(char board[][COLS]) {
    cout << "  1 2 3\n";
    for (int i = 0; i < ROWS; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < COLS; j++) {
            cout << board[i][j] << ((j < COLS - 1) ? "|" : "");
        }
        cout << "\n" << ((i < ROWS - 1) ? "  -----\n" : "");
    }
}

bool isValidMove(char board[][COLS], int row, int col) {
    if (row < 1 || row > ROWS || col < 1 || col > COLS) {
        return false;
    }
    if (board[row-1][col-1] != EMPTY) {
        return false;
    }
    return true;
}

void makeMove(char board[][COLS], char player, int row, int col) {
    board[row-1][col-1] = player;
}

bool hasWon(char board[][COLS], char player) {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    for (int j = 0; j < COLS; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

bool isTie(char board[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == EMPTY) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char board[ROWS][COLS];
    memset(board, EMPTY, sizeof(board));
    char currentPlayer = X;
    bool gameEnded = false;
    while (!gameEnded) {
        drawBoard(board);
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row col): ";
        cin >> row >> col;
        if (isValidMove(board, row, col)) {
            makeMove(board, currentPlayer, row, col);
            if (hasWon(board, currentPlayer)) {
                cout << "Player " << currentPlayer << " has won!" << endl;
                gameEnded = true;
            } else if (isTie(board)) {
                cout << "The game is a tie." << endl;
                gameEnded = true;
            } else {
                currentPlayer = (currentPlayer == X) ? O : X;
            }
        } else {
            cout << "Invalid move. Please try again." << endl;
        }
    }
    }
