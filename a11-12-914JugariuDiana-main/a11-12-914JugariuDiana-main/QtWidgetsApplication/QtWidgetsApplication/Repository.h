#pragma once
#include <vector>
#include "Movie.h"
#include "Exceptions.h"
#include <fstream>
#include "Utils.h"

using namespace std;

class Repository {
private:
	vector<Movie> movies;
	string fileName;
public:
	/// <summary>
	/// Default constructor
	/// </summary>
	Repository(const string& fileName);
	/// <summary>
	/// Adds a movie to the  repository
	/// </summary>
	/// <param name="movie">Movie</param>
	void addMovie(const Movie& movie);
	/// <summary>
	/// Fins a movie, by name and year
	/// </summary>
	/// <param name="name"Movie name></param>
	/// <param name="year">Movie release year</param>
	/// <returns>The movie that was found, or an "empty" movie</returns>
	Movie findByTitleAndYear(const std::string title, const int year);
	/// <summary>
	/// Function updates a movie
	/// </summary>
	/// <param name="function"></param>
	void updateMovieString(Movie& movie, void (Movie::*function)(std::string), std::string value);
	/// <summary>
	/// Function updates a movie
	/// </summary>
	/// <param name="function"></param>
	void updateMovieInteger(Movie& movie, void (Movie::* function)(int), int value);
	/// <summary>
	/// Delete a movie from the repository
	/// </summary>
	/// <param name="movie"></param>
	void removeMovie(const Movie& movie);
	/// <summary>
	/// Returns all the movies
	/// </summary>
	/// <returns>Dynamic vector containing all the movies </returns>
	vector<Movie> getMovies() const { return movies; }
	/// <summary>
	/// Returns number of movies in repo
	/// </summary>
	/// <returns>number of movies in repo</returns>
	int getSize() const { return this->movies.size(); }
private:
	void readFromFile();
	void writeToFile();
};
