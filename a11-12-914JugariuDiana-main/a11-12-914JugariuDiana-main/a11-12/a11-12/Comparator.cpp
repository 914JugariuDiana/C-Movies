#include "Comparator.h"
#include <string>


CompareByYear::CompareByYear()
{
}

bool CompareByYear::compare(const Movie& a, const Movie& b)
{
    if (a.getYear() < b.getYear())
        return false;
    return true;
}

CompareByYear::~CompareByYear()
{
}

CompareByTitle::CompareByTitle()
{
}

bool CompareByTitle::compare(const Movie& a, const Movie& b)
{
    if (a.getTitle().compare(b.getTitle()) < 0)
        return false;
    return true;
}

CompareByTitle::~CompareByTitle()
{
}

Comparator::Comparator()
{
}

Comparator::~Comparator()
{
}
