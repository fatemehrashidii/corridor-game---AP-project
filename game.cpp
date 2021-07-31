#include <iostream>
#include <string>
#include "headers.h"

using namespace std;

int main() {
    // number of players
    int number_of_players;
    cin >> number_of_players;
    CORRIDOR corridor(number_of_players);

    // set the board
    corridor.set_board(number_of_players);

    //print the board befor start
    corridor.print_board();
    
    // this loop continues untill the game ends
    while (corridor.board[60] == "     ")
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
            if(corridor.valid_place(start,destination))
            {
                cout<<endl;
                // swapping
                string tmp = corridor.board[start];
                corridor.board[start] = corridor.board[destination];
                corridor.board[destination] = tmp;
                system("cls");
                corridor.print_board();

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
            if (corridor.valid_wall(first_wall, second_wall))
            {
                corridor.board[first_wall] = corridor.board[second_wall] = "~~~~~~";
                system("cls");
                corridor.print_board();
            } // end if
            else
            {
                cout << "invalid place to put walls !!" << endl;
            }
        } // end if
    } // end loop
    
    // the winner
    if (corridor.board[60] != "      ")
    {
        cout << corridor.board[60].substr(2, 1) << " won the game!" << endl;
    }
} // end main