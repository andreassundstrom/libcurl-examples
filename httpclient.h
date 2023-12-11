#ifndef httpclient_h
#define httpclient_h

#include <string>
class HttpClient{
    public:
        std::string GetAsString(char *url);
};

#endif // httpclient_h