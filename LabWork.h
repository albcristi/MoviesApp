#pragma once

#include <QWidget>
#include "Controller.h"
#include <qlayout.h>
#include <qpushbutton.h>
#include <qlistwidget.h>
#include <qlineedit.h>

class LabWork : public QWidget
{

private:
	Controller contr;
	QListWidget* listOfMovies;
	QLineEdit* filter;
public:
	//default constructor
	LabWork();
	//destructor
	~LabWork();
	//constructor
	LabWork(Controller& _contr);

	//the init function
	void initialize();

	void populate(std::vector<Movie> filteredList);

private slots:
	void updateMovies();

};
