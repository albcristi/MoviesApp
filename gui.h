#pragma once

#include <QWidget>
#include "Controller.h"
#include <qpushbutton.h>
#include <qlayout.h>
#include <qlistwidget.h>
#include <qformlayout.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qstring.h>
#include <stdexcept>
#include <qerrormessage.h>
#include <vector>
#include <Windows.h>
#include "bonus.h"



class gui : public QWidget
{
private:
	Controller contr;
	QListWidget* allMovies, * currentMovie;
	QPushButton* addButton, * deleteButton, * updateButton, * addWatchListButton, * seeWatchListButton;
	QPushButton* deleteFromWatchListButton, * nextButton, * createWatchListButton, * stopCreating;
	QLabel* genreForWatchList, * removeFromWatchList;
	QLabel* title, * genre, * yearOfRelease, * trailer, * numberOflikes, * movieToUpdate;
	//the following line edits correspond to the form layout befor the add,delete, update 
	QLineEdit* titleBox, * genreBox, * yrOfReleaseBox, * trailerBox, * likesBox, * nameForUpdateBox;
	//those are the two line edits from the user part
	QLineEdit* preferedGenreBox, * removeWatchlTitleBox;
	QPushButton *removewtcl; //the button from the lower left corner
	QPushButton* undoButton, *redoButton;
	//the following two are used to simulate the infinite search
	//when looking looking for a movie to add to the watch list
	std::vector<Movie> resources;
	int currentIndex;
	//button used to activate the bonus part
	QPushButton* bonusButton;
public:
	gui(Controller _cotnr);
	~gui();
private:
	/*
	This function will initialize the gui
	     o add buttons
		 o add layouts
		 o CREATE THE PRINCIPAL LAYOUT
		 o add new layouts to the main 
		 layout
		 o etc...
	*/
	void initializeGui();

	/*
	This function creates a button having 
	the name set to the parameter of the
	fct. nameOfTheButton and font Crier.
	Function return a pointer to the new bttn.
	*/
	QPushButton* createButton(std::string nameOfTheButton);

	/*
	This function will add all the movies
	from the repository into a table so 
	that the datas from the data base
	can be seen easily when in the app
	*/
	void populateDataBase();

	/*
	Creates a new label with the name
	set to the only parameter that this
	function is taking.
	It also creates a txt box 
	*/
	QLabel* createLabel(std::string nameOfTheLabel);

	QLineEdit* createBudy(QLabel* theLabel);
	
private slots:
	/*
	Functions that handle the ADMIN ACTIONS
	*/
	/*
	This function will be called when the 
	delete button has been clicked
	*/

	void deleteWasClickedAdmin();

	/*
	This function will be called when
	the add button has been clicked
	*/

	void addClickedAdmin();

	/*
	This function will be called when the
	update button has been cliked
	*/

	void updateClickedAdmin();

	/*
	Functions that work with the buttons 
	from the user part ( right side -- 
	your perspective --)
	*/
	/*
	This function is called when the 
	prefered genre button is cliked
	o creates a list with all the movies
	from the database having a given genre
	*/
	void preferedGenreClicked();

	/*
	This function is called when the add button
	from the user part has been called and it will
	add the current movie from the watch list and
	increase the size
	*/

	void addWtchlClicked();


	/*
	This function is called when the user clicks
	on the next movie button
	*/
	void nextWtchlClicked();

	/*
	This function is called when the user wants to
	stop from looking for movies to add in the wacth
	List
	*/

	void stopLookingClicked();

	/*
	This function is called when the user clicks the 
	show wacth list button
	*/
	void showWtchlClicked();

	/*
	This function is called when the remove from
	watch list button is called ( ~removewtchl)
	*/
	void removeFromWatchlClicked();

	//bonus
	void bonusClicked();

	//lab14
	void undoClicked();

	void redoClicked();
};
