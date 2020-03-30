#pragma once
#include "Movie.h"
#include <vector>

class MovieWatchList
{
protected:
	std::vector<Movie> watchList;
	int current;

public:
	//default constructor
	//MovieWatchList();
	//destructor
	~MovieWatchList();

	//constructor
	MovieWatchList() { this->current = 0; }

	//copy constructor
	MovieWatchList(MovieWatchList& copy) { this->watchList = copy.watchList; this->current = copy.current; }

	//adds a new movie in the watch list
	void add(const Movie& movie);

	//returns the current movie
	Movie getCurrent();

	//sets the current to the first element
	void first();

	//sets the current to the next element
	void next();

	//void remove current element
	void removeCurrent();

	//removes a given movie from the watch list
	void removeMovie(Movie& mov);

	void clearWtch() {
		this->watchList.clear();
	}

	std::vector<Movie> getList() { return this->watchList; }
};

