#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <vector>
#include <limits>


class Movie
{
private:
    int id;

    std::string title;
    std::string director;
    int runtime; // runtime in minutes >= 0
    double rating; // range 0-10
public:
    void PrintMovieData();
    Movie(std::string t, std::string d, int r, int i, double rate);
    std::string GetTitle(); // returns title
    std::string GetDirector(); // returns director
    double GetRating(); // returns rating
    int GetRunTime(); // returns runtime

};

#endif