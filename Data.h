//
// Created by andreyzartty on 17/09/19.
//

#ifndef TECFLIX_SERVER_DATA_H
#define TECFLIX_SERVER_DATA_H

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Data {
private:
    string html;
    string movie;
    string name;


public:
    Data (string NAME, string HTML);
    void fillData();
    void printData();
};


#endif //TECFLIX_SERVER_DATA_H
