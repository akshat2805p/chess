#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int BOARD_SIZE = 8;

// Function to initialize the chessboard
void initializeBoard(vector<vector<string>>& board) {
    board = {
        {"R", "N", "B", "Q", "K", "B", "N", "R"},
        {"P", "P", "P", "P", "P", "P", "P", "P"},
        {".", ".", ".", ".", ".", ".", ".", "."},
        {".", ".", ".", ".", ".", ".", ".", "."},
        {".", ".", ".", ".", ".", ".", ".", "."},
        {".", ".", ".", ".", ".", ".", ".", "."},
        {"p", "p", "p", "p", "p", "p", "p", "p"},
        {"r", "n", "b", "q", "k", "b", "n", "r"}
    };
}

// Function to display the chessboard
void displayBoard(const vector<vector<string>>& board) {
    cout << "  a b c d e f g h\n";
    for (int i = 0; i < BOARD_SIZE; i++) {
        cout << 8 - i << " ";
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << board[i][j] << " ";
        }
        cout << 8 - i << "\n";
    }
    cout << "  a b c d e f g h\n";
}

// Function to process a move
bool makeMove(vector<vector<string>>& board, const string& move) {
    if (move.length() != 5 || move[2] != '-') {
        cout << "Invalid move format! Use 'e2-e4' format.\n";
        return false;
    }

    int startCol = move[0] - 'a';
    int startRow = 8 - (move[1] - '0');
    int endCol = move[3] - 'a';
    int endRow = 8 - (move[4] - '0');

    // Validate move
    if (startRow < 0 || startRow >= BOARD_SIZE || startCol < 0 || startCol >= BOARD_SIZE ||
        endRow < 0 || endRow >= BOARD_SIZE || endCol < 0 || endCol >= BOARD_SIZE) {
        cout << "Move out of bounds!\n";
        return false;
    }

    if (board[startRow][startCol] == ".") {
        cout << "No piece at the starting position!\n";
        return false;
    }

    // Make the move
    board[endRow][endCol] = board[startRow][startCol];
    board[startRow][startCol] = ".";
    return true;
}

int main() {
    vector<vector<string>> board;
    initializeBoard(board);

    cout << "Welcome to Chess!\n";
    cout << "Enter moves in the format 'e2-e4'. Enter 'exit' to quit.\n";

    string move;
    bool whiteTurn = true;

    while (true) {
        displayBoard(board);
        cout << (whiteTurn ? "White's turn: " : "Black's turn: ");
        cin >> move;

        if (move == "exit") {
            cout << "Game over! Thank you for playing.\n";
            break;
        }

        if (makeMove(board, move)) {
            whiteTurn = !whiteTurn;
        }
    }

    return 0;
}
