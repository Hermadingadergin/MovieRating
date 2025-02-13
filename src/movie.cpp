#include <iostream>
#include <vector>
#include <limits>
#include <string>

#include "movie.h"

void Movie::PrintMovieData()
{
	std::cout << "Movie: " + GetTitle() + "\nDirector: " + GetDirector() + "\nRuntime: " + std::to_string(GetRunTime()) + "\nRatings: " + std::to_string(GetRating()) + "\n";
}
Movie::Movie(std::string t, std::string d, int r, int i, double rate)
{
	title = t;
	director = d;
	id = i;
	if (r <= 0)
	{
		throw std::invalid_argument("Runtime cannot be 0 or less.");
	}
	else
	{
		runtime = r;
	}
	if (rate < 0 || rate > 10)
	{
		throw std::invalid_argument("Rating must be between 0 and 10");
	}
	else
	{
		rating = rate;
	}

}
std::string Movie::GetTitle() // returns title
{
	return title;
}
std::string Movie::GetDirector() // returns director
{
	return director;
}
double Movie::GetRating() // returns rating
{
	return rating;
}
int Movie::GetRunTime() // returns runtime
{
	return runtime;
}