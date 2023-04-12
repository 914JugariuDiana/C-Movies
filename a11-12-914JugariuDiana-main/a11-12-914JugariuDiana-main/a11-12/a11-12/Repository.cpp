#include "Repository.h"

using namespace std;

Repository::Repository(const string& fileName)
{
	this->fileName = fileName;
	readFromFile();
}

void Repository::addMovie(const Movie& movie)
{
	this->movies.push_back(movie);
}

Movie Repository::findByTitleAndYear(const std::string title, const int year)
{
	for (auto movie : movies)
	{
		if (movie.getTitle() == title && movie.getYear() == year)
			return movie;
	}

	return Movie{};
}

void Repository::updateMovieString(Movie& movie, void (Movie::*function)(std::string), std::string value)
{
	for (auto m = movies.begin(); m != movies.end(); ++m)
		if (*m == movie)
			(*m.*function)(value);
}

void Repository::updateMovieInteger(Movie& movie, void(Movie::* function)(int), int value)
{
	for (auto m = movies.begin(); m != movies.end(); ++m)
		if (*m == movie)
			(*m.*function)(value);
}

void Repository::removeMovie(const Movie& movie)
{
	int i = 0;
	bool found = false;
	while (i < this->movies.size() and found == false)
	{
		if (movies[i] == movie)
		{
			found = true;
			this->movies.erase(movies.begin() + i);
		}
		i++;
	}
}

void Repository::readFromFile()
{
	ifstream f(this->fileName);

	if (!f.is_open())
		throw FileException("The file could not be opened!");

	std::string title;
	std::string genre;
	std::string trailer;
	int year, numberOfLikes;

	while (getline(f, title))
	{
		getline(f, genre);
		getline(f, trailer);
		f >> year;
		f >> numberOfLikes;
		Movie m{ title, genre, trailer, year, numberOfLikes };
		addMovie(m);
		getline(f, genre);
	}
	f.close();

	f.close();
}

void Repository::writeToFile()
{
	ofstream g(fileName);
	if (!g.is_open())
		throw FileException("The file could not be opened!");

	for (auto m : this->movies)
	{
		g << m.getTitle() << "\n";
		g << m.getGenre() << "\n";
		g << m.getTrailer() << "\n";
		g << m.getYear() << "\n";
		g << m.getNumberLikes() << "\n";
	}

	g.close();
}

