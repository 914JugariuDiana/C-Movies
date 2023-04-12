#pragma once
#include <vector>
#include "Movie.h"
#include "Exceptions.h"

class Playlist
{
protected:
	std::vector<Movie> movies;
	int current;

public:
	Playlist();

	// Adds a movie to the playlist.
	void add(const Movie& movie);

	// Returns the movie that is currently playing.
	Movie getCurrentMovie();

	// Starts the playlist - plays the first movie.
	void play();

	// Plays the next movie in the playlist.
	void next();

	// Checks if the playlist is empty.
	bool isEmpty();

	std::vector<Movie> getMovies() const { return this->movies; }

	void remove(const Movie& movie);

	virtual ~Playlist() {}
};

