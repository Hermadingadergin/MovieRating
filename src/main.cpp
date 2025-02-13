#include "movie.h"
#include "movie_factory.h"
#include <iostream>
#include <vector>
#include <limits>
#include <string>

Movie* FindHighestRatedMovie(std::vector<Movie*> movielist)
{
	if (movielist.size() < 1)
	{
		throw std::invalid_argument{"No movies"};
	}
	Movie* highestrated = movielist[0]; // sets initial highest rated movie as the first
	for (size_t i = 0; i < movielist.size(); i++)
	{
		if (highestrated->GetRating() < movielist[i]->GetRating()) // if the ith movie has a higher rating, set as new highest rated
		{
			highestrated = movielist[i];
		}
	}
	return highestrated;
}

double CalculateAverageRuntime(std::vector<Movie*> movielist)
{
	if (movielist.size() < 1) // must have at least 1 movie
	{
		throw std::invalid_argument{ "No movies" };
	}
	double sum = 0;
	for (size_t i = 0; i < movielist.size(); i++) // sums up all of the movie runtimes
	{
		sum += movielist[i]->GetRunTime();
	}
	return sum / movielist.size(); // divides by the length of the movie list, then returns
}

int main()
{
	std::vector<std::string> titles{ "Movie 1", "Movie 2", "Movie 3", "Movie 4", "Movie 5" };
	std::vector<std::string> directors{ "Director 1", "Director 2", "Director 3", "Director 4", "Director 5" };
	std::vector<int> runtimes{ 140, 175, 150, 160, 140 };
	std::vector<int> ids{ 1, 2, 3, 4, 5 };
	std::vector<double> ratings{ 9.1, 9.2, 9.0, 8.8, 8.9 };

	std::vector<Movie*> movies = CreateMovies(titles, directors, runtimes, ids, ratings);
	
	Movie highest_rated{*FindHighestRatedMovie(movies)};
	double average_runtime{ CalculateAverageRuntime(movies)};

	highest_rated.PrintMovieData();
	std::cout << "The average runtime is " + std::to_string(average_runtime);

}