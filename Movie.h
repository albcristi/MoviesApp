#pragma once
#include <string>
#include <iostream>
#include <vector>

class Movie
{
private:
	std::string name, genre, trailer;
	int yearOfRelease, nbOfLikes;
public:
	//default constructor
	Movie();

	//constructor
	Movie(std::string name, std::string genre, std::string trailer, int year, int likes);

	//copy constructor
	Movie(const Movie& copy);

	//getters
	const std::string getName();
	const std::string getGenre();
	const std::string getTrailer();
	const int getYear();
	const int getLikes();

	//setters
	Movie& setName(std::string& name);
	Movie& setGenre(std::string& genre);
	Movie& setTrailer(std::string& trailer);
	Movie& setYear(int year);
	Movie& setLikes(int likes);

	//operators
	//equal if the name is the same
	bool operator==(const Movie& second);

	//not equal for the genre
	bool operator!=(const Movie& second);

	//tokenize a string
	friend std::vector<std::string> tokenize(std::string str, char delimit);

	//printing to console/file object of type Movie
	friend std::ostream& operator<<(std::ostream& os, const Movie& toPrint);

	//reading from console/file object of type Movie
	friend std::istream& operator>>(std::istream& is, Movie& toRead);
	~Movie();
};

