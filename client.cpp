#include <iostream>
#include <httplib.h>
#include "headers.h"

using namespace std;

int main() {
    using namespace httplib;
    Client cli("127.0.0.1", 8000);

    string name;
    cout << "Enter your name/ID: ";
    cin >> name;
    MultipartFormDataItems  form = { {"Start", name,"",""} };

    int number_of_players;
    cout << "Enter number of players: ";
    cin >> number_of_players;

    corridor game(number_of_players);
    game.set_board(number_of_players);
    game.print_board();

    
    while (game.board[60] == "     ") {
        cout << "press (W) to put walls or (M) to move on." << endl;
        char choice;
        cin >> choice;

        // if a player wants to move:
        if(choice == 'M')
	    {
            string curr_place, nxt_place;
            cout << "Enter current place: " ;
            cin  >> curr_place;
            cout << "Enter next place: ";
            cin  >> nxt_place;
            cout << endl;

            form[0].name = "Start";
			form[0].filename = curr_place;
			form[0].content_type = nxt_place;
            auto res = cli.Post("/Start", form);
            


            int curr = stoi(curr_place); int nxt = stoi(nxt_place);
            if (game.valid_place(curr, nxt)) {

                    cout<<endl;
                    // swapping
                    string tmp = game.board[curr];
                    game.board[curr] = game.board[nxt];
                    game.board[nxt] = tmp;
                    system("cls");
                    game.print_board();

                } // end if
                else
                {
                    cout<<"invalid move !!"<<endl;
                }
            } // end if

        // if a player wants to put walls:
        if (choice == 'W')
        {
            //auto res = cli.Post("/wall", data);
            string first_wall, second_wall;
            cout << "Enter the first block to put a wall: ";
            cin  >> first_wall;
            cout << "Enter the second block to put a wall: ";
            cin  >> second_wall;
            int wall1 = stoi(first_wall);
            int wall2 = stoi(second_wall);
            
            // check if the blockes are empty to put walls 
            if (game.valid_wall(wall1, wall2))
            {
                game.board[wall1] = game.board[wall2] = "~~~~~";
                system("cls");
                game.print_board();
            } // end if
            else
            {
                cout << "invalid place to put walls !!" << endl;
            }
        } // end if
    }

    if (auto res = cli.Get("/Start")) {
        if (res->status == 200) {
            while (true){
                string temp;
                cin >> temp;
                auto res = cli.Post("/p1", temp, "text/plain");

    
                //cout << res->status << std::endl;
                cout << res->body << std::endl;
            }
        }
    }

    

    

}