#pragma once
#include "FileWatchList.h"
#include <Windows.h>

class csv_watchList : public FileWatchList
{
public:
	csv_watchList(const std::string& file) : FileWatchList{ file } {};

	//write in a file the content of the watchList
	void write_file() override;

	//open the file 
	void openFileWithWatchList() override;
};


