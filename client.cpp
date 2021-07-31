#include <iostream>
#include <httplib.h>

using namespace std;

int main() {
    using namespace httplib;
    Client cli("127.0.0.1", 8000);

    auto res = cli.Get("/start");

    if (res) {
        cout << res -> status << endl;
        cout << res -> body << endl;
    }
    else {
        cout << "error: " << to_string(res.error()) << endl;   
    }

}