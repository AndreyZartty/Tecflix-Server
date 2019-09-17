//
// Created by andreyzartty on 17/09/19.
//

#include "Data.h"
#include <vector>
#include <iostream>

using namespace std;

Data::Data(string NAME, string HTML) {
    name = NAME;
    //all the html of the website
    html = HTML;
    fillData();
}

void Data::fillData() {
    string changePlace = "imdbTrailerJson";

    size_t indexChg = html.find(changePlace);

    string changeS = html.substr(indexChg);

    changePlace = "It Chapter Two";

    indexChg = changeS.find(changePlace);

    changeS = changeS.substr(indexChg);

    changePlace = "videoUrl";

    indexChg = changeS.find(changePlace);

    changeS = changeS.substr(indexChg);

    changePlace = "/";

    indexChg = changeS.find(changePlace);

    changeS = changeS.substr(indexChg);

    changePlace = "}";

    indexChg = changeS.find(changePlace);

    changeS = changeS.substr(0,indexChg-1);

    movie = "imdb.com" + changeS;

}

void Data::printData() {
    cout << "\n" << name << ":" << endl;
    cout << "\tTRAILER LINK\t\t" << movie << endl;
}
