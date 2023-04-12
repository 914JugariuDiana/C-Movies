#pragma once
#include <exception>
#include <string>

class FileException : public std::exception
{
protected:
	std::string message;

public:
	FileException(const std::string& msg);
	virtual const char* what();
};

class DuplicateMovieException : public std::exception
{
protected:
	std::string message;
public:
	DuplicateMovieException();
	virtual const char* what();
};

class InexistentMovieException : public std::exception
{
protected:
	std::string message;
public:
	InexistentMovieException();
	virtual const char* what();
};