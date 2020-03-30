#include "Controller.h"



Controller::Controller(){
	this->watchListP = nullptr;
	this->currentIndex = -1;
}


Controller::~Controller()
{
}

void Controller::redo()
{
	if (this->currentIndex == this->undoActions.size() - 1) {
		throw(std::runtime_error(""));
	}
	this->redoActions[currentIndex+1]->redoAction();
	this->currentIndex++;
	
}

void Controller::undo()
{
	if (this->currentIndex ==- 1) {
		throw(std::runtime_error(""));
	}
	this->undoActions.at(this->currentIndex)->executeUndo();
	this->currentIndex--;
	
}

void Controller::addMovieRepo(Movie& movie)
{

	this->repo.addElement(movie);
	UndoAdd* add = new UndoAdd(movie, this->repo);
	this->undoActions.push_back(add);
	this->currentIndex = this->undoActions.size() - 1;
	RedoAdd* addr = new RedoAdd(movie, this->repo);
	this->redoActions.push_back(addr);
}

void Controller::deleteMovieRepo(Movie& movie)
{
	Movie toDelete = this->repo.getInfo(movie);
	this->repo.remove(movie);
	UndoDelete* del = new UndoDelete(toDelete, this->repo);
	this->undoActions.push_back(del);
	RedoDelete* der = new RedoDelete(toDelete, this->repo);
	this->redoActions.push_back(der);
	this->currentIndex = this->undoActions.size() - 1;
}

void Controller::updateMovieRepo(Movie& old, Movie& replace)
{
	//MovieValidator val{};
	//val.validator(replace);
	Movie mov = this->repo.getInfo(old);
	this->repo.update(old, replace);
	UndoUpdate* upd = new UndoUpdate(mov, replace, this->repo);
	this->undoActions.push_back(upd);
	RedoUpdate* up = new RedoUpdate(mov, replace, this->repo);
	this->redoActions.push_back(up);
	this->currentIndex = this->undoActions.size() - 1;
}

void Controller::addWatchList(const Movie& mov)
{
	this->watchListP->add(mov);
}

void Controller::removeFromWatchList()
{
	this->watchListP->removeCurrent();
}

std::vector<Movie> Controller::sortByGenre(Movie& mov)
{
	return this->repo.sortedByGenre(mov);
}

void Controller::increaseLikes(Movie& mov, int likes)
{
	this->repo.increaseLikes(mov, likes);
}

void Controller::removeFromWatchList(Movie& mov)
{
	this->watchListP->removeMovie(mov);
}

void Controller::openWatchList()
{
	this->watchListP->openFileWithWatchList();
}

void Controller::saveWatchList()
{
	this->watchListP->write_file();
}

std::vector<Movie> Controller::findStr(Movie key)
{
	std::vector<Movie> filt;
	if (key.getGenre() == "")
		return this->repo.getAll();
	for (auto mov : repo.getAll()) {
		if (strstr(mov.getGenre().c_str(),key.getGenre().c_str())!=NULL) {
			filt.push_back(mov);
		}
	}

	return filt;
}

std::vector<std::string> Controller::getGenres()
{
	int ok = 0;
	std::vector<std::string> genres;
	for (auto mov : this->repo.getAll()) {
		if (genres.size() == 0) {
			genres.push_back(mov.getGenre());
		}
		else {
			ok = 0;
			for (auto gen : genres) {
				if (gen == mov.getGenre()) {
					ok = 1;
				}
			}

			if (ok == 0) {
				genres.push_back(mov.getGenre());
			}
		}
	}

	return genres;
}

