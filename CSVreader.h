//
// Created by andreyzartty on 17/09/19.
//

#ifndef TECFLIX_SERVER_CSVREADER_H
#define TECFLIX_SERVER_CSVREADER_H

#include <string>
#include <iostream>
#include <fstream>
#include "CurlObj.h"


using namespace std;


class CSVreader {

public:

    CSVreader(string location);
    void setLink();
    void writeCSV(string url);

private:

    ifstream dataset;
    string link;
    ofstream Dataset;

    string html;

};


#endif //TECFLIX_SERVER_CSVREADER_H
