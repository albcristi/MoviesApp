#include "MovieWatchList.h"



MovieWatchList::~MovieWatchList()
{
}

void MovieWatchList::add(const Movie& movie)
{
	for (auto mov : this->watchList) {
		if (mov == movie) {
			return;
		}
	}
	this->watchList.push_back(movie);
}

Movie MovieWatchList::getCurrent()
{
	if (this->watchList.size() == 0)
		throw std::runtime_error(std::string("EMPTY WATCH LIST"));
	if (this->current == this->watchList.size()) {
		this->current = 0;
	}

	return this->watchList[this->current];
}

void MovieWatchList::first()
{
	this->current = 0;
}

void MovieWatchList::next()
{
	this->current++;
}

void MovieWatchList::removeCurrent()
{
	if (this->current == this->watchList.size()) {
		this->current = 0;
	}
	this->watchList.erase(this->watchList.begin() + this->current);
}

void MovieWatchList::removeMovie(Movie & mov)
{
	std::vector<Movie>::iterator it = std::find(this->watchList.begin(), this->watchList.end(), mov);
	this->watchList.erase(it);
}
