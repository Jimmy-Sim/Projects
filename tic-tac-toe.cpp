#include <iostream>

using namespace std;

char board[5][5];

void boardInit()
{
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) board[i][j] = ' ';
    }
}

void displayBoard()
{
    cout << board[1][1] << '|' << board[1][2] << '|' << board[1][3] << '\n';
    cout << "-----\n";
    cout << board[2][1] << '|' << board[2][2] << '|' << board[2][3] << '\n';
    cout << "-----\n";
    cout << board[3][1] << '|' << board[3][2] << '|' << board[3][3] << '\n';
}

bool oWins, xWins;

void checkOWins()
{
    for (int i = 1; i <= 3; i++) {
        if (board[i][1] == 'O' && board[i][2] == 'O' && board[i][3] == 'O') oWins = true;
        else if (board[1][i] == 'O' && board[2][i] == 'O' && board[3][i] == 'O') oWins = true;
    }
    if (board[1][1] == 'O' && board[2][2] == 'O' && board[3][3] == 'O') oWins = true;
    else if (board[1][3] == 'O' && board[2][2] == 'O' && board[3][1] == 'O') oWins = true;
}

void checkXWins()
{
    for (int i = 1; i <= 3; i++) {
        if (board[i][1] == 'X' && board[i][2] == 'X' && board[i][3] == 'X') xWins = true;
        else if (board[1][i] == 'X' && board[1][2] == 'X' && board[3][i] == 'X') xWins = true;
    }
    if (board[1][1] == 'X' && board[2][2] == 'X' && board[3][3] == 'X') xWins = true;
    else if (board[1][2] == 'X' && board[2][2] == 'X' && board[3][1] == 'X') xWins = true;
}

void play()
{
    oWins = false, xWins = false;
    boardInit();
    int turn = 1, count = 0;

    while (true) {
        displayBoard();

        checkOWins();
        checkXWins();

        if (oWins) {
            cout << "Player O Wins!\n\n";
            break;
        }
        else if (xWins) {
            cout << "Player X Wins!\n\n";
            break;
        }
        else if (count == 9) {
            cout << "Draw!\n\n";
            break;
        }

        if (turn % 2 == 1) cout << "Player O's Turn\n";
        else cout << "Player X's Turn\n";

        int row, col;
        cout << "Enter row: ";
        cin >> row;
        cout << "Enter column: ";
        cin >> col;
        while (row < 1 || row > 3 || col < 1 || col > 3 || board[row][col] != ' ') {
            cout << "Please enter appropriately.\n";
            cout << "Enter row: ";
            cin >> row;
            cout << "Enter column: ";
            cin >> col;
        }

        if (turn % 2 == 1) board[row][col] = 'O';
        else board[row][col] = 'X';

        turn++;
        count++;
    }
}

// Tic-tac-toe is a two-player game where players take turns marking the spaces in a three-by-three grid with X or O. The player who succeeds in placing three of their marks in a horizontal, vertical, or diagonal row is the winner. 

void rules()
{
    cout << "Tic-tac-toe is a two-player game where players\n";
    cout << "take turns marking the spaces in a three-by-three grid with X or O.\n";
    cout << "The player who succeeds in placing three of their marks in a\n";
    cout << "horizontal, vertical, or diagonal row is the winner.\n\n";
}

int main()
{
    while (true) {
        cout << "TIC-TAC-TOE\n";
        cout << "1: Play\n";
        cout << "2: Rules\n";
        cout << "3: Quit\n";

        int option;
        cin >> option;

        if (option == 1) play();
        else if (option == 2) rules();
        else if (option == 3) break;
        else cout << "Please choose a valid option.\n\n";
    }

    return 0;
}