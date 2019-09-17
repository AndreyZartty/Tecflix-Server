//
// Created by andreyzartty on 17/09/19.
//

#include "CurlObj.h"

CurlObj::CurlObj(string url) {
    curl = curl_easy_init();
    if (!curl) {
        throw string ("Curl did not initialize.");
    }

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &CurlObj::curlWriter);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &curlBuffer);
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
    curl_easy_perform(curl);
}

int CurlObj::curlWriter(char *data, int size, int nmemb, string *buffer) {
    int result = 0;
    if (buffer != NULL) {
        buffer->append(data, size * nmemb);
        result = size * nmemb;
    }

    return result;
}

string CurlObj::getData() {
    return curlBuffer;
}
