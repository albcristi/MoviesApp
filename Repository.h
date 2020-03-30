#pragma once
#include "Movie.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <exception>
#include <fstream>


class Repository
{
private:
	std::vector<Movie> repo;
public:
	//default constructor
	Repository();
	//default destructor
	~Repository();

	//function that checks if an element is
	//not already in the repository
	bool isUnique(const Movie& candidate);

	//add element : true if operation was a success
	bool addElement(Movie& toAdd);

	//delete element : true if operation was a success
	bool remove(Movie& toRemove);

	//update an element : true if operation was a success
	bool update(Movie& oldMovie, Movie& newMovie);

	//get size of the aray 
	int getSize();

	//returns a vector only with the movies that have the same genre
	std::vector<Movie> sortedByGenre(Movie& keyGenre);

	//function used for sorting by genre
	//bool sameGenre(Movie& mov);

	//initialize the repository with some data
	void initialize();

	//check if the array is empty
	bool isEmpty();

	//increase likes for an element
	void increaseLikes(Movie& mov, int number);

	//print the repository
	friend std::ostream& operator<<(std::ostream& os, const Repository& repo);

	//writes data in file
	void writeData();

	//reads data from file
	void readData();

	//get all elements from the movie
	std::vector<Movie> getAll() { return this->repo; }

	Movie getInfo(Movie& movie) {
		for (auto mov : this->repo) {
			if (mov == movie) {
				return mov;
			}
		}
		Movie m{};
		return m;
	}
	


};

