#pragma once
#include "MovieWatchList.h"

class FileWatchList : public MovieWatchList
{
protected:

	std::string fileName;
public:
	//constructor
	FileWatchList(const std::string& file);

	//destructor
	virtual  ~FileWatchList();

	virtual void write_file() = 0;

	virtual void openFileWithWatchList() = 0;
};

