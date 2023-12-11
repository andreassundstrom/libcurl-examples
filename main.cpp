#include <iostream>
#include <string>

#include "httpclient.h"



int main(int argc, char *argv[]) {
    HttpClient httpclient;
    std::string response = httpclient.GetAsString(argv[1]);
    
    std::cout << argv[1] << std::endl;
    std::cout << response << std::endl;

    return 0;
}
