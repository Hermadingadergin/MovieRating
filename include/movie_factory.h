#ifndef MOVIE_FACTORY_H
#define MOVIE_FACTORY_H

#include <iostream>
#include <vector>
#include <limits>   
#include <movie.h>

//class Movie_Factory
//{
/*
Write function declaration CreateMovies() that
accepts (attributes in the below order)
  vector of titles,
  vector of directors,
  vector of runtimes,
  vector of ids,
  vector of ratings and
return
  vector of pointers of Movie objects
*/
//public:
	std::vector<Movie*> CreateMovies(std::vector<std::string> titles, std::vector<std::string> directors, std::vector<int> runtime, std::vector<int> ids, std::vector<double> ratings);
//};

#endif