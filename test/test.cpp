#define CATCH_CONFIG_MAIN			// this line tells Catch to provide a main() function
#define CATCH_CONFIG_COLOUR_NONE

#include "catch2\catch.hpp"
#include "movie.h"
#include "movie_factory.h"
#include <iostream>

TEST_CASE("Test Movie Constructor and Helper Functions")
{
	Movie test("Title", "Director", 1, 1, 1);
	CHECK(test.GetTitle() == "Title");
	CHECK(test.GetDirector() == "Director");
	CHECK(test.GetRating() == 1);
	CHECK(test.GetRuntime() == 1);

	CHECK_THROWS(Movie("Title", "Director", -1, 1, 1)); // bad runtime
	CHECK_THROWS(Movie("Title", "Director", 1, 1, -1)); // bad rating
}

TEST_CASE("Test CreateMovies")
{
	// creating valid arguments for CreateMovies
	std::vector<std::string> titles = {"Title1", "Title2", "Title3"};
	std::vector<std::string> directors = { "Director1", "Director2", "Director3" };
	std::vector<int> runtime = { 1, 2, 3 };
	std::vector<int> ids = { 1, 2, 3 };
	std::vector<double> ratings = { 1, 2, 3 };
	std::vector<Movie*> listofmovies = CreateMovies(titles, directors, runtime, ids, ratings);

	// verifying that CreateMovies works
	CHECK(listofmovies[0]->GetTitle() == "Title1");
	CHECK(listofmovies[0]->GetDirector() == "Director1");
	CHECK(listofmovies[1]->GetTitle() == "Title2");
	CHECK(listofmovies[1]->GetDirector() == "Director2");
	CHECK(listofmovies[2]->GetTitle() == "Title3");
	CHECK(listofmovies[2]->GetDirector() == "Director3");
	for (int i = 0; i < 3; i++)
	{
		CHECK(listofmovies[i]->GetRuntime() == i + 1);
		CHECK(listofmovies[i]->GetRating() == i + 1);
	}

	// creating invalid arguments for CreateMovies
	std::vector<std::string> titles_i = { "Title1", "Title2", "Title3", "Title4"};
	std::vector<std::string> directors_i = { "Director1", "Director2"};
	std::vector<int> runtime_i = { 1, 2, 3, 4 };
	std::vector<int> ids_i = { 1, 2 };
	std::vector<double> ratings_i = { 1, 2, 3, 4 };

	// verifying that CreateMovies throws exceptions when given invalid arguments
	CHECK_THROWS(CreateMovies(titles_i, directors, runtime, ids, ratings)); // too many titles
	CHECK_THROWS(CreateMovies(titles, directors_i, runtime, ids, ratings)); // too few directors
	CHECK_THROWS(CreateMovies(titles, directors, runtime_i, ids, ratings)); // too many runtimes
	CHECK_THROWS(CreateMovies(titles, directors, runtime, ids_i, ratings)); // too few ids
	CHECK_THROWS(CreateMovies(titles, directors, runtime, ids, ratings_i)); // too many ratings
}
