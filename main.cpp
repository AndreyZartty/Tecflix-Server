#include <iostream>
#include "CurlObj.h"
#include "Data.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    string address = "https://www.imdb.com/trailers/?ref_=nv_mv_tr";
    CurlObj temp(address);
    try {
        Data* data = new Data("IT", temp.getData());
        data->printData();
    } catch (std::exception e) {
        cout << "\n" << "IT" << " is not a valid ticker." << endl;
    }
}