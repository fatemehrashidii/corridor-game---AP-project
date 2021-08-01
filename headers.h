#include <string>
#include <iostream>

using namespace std;

class corridor
{
public:
    // make the 11*11 game board
    std :: string board[121] = {
        "     ", "     ", "     ", "     ", "     ", "     ",  "     ", "     ", "     ", "     ", "     ",
        "     ", "     ", "     ", "     ", "     ", "     ",  "     ", "     ", "     ", "     ", "     ",
        "     ", "     ", "     ", "     ", "     ", "     ",  "     ", "     ", "     ", "     ", "     ",
        "     ", "     ", "     ", "     ", "     ", "     ",  "     ", "     ", "     ", "     ", "     ",
        "     ", "     ", "     ", "     ", "     ", "     ",  "     ", "     ", "     ", "     ", "     ",
        "     ", "     ", "     ", "     ", "     ", "     ",  "     ", "     ", "     ", "     ", "     ",
        "     ", "     ", "     ", "     ", "     ", "     ",  "     ", "     ", "     ", "     ", "     ",
        "     ", "     ", "     ", "     ", "     ", "     ",  "     ", "     ", "     ", "     ", "     ",
        "     ", "     ", "     ", "     ", "     ", "     ",  "     ", "     ", "     ", "     ", "     ",
        "     ", "     ", "     ", "     ", "     ", "     ",  "     ", "     ", "     ", "     ", "     ",
        "     ", "     ", "     ", "     ", "     ", "     ",  "     ", "     ", "     ", "     ", "     "
        
    };
        corridor(int);
        ~corridor();
        void set_board(int);
        void print_board();
        bool valid_place(int, int);
        bool valid_wall(int, int);

    private:
        int players;
};

// constructor
corridor :: corridor(int n) {
    players = n;
}
// distructor
corridor :: ~corridor(){
    //
}
// function to set the board game
void corridor :: set_board(int num) {
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
} // end set_board()
// function to print the board
void corridor :: print_board() {
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
} // end print_board()
// function to check if a move is valid or not
bool corridor :: valid_place(int i, int j)
{
    // board[i] : current place | board[j] : nect place
    // if board[i] == "     " ---> there is nothing to move!
    // if board[j] != "     " ---> the place is blocked.
    if (board[i] == "     " || board[j] != "     ")
        return false;
    // moving forward(right)
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
    // moving backward(left)
    else if (j == i - 1)
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
} // end valid_place()
// function to check if it's valid to put the wall or not
bool corridor :: valid_wall(int i, int j)
{
    // rules: target blocks and the center block couldn't be full
    if (board[i] != "     " || board[j] != "     " || i == 60 || j == 60 || j % 11 == 0)
        return false;
    // if chosen blockes are next to each other, we can put walls
    if (j == i+1 || j == i-1 || j == i+11 || j == i-11)
        return true;
    else 
        return false;
} // endvalid_wall