#include "File.h"

File::File() : Playlist{}, fileName{ "" }
{
}

File::~File()
{
}

void File::setFileName(const std::string& name)
{
	this->fileName = name;
}