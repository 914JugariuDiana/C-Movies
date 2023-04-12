#pragma once
#include "Movie.h"

class Comparator {
public:
	Comparator();
	virtual bool compare(const Movie& a, const Movie& b) = 0;
	~Comparator();
};

class CompareByYear : Comparator {
public:
	CompareByYear();
	bool compare(const Movie& a, const Movie& b) override;
	~CompareByYear();
};

class CompareByTitle : Comparator {
public:
	CompareByTitle();
	bool compare(const Movie& a, const Movie& b) override;
	~CompareByTitle();
};