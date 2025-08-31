#include<iostream>
#include<string>
using namespace std;

char ttt[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void displayBoard(char ttt[3][3]) {
    cout << " Current Board:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " | " << ttt[i][j];
        }
        cout << " | " << endl << " ------------- " << endl;
    }
}

void resetBoard() {
    char val = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ttt[i][j] = val++;
        }
    }
}

void playerMove(char player) {
    int pos;
    while (true) {
        cout << "Player " << player << ", enter position (1-9): ";
        cin >> pos;

        if (pos < 1 || pos > 9) {
            cout << "Invalid position! Try again."<<endl;
            continue;
        }

        int row = (pos - 1) / 3;
        int col = (pos - 1) % 3;

        if (ttt[row][col] != 'X' && ttt[row][col] != 'O') {
            ttt[row][col] = player;
            break;
        } else {
            cout << "That spot is already taken! Try again."<<endl;
        }
    }
}

char checkWinner() {
    for (int i = 0; i < 3; i++) 
    {
        if (ttt[i][0] == ttt[i][1] && ttt[i][1] == ttt[i][2]) return ttt[i][0];
        if (ttt[0][i] == ttt[1][i] && ttt[1][i] == ttt[2][i]) return ttt[0][i];
    }
    if (ttt[0][0] == ttt[1][1] && ttt[1][1] == ttt[2][2]) return ttt[0][0];
    if (ttt[0][2] == ttt[1][1] && ttt[1][1] == ttt[2][0]) return ttt[0][2];
    return ' ';
}

int main() {
    string player1, player2;
    cout << "Enter Player 1 name (X): ";
    getline(cin, player1);
    cout << "Enter Player 2 name (O): ";
    getline(cin, player2);

    cout << "Welcome to Tic Tac Toe, " << player1 << " and " << player2 << "!"<<endl;
    cout << "Let's start the game!"<<endl;

    int round = 0, roundp1 = 0, roundp2 = 0;

    while (round < 10) 
    {
        resetBoard();
        char winner = ' ';
        int moves = 0;

        displayBoard(ttt);

        while (winner == ' ' && moves < 9) 
        {
            char currentPlayer = (moves % 2 == 0) ? 'X' : 'O';
            playerMove(currentPlayer);
            displayBoard(ttt);
            winner = checkWinner();
            moves++;
        }

        if (winner == 'X') 
        {
            cout << "Congratulations " << player1 << "! You win this round!"<<endl;
            roundp1++;
        } 
        else if (winner == 'O') 
        {
            cout << "Congratulations " << player2 << "! You win this round!"<<endl;
            roundp2++;
        } 
        else 
        {
            cout << "It's a draw!"<<endl;
        }

        round++;
        cout<<"round : "<<round+1<<endl;
        cout << "Score: " << player1 << " (" << roundp1 << ") - "
             << player2 << " (" << roundp2 << ")"<<endl<<endl;
    }

    cout << "=== Game Over ==="<<endl;
    if (roundp1 > roundp2) 
    {
        cout << "Congratulations " << player1 << "! You are the overall winner!"<<endl;
    } 
    else if (roundp2 > roundp1) 
    {
        cout << "Congratulations " << player2 << "! You are the overall winner!"<<endl;
    } 
    else 
    {
        cout << "It's a tie overall!"<<endl;
    }
}
