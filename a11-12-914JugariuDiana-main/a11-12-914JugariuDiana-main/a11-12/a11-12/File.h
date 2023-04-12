#pragma once
#include <iostream>
#include "Playlist.h"

class File : public Playlist
{
protected: 
	std::string fileName;
public:
	File();
	virtual ~File();

	void setFileName(const std::string& name);
	virtual void writeToFile() = 0;
	virtual void displayPlaylist() const = 0;
};
