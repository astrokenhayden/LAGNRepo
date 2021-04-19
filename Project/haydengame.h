#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <stdlib.h> 


using namespace std;
class HaydenGame {


private:
    int m_XO;
    int m_OX;
    char winner;
    char board[3][3];

public:
    void play(char playerLetter);
    bool isFull();
    void displayBoard();
    bool isValidMove();
    void getXOMove(int XO, int OX);
    bool gameStatus(char player);
    HaydenGame();
    void comPlayerNumbers();

};
void HaydenGame::comPlayerNumbers() {
    // player o is always the computer
    m_XO = rand() % 4;
    m_OX = rand() % 4;


}
void HaydenGame::play(char playerLetter) {

    if (m_XO == 1 && m_OX == 1) { // board position 1 1 case 1
        board[0][0] = playerLetter;
    }
    if (m_XO == 2 && m_OX == 2) { // board postion 2 2 case 2
        board[1][1] = playerLetter;
    }
    if (m_XO == 3 && m_OX == 3) { // board postion 3 3 case 3
        board[2][2] = playerLetter;
    }
    if (m_XO == 1 && m_OX == 2) { // board postion 1 2 case 4
        board[0][1] = playerLetter;
    }
    if (m_XO == 1 && m_OX == 3) { // board postion 1 3 case 5
        board[0][2] = playerLetter;
    }
    if (m_XO == 2 && m_OX == 1) { // board postion 2 1 case 6
        board[1][0] = playerLetter;
    }
    if (m_XO == 2 && m_OX == 3) { // board position 2 3 case 7
        board[1][2] = playerLetter;
    }
    if (m_XO == 3 && m_OX == 1) { // board position 3 1 case 8
        board[2][0] = playerLetter;
    }
    if (m_XO == 3 && m_OX == 2) { // board position 3 2 case 9
        board[2][1] = playerLetter;
    }

}

void HaydenGame::displayBoard() {

    cout << "     1   2   3";

    cout << endl << endl;
    cout << " 1  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "   ___|___|___" << endl;
    cout << " 2  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "   ___|___|___" << endl;
    cout << " 3  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "      |" << "   |" << endl;


}

bool HaydenGame::gameStatus(char player) {

    winner = ' ';
    bool alert = false;

    if ((board[0][0] == player) && (board[0][1] == player) && (board[0][2] == player)) {
        winner = player;
        alert = true;
    }
    else if ((board[0][0] == player) && (board[1][0] == player) && (board[2][0] == player)) {
        winner = player;
        alert = true;
    }
    else if ((board[0][1] == player) && (board[1][1] == player) && (board[2][1] == player)) {
        winner = player;
        alert = true;
    }
    else if ((board[0][2] == player) && (board[1][2] == player) && (board[2][2] == player)) {
        winner = player;
        alert = true;
    }
    else if ((board[1][0] == player) && (board[1][1] == player) && (board[1][2] == player)) {
        winner = player;
        alert = true;

    }
    else if ((board[2][0] == player) && (board[2][1] == player) && (board[2][2] == player)) {
        winner = player;
        alert = true;
    }
    else if ((board[0][2] == player) && (board[1][1] == player) && (board[2][0] == player)) {
        winner = player;
        alert = true;
    }
    else if ((board[0][0] == player) && (board[1][1] == player) && (board[2][2] == player)) {
        winner = player;
        alert = true;
    }

    return alert;

}
bool HaydenGame::isValidMove() {

    bool gameResult = false;

    if (m_XO <= 3 && m_OX <= 3) {
        gameResult = true;
    }
    else {
        gameResult = false;
    }

    return gameResult;
}
bool HaydenGame::isFull() {
    if (board[m_XO - 1][m_OX - 1] == 'X' || board[m_XO - 1][m_OX - 1] == 'O') {
        return true;
    }
    else {
        return false;
    }
}
void HaydenGame::getXOMove(int XO, int OX) {
    m_XO = XO;
    m_OX = OX;


}

HaydenGame::HaydenGame() {
    m_XO = 0;
    m_OX = 0;

    char board[3][3] =
    {
      {' ',' ',' '},
      {' ',' ',' '},
      {' ',' ',' '},
    };

}
