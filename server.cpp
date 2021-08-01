#include <iostream>
#include <string>
#include "httplib.h"
#include "headers.h"


int main() {

    httplib :: Server srv;

    srv.Post("/Start", [&](const auto & req, auto &res) {
    res.set_content("client is connectd.", "text/plain");
    const auto& file = req.get_file_value("Start");
    string pl1 = file.filename;
	string pl2 = file.content_type;
    cout << pl1 << "\n" << pl2 << "\n";
    
    });



    std::cout << "start server..." << std::endl;
    srv.listen("127.0.0.1", 8000);

}
