#pragma once
#include "Movie.h"
#include "Repository.h"
#include "MovieWatchList.h"
#include "FileWatchList.h"
#include "MovieValidator.h"	
#include "Undo.h"
#include "Redo.h"

class Controller
{
private:
	Repository repo;
	///MovieWatchList watchList;
	FileWatchList* watchListP;
    std::vector<Undo*> undoActions;
	std::vector<Redo*> redoActions;
	int currentIndex;

public:
	//default constructor
	Controller();
	//destructor
	~Controller();

	//constructor
	Controller(Repository repo, FileWatchList* wtl) :repo{ repo }, watchListP{ wtl }{this->currentIndex = -2; }
	int sizeUndo() { return undoActions.size(); }

	bool undoValid() { return 0 <= this->currentIndex && undoActions.size() > 0; }
	bool redoValid() {
		if (undoActions.size() == 0) { return false; } return (this->currentIndex < this->undoActions.size()-1 && -1 <= this->currentIndex);
	}
	
	void redo();
	//undo operation
	void undo();
	//add movie in the repository
	void addMovieRepo(Movie& movie);

	//delete a movie in the repository
	void deleteMovieRepo(Movie& movie);

	//update a movie in the repository
	void updateMovieRepo(Movie& old, Movie& replace);

	//adds a new element to the watch list
	void addWatchList(const Movie& mov);

	//remove from watch list the current movie
	void removeFromWatchList();

	//returns a vector containing elements 
	//with the specified genre
	std::vector<Movie> sortByGenre(Movie& mov);

	//increase likes
	void increaseLikes(Movie& mov, int likes);

	//void remove a certain movie from the watch list
	void removeFromWatchList(Movie& mov);

	//get the watch list
	std::vector<Movie> getWatchList() { return this->watchListP->getList(); }

	//get repository
	Repository getRepo() { return this->repo; }

	//save the data from the repository
	void saveData() { this->repo.writeData(); }

	//get all elements from the repo
	std::vector<Movie> getAllFromRepo() { return this->repo.getAll(); }

	//open watch list
	void openWatchList();

	//save the watch list
	void saveWatchList();

	std::vector<Movie> findStr(Movie key);

	std::vector<std::string> getGenres();

	void clearWtch() {
		this->watchListP->clearWtch();
	}
};

