#include "Service.h"
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>
#include "Exceptions.h"


void Service::add(std::string& title, std::string& genre, std::string& trailer, int year, int numberLikes)
{
	Movie movie{ title, genre, trailer, year, numberLikes };
	Movie m = this->repo.findByTitleAndYear(title, year);
	if (m == movie)
		throw DuplicateMovieException{};
	this->repo.addMovie(movie);
}

void Service::remove(std::string& title, int year)
{
	Movie m = this->repo.findByTitleAndYear(title, year);
	if (m == Movie{})
		throw InexistentMovieException{};
	this->repo.removeMovie(m);
}

void Service::updateMovieString(std::string& title, int year, std::string& updatedValue, int updater)
{
	Movie m = this->repo.findByTitleAndYear(title, year);
	if (m == Movie{})
		throw InexistentMovieException{};
	switch (updater)
	{
		case 1:
		{
			this->repo.updateMovieString(m, &Movie::setTitle, updatedValue);
			break;
		}
		case 2:
		{
			this->repo.updateMovieString(m, &Movie::setGenre, updatedValue);
			break;
		}
		case 3:
		{
			this->repo.updateMovieString(m, &Movie::setTrailer, updatedValue);
			break;
		}
	}
}

void Service::updateMovieInteger(std::string& title, int year, int updatedValue, int updater)
{
	Movie m = this->repo.findByTitleAndYear(title, year);
	if (m == Movie{})
		throw InexistentMovieException{};
	switch (updater)
	{
		case 1:
		{
			this->repo.updateMovieInteger(m, &Movie::setYear, updatedValue);
			break;
		}
		case 2:
		{
			this->repo.updateMovieInteger(m, &Movie::setNumberLikes, updatedValue);
			break;
		}
	}
}

void Service::savePlaylist()
{
	if (this->playlist == nullptr)
		return;

	this->playlist->writeToFile();
}

void Service::openPlaylist() const
{
	if (this->playlist == nullptr)
		return;

	this->playlist->displayPlaylist();
}

void Service::addAllMoviesWithGenreToPlaylist(const string& genre)
{
	vector<Movie> movies, filteredList;

	movies = this->repo.getMovies();

	filteredList = vector<Movie>();
	copy_if(movies.begin(), movies.end(), std::back_inserter(filteredList), [&genre](const Movie& m) {return m.getGenre() == genre; });
	if (filteredList.size() == 0)
		copy(movies.begin(), movies.end(), std::back_inserter(filteredList));
	
	for (auto m : filteredList)
		this->playlist->add(m);
}

void Service::startPlaylist()
{
	if (this->playlist == nullptr)
		return;
	this->playlist->play();
}

void Service::nextPlaylist()
{
	if (this->playlist == nullptr)
		return;
	this->playlist->next();
}

void Service::order(vector<Movie>& movies, Comparator* compare)
{
	Movie m;
	bool ok = true;
	while (ok)
	{
		ok = false;
		for (auto i = 0; i < movies.size() - 1; i++)
			if (!compare->compare(movies[i], movies[i + 1]))
			{
				ok = true;
				m = movies[i];
				movies[i] = movies[i + 1];
				movies[i + 1] = m;
			}
	}
}

void Service::addToPlaylist(Movie movie)
{
	Movie m = this->repo.findByTitleAndYear(movie.getTitle(), movie.getYear());
	/*if (m == movie)
		throw DuplicateMovieException{};*/
	this->playlist->add(movie);
}

void Service::removeFromPlaylist(const Movie& movie)
{
	playlist->remove(movie);
}
