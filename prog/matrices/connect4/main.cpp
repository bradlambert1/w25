#include <iostream>
#include <random>
#include <time.h>
using namespace std;
const int HEIGHT = 6;
const int WIDTH = 6;

bool isTaken(string table[][WIDTH], int i, int j) {
    return table[i][j] != " ";
}

void creationMatrice(string table[][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            table[i][j] = " ";
            cout << table[i][j];
        }
    }
}

bool isFlying(string table[][WIDTH], int i, int j ) {
    if (i + 1 >= HEIGHT) {
    return false;
    }

    return table[i+1][j] == " ";
}


char move(string table[][WIDTH], int player) {
    string playerName;
    int randomRow = 0;
    int randomCol = 0;
    char playerChar;
    do {
    randomRow = rand() % 7;
    randomCol = rand() % 7;
    } while (isTaken(table, randomRow, randomCol) && !isFlying(table, randomRow, randomCol));


    if (player % 2 == 0) {
        playerName = "Gaetan Bontemps";
        playerChar = 'B';
    } else {
        playerName = "Babe Boune Darkness";
        playerChar = 'N';
    }
    table[randomRow][randomCol] = playerChar;
    cout << "[LOG]" << playerName << " played " << randomRow << "," << randomCol << endl;
    return playerChar;
}

void game(string table[][WIDTH]) {
    bool isOngoing = true;
    char playerChar;
    int turn = 0;
    while (isOngoing) {
            move(table, turn);
            turn++;
            if (turn >= HEIGHT * WIDTH) {
                isOngoing = false;
            }
        };
    }

void printBoard(string table[][WIDTH]) {
    cout << endl << "Game Board" << endl;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            cout << "[" << table[i][j] << "]";
        }
        cout << endl;
    }
}

int main() {
    string table[6][6];
    srand(time(0));

    creationMatrice(table);
    game(table);
    printBoard(table);
    return 0;
}
    