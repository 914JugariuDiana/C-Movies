#pragma once
#include "File.h"
#include <string>
#include <Windows.h>

class Html : public File
{
public:
	/*
		Writes the playlist to file.
		Throws: FileException - if it cannot write.
	*/
	void writeToFile() override;

	/*
		Displays the playlist.
	*/
	void displayPlaylist() const override;
};

