#include <iostream>
#include <httplib.h>

using namespace std;

int main() {
    using namespace httplib;
    Client cli("127.0.0.1", 8000);

    if (auto res = cli.Get("/start")) {
        if (res->status == 200) {
            while (true) {
    string temp;
    cin >> temp;
        auto res = cli.Post("/p1", temp, "text/plain");

    
        //cout << res->status << std::endl;
        cout << res->body << std::endl;
            }
    }
    }

    

    

}