#include <iostream>
#include <httplib.h>

using namespace std;

int main() {
    using namespace httplib;
    Server srv;

    int number_of_players;
    cout << "Enter number of players: ";
    cin >> number_of_players;

    srv.Get("/start", [](const auto &, auto &res) {
    res.set_content("Enter number of players: ", "text/plain");
    });

    std::cout << "start server..." << std::endl;
    srv.listen("127.0.0.1", 8000);

}
