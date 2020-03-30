#include "Repository.h"



Repository::Repository()
{
	this->repo.reserve(1);

}


Repository::~Repository()
{
}

//checks the existence of an element
bool Repository::isUnique(const Movie& candidate)
{
	if (this->repo.size() == 0) {
		return true;
	}

	for (auto mov : this->repo) {
		if (mov == candidate) {
			return false;
		}
	}

	return true;
}

//adds an element in the repo, if possible
bool Repository::addElement(Movie& toAdd)
{
	if (this->isUnique(toAdd) == true) {
		this->repo.push_back(toAdd);
		return true;
	}
	throw std::runtime_error(std::string("Make sure the element that the element is unique!\n"));
}

//removes an element from the array, if possible
bool Repository::remove(Movie& toRemove)
{
	if (this->isUnique(toRemove) == true) {
		//it means that we don't have the movie in the repo
		throw std::runtime_error(std::string("Make sure that the element is in the database!\n"));
	}

	std::vector<Movie>::iterator it = std::find(this->repo.begin(), this->repo.end(), toRemove);
	int index = std::distance(this->repo.begin(), it);

	this->repo.erase(it);

	return true;
}

//updates an element from the array,if possible
bool Repository::update(Movie& oldMovie, Movie& newMovie)
{
	//movie to replace is not in the array
	if (this->isUnique(oldMovie) == true) {
		throw std::runtime_error(std::string("Make sure that the old element is in the database!\n"));
	}

	//the new movie is already in the array
	if (!(oldMovie == newMovie)) {
		if (this->isUnique(newMovie) == false) {
			throw std::runtime_error(std::string("Make sure that the element does not exist in the database!\n"));
		}
	}

	this->remove(oldMovie);
	this->addElement(newMovie);

	return true;
}

//returns the size the array
int Repository::getSize()
{
	return this->repo.size();
}

//returns a vector with movies given by genre
std::vector<Movie> Repository::sortedByGenre(Movie& keyGenre)
{

	std::vector<Movie> sorted(this->repo.size());

	if (keyGenre.getGenre() == "") {
		std::copy(this->repo.begin(), this->repo.end(), sorted.begin());
		return sorted;
	}

	sorted.resize(0);
	for (auto mov : this->repo) {
		if (mov.getGenre() == keyGenre.getGenre()) {
			sorted.push_back(mov);
		}
	}
	return sorted;
}


//init the repo with some data
void Repository::initialize()
{
	//initialize the repo with some data
	Movie mov{ "Titanic" ,"Romance","https://www.youtube.com/watch?v=2e-eXJ6HgkQ" ,1997,3000 };
	Movie mov1{ "The Matrix","SF","https://www.youtube.com/watch?v=vKQi3bBA1y8",1999,5000 };
	Movie mov2{ "Oblivion","SF", "https://www.youtube.com/watch?v=XmIIgE7eSak" ,2013,4000 };
	Movie mov3{ "Pulp Fiction", "Drama","https://www.youtube.com/watch?v=s7EdQ4FqbhY",1994,6000 };
	Movie mov4{ "Lara Croft: Tomb Raider","Action","https://www.youtube.com/watch?v=cnNBqNb3taw" ,2001,4500 };
	Movie mov5{ "Black Panther","Action", "https://www.youtube.com/watch?v=dxWvtMOGAhw",2018,5500 };
	Movie mov6{ "The fault in our stars","Romance","https://www.youtube.com/watch?v=9ItBvH5J6ss",2014,3550 };
	Movie mov7{ "Skyfall","Action", "https://www.youtube.com/watch?v=6kw1UVovByw",2012,8000 };
	Movie mov8{ "The Godfather","Drama", "https://www.youtube.com/watch?v=sY1S34973zA",1972,10000 };
	this->addElement(mov);
	this->addElement(mov1);
	this->addElement(mov2);
	this->addElement(mov3);
	this->addElement(mov4);
	this->addElement(mov5);
	this->addElement(mov6);
	this->addElement(mov7);
	this->addElement(mov8);
}

//check if the repo is empty
bool Repository::isEmpty()
{
	return this->getSize() == 0;
}

//increases the nb of likes of an element
void Repository::increaseLikes(Movie& mov, int number)
{
	if (this->isUnique(mov)) {
		//movie not in array
		return;
	}

	std::vector<Movie>::iterator it = std::find(this->repo.begin(), this->repo.end(), mov);
	int index = std::distance(this->repo.begin(), it);
	this->repo[index].setLikes(this->repo[index].getLikes() + number);
}

void Repository::writeData()
{
	//delete everything that has been in the file before
	std::ofstream del("storage.txt", std::ios::trunc);
	del.close();

	//enter the content
	std::ofstream newFile("storage.txt", std::ios::app);

	for (auto mov : this->repo) {
		newFile << mov;
	}

	newFile.close();

}

void Repository::readData()
{
	std::ifstream inputData("_storage.txt");
	Movie reading{};

	if (!inputData.is_open()) {
		throw std::runtime_error(std::string("FAILED TO OPEN THE FILE"));
	}

	while (inputData >> reading) {
		this->addElement(reading);
	}
	inputData.close();

}

//overloads the << operator
std::ostream& operator<<(std::ostream & os, const Repository & repo)
{
	for (auto mov : repo.repo) {
		os << mov << "\n";
	}
	return os;
}
