#include "CSV.h"
#include <fstream>
#include <Windows.h>

using namespace std;

void CSV::writeToFile()
{
	ofstream g(fileName);

	if (!g.is_open())
		throw FileException("The file could not be opened!");

	for (auto m : this->movies)
	{
		g << m.getTitle() << ",";
		g << m.getGenre() << ",";
		g << m.getTrailer() << ",";
		g << m.getYear() << ",";
		g << m.getNumberLikes() << "\n";
	}

	g.close();
}

void CSV::displayPlaylist() const
{
	string aux = "\"" + this->fileName + "\""; 
	ShellExecuteA(NULL, NULL, "C:\\Program Files\\Microsoft Office\\root\\Office16\\EXCEL.EXE", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}
