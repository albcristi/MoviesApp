#include "html_watchList.h"
#include <fstream>
#include <Windows.h>
#include <shellapi.h>



void html_watchList::write_file()
{
	std::ofstream delContent(this->fileName, std::ios::trunc);
	delContent.close();

	std::ofstream htmlStream(this->fileName, std::ios::app);

	//save the wachtch list in HTML format
	htmlStream << "<!DOCTYPE html> \n" << "<html> \n";
	htmlStream << "<head>\n" << " <title> Watch List </title> \n" << "</head>\n";
	htmlStream << "<body>\n" << "<table border=\"1\" bgcolor=\"#A9D0F5\" align=\"center\">\n";
	htmlStream << "<tr>\n <td>Name</td>\n" << "<td>Genre</td>\n" << " <td>Year of Release</td>\n" << " <td>Number of likes</td>\n" << "<td>Link to the trailer</td>\n </tr>\n ";

	for (auto mov : this->watchList) {
		htmlStream << "<tr>\n";
		htmlStream << "<td>" << mov.getName() << "</td> \n";
		htmlStream << "<td>" << mov.getGenre() << "</td> \n";
		htmlStream << "<td>" << mov.getYear() << "</td> \n";
		htmlStream << "<td>" << mov.getLikes() << "</td> \n";
		htmlStream << "<td><a href=" << '"' << mov.getTrailer() << '"' << ">Link</a></td> \n";
		htmlStream << "</tr> \n";
	}

	htmlStream << "</table>\n" << "</body> \n" << "</html> \n";
	htmlStream.close();

}

void html_watchList::openFileWithWatchList()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->fileName.c_str(), NULL, SW_SHOWMAXIMIZED);
}
