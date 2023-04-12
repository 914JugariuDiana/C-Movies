#include "PlayList.h"


Playlist::Playlist()
{
	this->current = 0;
}

void Playlist::add(const Movie& movie)
{
	this->movies.push_back(movie);
}

Movie Playlist::getCurrentMovie()
{
	if (this->current == this->movies.size())
		this->current = 0;
	return this->movies[this->current];
	return Movie{};
}

void Playlist::play()
{
	if (this->movies.size() == 0)
		return;
	this->current = 0;
	Movie currentMovie = this->getCurrentMovie();
	currentMovie.play();
}

void Playlist::next()
{
	if (this->movies.size() == 0)
		return;
	this->current++;
	Movie currentMovie = this->getCurrentMovie();
	currentMovie.play();
}

bool Playlist::isEmpty()
{
	return this->movies.size() == 0;
}

void Playlist::remove(const Movie& movie)
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

