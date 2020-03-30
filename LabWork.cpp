#include "LabWork.h"
#include <sstream>

LabWork::LabWork()
{
}

LabWork::~LabWork()
{
}

LabWork::LabWork(Controller& _contr)
{
	this->contr = _contr;
	this->initialize();
	this->populate(this->contr.getAllFromRepo());
}

void LabWork::initialize()
{
	QVBoxLayout* mainLayout = new QVBoxLayout{ this };

	this->listOfMovies = new QListWidget{};
	this->filter = new QLineEdit{};

	QObject::connect(this->filter, &QLineEdit::textChanged, this, &LabWork::updateMovies);
	
	mainLayout->addWidget(this->filter);
	mainLayout->addWidget(this->listOfMovies);


}

void LabWork::populate(std::vector<Movie> filteredList)
{
	for (auto movie : filteredList) {
		std::string row;
		std::stringstream ss;
		std::stringstream order;
		ss << movie.getYear();
		row.append(" " + movie.getName() + " " + ss.str() + "  " + movie.getGenre());
		this->listOfMovies->addItem(row.c_str());
	}

}

void LabWork::updateMovies()
{
	QString filt = this->filter->text();
	Movie key{};
	key.setGenre(filt.toStdString());
	std::vector<Movie> newList = this->contr.findStr(key);
	this->listOfMovies->clear();
	this->populate(newList);
}
