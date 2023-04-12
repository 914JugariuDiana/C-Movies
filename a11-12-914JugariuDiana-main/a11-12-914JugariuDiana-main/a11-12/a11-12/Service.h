#pragma once
#include "Repository.h"
#include "File.h"
#include "Comparator.h"

class Service
{
private:
	Repository repo;
	File* playlist;

public:
	/// <summary>
	/// Constructor for service
	/// </summary>
	/// <param name="repo"></param>
	Service(const Repository& r, File* p) : repo{ r }, playlist{ p } {}
	/// <summary>
	/// Add a movie in the repo, if it does not already exist
	/// </summary>
	/// <param name="title"></param>
	/// <param name="genre"></param>
	/// <param name="trailer"></param>
	/// <param name="year"></param>
	/// <param name="numberLikes"></param>
	/// <returns>1 if the operation was succesful, 0 otherwise </returns>
	void add(std::string& title, std::string& genre, std::string& trailer, int year, int numberLikes);
	/// <summary>
	/// Removes a movie from the reppository
	/// </summary>
	/// <param name="title">Identifier for the movie to be removed</param>
	/// <param name="year">Identifier for the movie to be removed</param>
	/// <returns>1 if the operation was succesful, 0 otherwise </returns>
	void remove(std::string& title, int year);
	/// <summary>
	/// Function updates a movie
	/// </summary>
	/// <param name="title"></param>
	/// <param name="year"></param>
	/// <param name="updatedValue"></param>
	/// <param name="updater"></param>
	/// <returns>1 if the operation was succesful, 0 otherwise</returns>
	void updateMovieString(std::string& title, int year, std::string& updatedValue, int updater);
	/// <summary>
	/// Function updates a movie
	/// </summary>
	/// <param name="title"></param>
	/// <param name="year"></param>
	/// <param name="updatedValue"></param>
	/// <param name="updater"></param>
	/// <returns>1 if the operation was succesful, 0 otherwise</returns>
	void updateMovieInteger(std::string& title, int year, int updatedValue, int updater);
	/// <summary>
	/// Gets the movies from the repo
	/// </summary>
	/// <returns>A dynamic vector containing all the movies from the repo</returns>
	Repository getRepo() const { return this->repo; }
	/// <summary>
	/// Gets the size of the list with movies
	/// </summary>
	/// <returns>The number of movies stored in the repo</returns>
	int getSize() { return this->repo.getSize(); }

	/// Add a movie in the repo, if it does not already exist
	void addToPlaylist(Movie movie);
	/// <summary>
	/// Removes a movie from the reppository
	/// </summary>
	/// <param name="title">Identifier for the movie to be removed</param>
	/// <param name="year">Identifier for the movie to be removed</param>
	/// <returns>1 if the operation was succesful, 0 otherwise </returns>
	void removeFromPlaylist(const Movie& movie);
	/// <summary>
	/// Gets the movies from the repo
	/// </summary>
	/// <returns>A dynamic vector containing all the movies from the repo</returns>
	Playlist* getPlaylist() { return this->playlist; }
	/*
		Saves the playlist.
		Throws: FileException - if the given file cannot be opened.
	*/
	void savePlaylist(const string& filename);
	/*
	Opens the playlist, with an appropriate application.
	Throws: FileException - if the given file cannot be opened.
	*/
	void openPlaylist() const;
	// Adds all the songs from the repository, that have the given artist, to the current playlist.
	void addAllMoviesWithGenreToPlaylist(const string& genre);

	void startPlaylist();
	void nextPlaylist();

	void order(vector<Movie>& movies, Comparator* comparat);
};



