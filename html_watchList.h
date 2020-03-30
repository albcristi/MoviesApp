#pragma once
#include "FileWatchList.h"

class html_watchList : public FileWatchList
{
public:
	html_watchList(const std::string& file) : FileWatchList{ file } {};

	void write_file() override;

	void openFileWithWatchList() override;
};

