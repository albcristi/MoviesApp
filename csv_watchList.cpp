#include "csv_watchList.h"
#include <fstream>
#include <shellapi.h>


void csv_watchList::write_file()
{
	std::ofstream delContent(this->fileName, std::ios::trunc);
	delContent.close();

	std::ofstream csvStream(this->fileName, std::ios::app);

	for (auto mov : this->watchList) {
		csvStream << mov;
	}

	csvStream.close();
}

void csv_watchList::openFileWithWatchList()
{
	ShellExecuteA(NULL, NULL, "notepad.exe", this->fileName.c_str(), NULL, SW_SHOWMAXIMIZED);
}
