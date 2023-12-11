#include <curl/curl.h>

#include "httpclient.h"

size_t CallbackFn(void *contents, size_t size, size_t nmemb, std::string *s){
    size_t newLength = size*nmemb;
    s->append((char*)contents, newLength);
    return newLength;
}

std::string HttpClient::GetAsString(char *url){
    CURL *curl;
    CURLcode res;

    std::string response_data;

    curl = curl_easy_init();
    if(curl){
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, CallbackFn);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);
        
        res = curl_easy_perform(curl);


        if(res != CURLE_OK){
            curl_easy_cleanup(curl);
        }
    } 
    curl_global_cleanup();

    return response_data;
} 