#include <iostream>
#include <vector>
#include <limits>

#include "movie_factory.h"

std::vector<Movie*> CreateMovies(std::vector<std::string> titles, std::vector<std::string> directors, std::vector<int> runtime, std::vector<int> ids, std::vector<double> ratings)
{
	//size_t argeval = (titles.size() + directors.size() + runtime.size() + ids.size() + ratings.size()) % 5;
	if (titles.size() == directors.size() && directors.size() == runtime.size() && runtime.size() == ids.size() && ids.size() == ratings.size()) // since there are 5 arguments, a valid list of arguments
	{
		std::vector<Movie*> movielist;

		for (size_t i = 0; i < titles.size(); i++)
		{
			Movie* newmovie = new Movie(titles[i], directors[i], runtime[i], ids[i], ratings[i]);
			movielist.push_back(newmovie);
		}
		return movielist;
		
	}
	else
	{
		throw std::invalid_argument("There is a mismatch in argument sizes.");
	}

}