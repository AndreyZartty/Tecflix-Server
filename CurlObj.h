//
// Created by andreyzartty on 17/09/19.
//

#ifndef TECFLIX_SERVER_CURLOBJ_H
#define TECFLIX_SERVER_CURLOBJ_H


#include <iostream>
#include <curl/curl.h>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;


class CurlObj {

public:
    CurlObj (string url);

    static int curlWriter(char *data, int size, int nmemb, string *buffer);

    string getData();

protected:
    CURL * curl;
    string curlBuffer;
};

#endif //TECFLIX_SERVER_CURLOBJ_H
