#include <iostream>
#include <string>
#include "headers.h"

using namespace std;

CORRIDOR :: CORRIDOR(int n) {
    players = n;
}

void CORRIDOR :: set_board(int num) {
    // 2 players :
    if (num == 2) {
        board[0]   = "**A**";
        board[10]  = "**B**";
    }
    // 3 players :
    else if (num == 3) {
        board[0]   = "**A**";
        board[10]  = "**B**";
        board[110] = "**C**";

    }
    //4 players :
    else if (num == 4) {
        board[0]   = "**A**";
        board[10]  = "**B**";
        board[110] = "**C**";
        board[120] = "**D**";
    }
}

void CORRIDOR :: print_board() {
    for (int i = 0 ; i < 66 ; i++)
        std :: cout << "-";
    std :: cout << std :: endl;
    for (int i = 0 ; i < 11 ; i++)
    {
        for (int j = 0 ; j < 11 ; j++)
        {
            if (j != 10)
            {
                std :: cout << "|" << board[i*11 + j] ;
            }
            else
                std :: cout << "|" << board[i*11 + j] << "|";
        }
        std :: cout << std :: endl;
        {
            for (int j = 0 ; j < 66 ; j++)
            {
                std :: cout << "-";
            }
        }
        std :: cout << std :: endl;
    }
}
// function to check if a move is valid or not
bool CORRIDOR :: valid_place(int i, int j)
{
    // board[i] : start | board[j] : destination
    // if board[i] == "     " ---> there is nothing to move!
    // if board[j] != "     " ---> the place is blocked.
    if (board[i] == "     " || board[j] != "     ")
        return false;
    // moving forward
    if (j == i + 1)
    {
        // check if it goes to the next line or not
        if (j % 11 == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    // moving backward
    else if (j == i -1)
    {
        // check if it goes to the privios line or not
        if (i % 11 == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    // moving up/down
    else if ((j == i+11) || (j == i-11))
        return true;
    // anywhere else
    else 
        return false;
}
// function to check if it's valid to put the wall or not
bool CORRIDOR :: valid_wall(int i, int j)
{
    // rules: target blocks and the center block couldn't be full
    if (board[i] != "     " || board[j] != "     " || i == 60 || j == 60)
        return false;
    // if chosen blockes are next to each other, we can put walls
    if (j == i+1 || j == i-1 || j == i+11 || j == i-11)
        return true;
    else 
        return false;
}