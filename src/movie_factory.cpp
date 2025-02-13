#include <iostream>
#include <vector>
#include <limits>

#include "movie_factory.h"

std::vector<Movie*> CreateMovies(std::vector<std::string> titles, std::vector<std::string> directors, std::vector<int> runtime, std::vector<int> ids, std::vector<double> ratings)
{
	if (titles.size() == directors.size() && directors.size() == runtime.size() && runtime.size() == ids.size() && ids.size() == ratings.size()) // checks to make sure all arguments have the same length
	{
		std::vector<Movie*> movielist;

		for (size_t i = 0; i < titles.size(); i++)
		{
			Movie* newmovie = new Movie(titles[i], directors[i], runtime[i], ids[i], ratings[i]); // creates a pointer to a movie
			movielist.push_back(newmovie); // pushes the movie to the back of vector movielist
		}
		return movielist;
		
	}
	else
	{
		throw std::invalid_argument("There is a mismatch in argument sizes.");
	}

}