#include "Exceptions.h"

FileException::FileException(const std::string& msg) : message (msg)
{}

const char* FileException::what()
{
	return message.c_str();
}

DuplicateMovieException::DuplicateMovieException()
{
	message = "There is another movie with the same name and year!";
}

const char* DuplicateMovieException::what()
{
	return message.c_str();
}

InexistentMovieException::InexistentMovieException()
{
	message = "There are no movies with that name and year!";
}

const char* InexistentMovieException::what()
{
	return message.c_str();
}
