#include <iostream>
#include <curl/curl.h>
#include <string>
size_t CallbackFn(void *contents, size_t size, size_t nmemb, std::string *s){
    size_t newLength = size*nmemb;
    s->append((char*)contents, newLength);
    return newLength;
}

int main(int argc, char *argv[]) {
    CURL *curl;
    CURLcode res;

    std::cout << argv[1] << std::endl;

    std::string response_data;

    curl = curl_easy_init();
    if(curl){
        curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, CallbackFn);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);
        
        res = curl_easy_perform(curl);

        std::cout << response_data;

        if(res != CURLE_OK){
            curl_easy_cleanup(curl);
        }
    } 
    curl_global_cleanup();
    return 0; 
}
