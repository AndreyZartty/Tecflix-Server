#include <iostream>
#include "CurlObj.h"
#include "Data.h"
#include "CSVreader.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    string address = "https://www.imdb.com/trailers/?ref_=nv_mv_tr";
    CurlObj temp(address);

    Data* data = new Data("IT", temp.getData());
    data->printData();


    cout << "--------------------" << endl;

    CSVreader* read = new CSVreader("/home/andreyzartty/Documentos/Proyectos/TECflix/Tecflix-Server/Dataset.csv");
}