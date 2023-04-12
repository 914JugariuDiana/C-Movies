#include "Html.h"
#include <fstream>
#include <Windows.h>

using namespace std;

void Html::writeToFile()
{
    ofstream g(fileName);

    if (!g.is_open())
        throw FileException("The file could not be opened!");

    g << "<!DOCTYPE html>\n<html>\n<head>\n     <title>playlist</title>\n</head>\n<body>\n";
    g << "<table border=\"1\">\n<tr>\n      <td>Title</td>\n      <td>Genre</td>\n      <td>Youtube link</td>\n      <td>Year</td>\n";
    g << "      <td>Number of likes</td>\n</tr>\n";

    for (auto m : this->movies)
    {
        g << "<tr>\n";
        g << "      <td>" << m.getTitle() << "</td>\n";
        g << "      <td>" << m.getGenre() << "</td>\n";
        g << "      <td><a href = \"" << m.getTrailer() << "\">Link</a></td>\n";
        g << "      <td>" << m.getYear() << "</td>\n";
        g << "      <td>" << m.getNumberLikes() << "</td>\n";
        g << "</tr>\n";
    }
        g << "</table>\n</body>\n</html>\n";
    g.close();
}

void Html::displayPlaylist() const
{
    string aux = "\"" + this->fileName + "\"";
    ShellExecuteA(NULL, NULL, "C:\\Program Files\\Opera\\launcher.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}
