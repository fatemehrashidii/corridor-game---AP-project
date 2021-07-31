#include <iostream>
#include <string>
#include "headers.h"

using namespace std;

int main() {
    // number of players
    int number_of_players;
    cin >> number_of_players;
    corridor C(number_of_players);

    // set the board
    C.set_board(number_of_players);

    //print the board befor start
    C.print_board();
    
    // this loop continues untill the game ends
    while (C.board[60] == "     ")
    {
        // ask if a user wants to put walls or move
        cout << "press (W) to put walls or (M) to move on." << endl;
        char choice;
        cin >> choice;
        // if a player wants to move:
        if(choice == 'M')
	    {
            // get start and destionation position from the user
            int start,destination;
            cin >> start >> destination;
            // check if the destination is valid or not
            if(C.valid_place(start,destination))
            {
                cout<<endl;
                // swapping
                string tmp = C.board[start];
                C.board[start] = C.board[destination];
                C.board[destination] = tmp;
                system("cls");
                C.print_board();

            } // end if
            else
            {
                cout<<"invalid move !!"<<endl;
            }
    	} // end if

        // if a player wants to put walls:
        if (choice == 'W')
        {
            int first_wall, second_wall;
            cin >> first_wall >> second_wall;
            // check if the blockes are empty to block 
            if (C.valid_wall(first_wall, second_wall))
            {
                C.board[first_wall] = C.board[second_wall] = "~~~~~~";
                system("cls");
                C.print_board();
            } // end if
            else
            {
                cout << "invalid place to put walls !!" << endl;
            }
        } // end if
    } // end loop
    
    // the winner
    if (C.board[60] != "      ")
    {
        cout << C.board[60].substr(2, 1) << " won the game!" << endl;
    }
} // end main