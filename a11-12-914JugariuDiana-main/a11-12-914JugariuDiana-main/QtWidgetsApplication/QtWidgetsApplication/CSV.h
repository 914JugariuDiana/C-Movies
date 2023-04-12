#pragma once
#include "File.h"
#include <string>

class CSV : public File
{
public:
	/*
		Writes the playlist to file.
		Throws: FileException - if it cannot write.
	*/
	void writeToFile() override;

	/*
		Displays the playlist using Microsof Excel.
	*/
	void displayPlaylist() const override;
};

