//
// Created by andreyzartty on 17/09/19.
//

#include "CSVreader.h"

CSVreader::CSVreader(string location) {
    dataset.open(location);
    setLink();
    dataset.close();

    Dataset.open(location);
    writeCSV(link);
    Dataset.close();
}

void CSVreader::setLink() {
    getline(dataset,link, '\n');

    string temp;
    size_t index = link.find(",");
    temp = link.substr(index+1);
    link = temp;

    cout << link << endl;


}

void CSVreader::writeCSV(string url) {

    Dataset << "Link" << "," << "https://www.imdb.com/trailers/?ref_=nv_mv_tr" << endl;

    Dataset << endl;

    Dataset << "Title and Year" << "," << "Description" << "," << "Director" << "," << "Actors" << "," << "For Adults?" << "," << "Poster" << "," << "Trailer" << endl;

    Dataset << endl;

    CurlObj dataHTML(url);
    html = dataHTML.getData();


    string Inicio = "imdbTrailerJson";

    string Fin = "}}";

    size_t indexInicio = html.find(Inicio);


    string Html_info = html.substr(indexInicio);

    html = Html_info;

    size_t indexFin = html.find(Fin);

    Html_info = html.substr(0,indexFin+2);

    html = Html_info;

    indexInicio = html.find(":");

    html = html.substr(indexInicio+1);

    while (html.length() > 2){
        size_t newMovie = html.find("}");

        string movie = html.substr(0, newMovie+1);

        html = html.substr(newMovie+1);

        string title;
        string description;
        string director;
        string actors;
        string adults;
        string poster;
        string trailer;

        ///Para columna Adult

        size_t search = movie.find("adult");

        string current = movie.substr(search+5);

        movie = current;

        search = movie.find(":");

        current = movie.substr(search+1);

        movie = current;

        search = movie.find(",");

        current = movie.substr(0, search);

        adults = current;

        movie = movie.substr(search+1);

        /// Para columna Description

        search = movie.find("description");

        current = movie.substr(search+11);

        movie = current;

        search = movie.find(":");

        current = movie.substr(search+2);

        movie = current;

        search = movie.find("directorNames");

        current = movie.substr(0, search-3);

        description = current;


        /// Para columna Director


        search = movie.find("directorNames");

        current = movie.substr(search+13);

        movie = current;

        search = movie.find(":");
        size_t search2 = movie.find(",");


        if ((search2 - search) > 4) {

            current = movie.substr(search+3);

            movie = current;

            search = movie.find(",");

            current = movie.substr(0, search-2);
        }
        else{
            current = "Not Found";
        }
        director = current;

        movie = movie.substr(search2+1);

        /// Para columna Poster

        search = movie.find("posterUrl");

        current = movie.substr(search+9);

        movie = current;

        search = movie.find(":");

        current = movie.substr(search+2);

        movie = current;

        search = movie.find(",");

        current = movie.substr(0, search-1);

        if(current.length()< 2){
            current = "Not Found";
        }

        poster = current;

        movie = movie.substr(search+1);

        /// Para columna Actors

        search = movie.find("starNames");

        current = movie.substr(search+9);

        movie = current;

        search = movie.find(":");

        current = movie.substr(search+1);

        movie = current;

        search = movie.find("]");

        current = movie.substr(0, search+1);

        actors = current;

        movie = movie.substr(search+2);

        /// Para columna Title and Year

        search = movie.find("titleNameWithYear");

        current = movie.substr(search+17);

        movie = current;

        search = movie.find(":");

        current = movie.substr(search+2);

        movie = current;

        search = movie.find(",");

        current = movie.substr(0, search-1);

        title = current;

        movie = movie.substr(search+1);

        /// Para columna Trailer


        search = movie.find("videoUrl");

        current = movie.substr(search+8);

        movie = current;

        search = movie.find(":");

        current = movie.substr(search+2);

        movie = current;

        search = movie.find("}");

        current = movie.substr(0, search-1);

        trailer = "https://www.imdb.com" + current;

        movie = movie.substr(search+1);

        size_t Actors = actors.find(",");

        size_t Title = title.find(",");

        size_t Descp = description.find(",");

        size_t Actors1 = actors.find(";");

        size_t Title1 = title.find(";");

        size_t Descp1 = description.find(";");

        while(Title < title.length()){

            title.replace(Title,1," ");
            Title = title.find(",");
        }

        while (Title1 < title.length()){
            title.replace(Title1,1," ");
            Title1 = title.find(";");
        }

        while(Actors < actors.length()){

            actors.replace(Actors,1," ");
            Actors = actors.find(",");
        }

        while (Actors1 < actors.length()){
            actors.replace(Actors1,1," ");
            Actors1 = actors.find(";");
        }

        while(Descp < description.length()){

            description.replace(Descp,1," ");
            Descp = description.find(",");
        }

        while (Descp1 < description.length()){
            description.replace(Descp1,1," ");
            Descp1 = description.find(";");
        }


        Dataset << title << "," << description << "," << director << "," << actors << "," << adults << "," << poster << "," << trailer << endl;

    }
}
