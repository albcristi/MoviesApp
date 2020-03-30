#include "Movie.h"
#include <sstream>

//default constructor
Movie::Movie()
	:name(" "), genre(" "), trailer(" ")
{
	this->yearOfRelease = 0;
	this->nbOfLikes = 0;
}

//constructor
Movie::Movie(std::string name, std::string genre, std::string trailer, int year, int likes)
	:name(name), genre(genre), trailer(trailer)
{
	this->yearOfRelease = year;
	this->nbOfLikes = likes;
}

//copy constructor
Movie::Movie(const Movie& copy)
	:name(copy.name), genre(copy.genre), trailer(copy.trailer), nbOfLikes(copy.nbOfLikes), yearOfRelease(copy.yearOfRelease)
{
}

//getter fct for the name
const std::string Movie::getName()
{
	return this->name;
}

//getter fct for the genre
const std::string Movie::getGenre()
{
	return this->genre;

}

//getter fct fot the trailer
const std::string Movie::getTrailer()
{
	return this->trailer;
}

//getter fct for the year of release
const int Movie::getYear()
{
	return this->yearOfRelease;
}

//getter fct for the number of likes
const int Movie::getLikes()
{
	return this->nbOfLikes;
}

//setter fct for the name
Movie& Movie::setName(std::string& name)
{
	this->name = name;
	return *this;
}

//setter fct fot the genre
Movie& Movie::setGenre(std::string& genre)
{
	this->genre = genre;
	return *this;
}

//setter fct fot the trailer
Movie& Movie::setTrailer(std::string& trailer)
{
	this->trailer = trailer;
	return *this;
}

//setter fct for the year
Movie& Movie::setYear(int year)
{
	this->yearOfRelease = year;
	return *this;
}

//setter fct for the nb of likes
Movie& Movie::setLikes(int likes)
{
	this->nbOfLikes = likes;
	return *this;

}


//equal operator ( name matching)
bool Movie::operator==(const Movie& second)
{
	return this->name == second.name;
}

// not equal operator( genre matching )
bool Movie::operator!=(const Movie& second)
{
	return this->genre != second.genre;
}

//destructor
Movie::~Movie()
{
}

std::vector<std::string> tokenize(std::string str, char delimit)
{
	std::vector<std::string> result;
	std::stringstream ss(str);
	std::string token;

	while (getline(ss, token, delimit)) {
		result.push_back(token);
	}

	return result;
}

//print object of type Movie
std::ostream& operator<<(std::ostream& os, const  Movie& toPrint)
{

	os << toPrint.name << "," << toPrint.genre << "," << toPrint.trailer << "," << toPrint.yearOfRelease << "," << toPrint.nbOfLikes << "\n";
	return os;
}

//read object of type movie
std::istream& operator>>(std::istream& is, Movie& toRead)
{
	std::string line;
	getline(is, line);
	std::vector<std::string> tok = tokenize(line, ',');

	if (tok.size() != 5) {
		//throw std::runtime_error(std::string("READING HAS FAILED!\n"));
		return is;
	}

	toRead.name = tok[0];
	toRead.genre = tok[1];
	toRead.trailer = tok[2];
	toRead.yearOfRelease = std::stoi(tok[3]);
	toRead.nbOfLikes = std::stoi(tok[4]);

	return is;

}
