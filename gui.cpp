#include "gui.h"
#include <sstream>
#include <shellapi.h>
#include "MovieWatch.h"
#include <qshortcut.h>

gui::gui(Controller _contr)
{
	this->contr = _contr;
	this->initializeGui();
	this->populateDataBase();
}

gui::~gui()
{
}

void gui::initializeGui()
{
	QHBoxLayout* mainLayout = new QHBoxLayout{ this };
	//ADMIN things
	//create the watch list;
	this->allMovies = new QListWidget{};
	//add the watchList to the layout
	QVBoxLayout* database = new QVBoxLayout{};
	
	database->addWidget(this->allMovies);
	//create the layout from where the user 
	//will enter new  movies
	QFormLayout* dataEntrance = new QFormLayout{};
	
	//create  the line edit objects <-- those that
	//will help to create a new movie
	this->title = this->createLabel("&Title:");
	this->titleBox = this->createBudy(this->title);
	this->genre = this->createLabel("&Genre:");
	this->genreBox = this->createBudy(this->genre);
	this->trailer = this->createLabel("&Trailer:");
	this->trailerBox = this->createBudy(this->trailer);
	this->yearOfRelease = this->createLabel("&Year of release:");
	this->yrOfReleaseBox = this->createBudy(this->yearOfRelease);
	this->numberOflikes = this->createLabel("&Number of likes:");
	this->likesBox = this->createBudy(this->numberOflikes);
	this->movieToUpdate = this->createLabel("&Old name:");
	this->nameForUpdateBox = this->createBudy(this->movieToUpdate);

	//add them to their corresponding layout
	dataEntrance->addRow(this->title,this->title->buddy());
	dataEntrance->addRow(this->genre,this->genre->buddy());
	dataEntrance->addRow(this->yearOfRelease,this->yearOfRelease->buddy());
	dataEntrance->addRow(this->trailer,this->trailer->buddy());
	dataEntrance->addRow(this->numberOflikes,this->numberOflikes->buddy());
	dataEntrance->addRow(this->movieToUpdate, this->movieToUpdate->buddy());
	database->addLayout(dataEntrance);

	//add, delete and update buttons
	this->addButton = this->createButton("Add");
	this->deleteButton = this->createButton("Delete");
	this->updateButton = this->createButton("Update");

	this->undoButton = this->createButton("Undo");
	this->redoButton = this->createButton("Redo");
	//create the layout where to put the add, delete and update
	//buttons,layout that will be added after to the mainLayout
	QGridLayout* adminButtons = new QGridLayout{};

	adminButtons->addWidget(this->addButton, 0, 0, 1, 3);
	adminButtons->addWidget(this->deleteButton, 1,0,1,3);
	adminButtons->addWidget(this->updateButton, 2, 0, 1, 3);
	adminButtons->addWidget(this->undoButton,3,0,1,2);
	adminButtons->addWidget(this->redoButton,3,2,1,1);
	database->addLayout(adminButtons);
	mainLayout->addLayout(database);

	//USER MODE
		//create the button that will help the user to 
	//create a new movie watch list
	QVBoxLayout* leftLayoutUser = new QVBoxLayout{};

	this->createWatchListButton = this->createButton("Start a new Watch List");
	QHBoxLayout* bttn = new QHBoxLayout{};
	bttn->addWidget(this->createWatchListButton);
	leftLayoutUser->addLayout(bttn);

	QFormLayout* getThePreferedGenre = new QFormLayout{};
	this->genreForWatchList = this->createLabel("&Prefered Genre:");
	this->preferedGenreBox = this->createBudy(this->genreForWatchList);
	getThePreferedGenre->addRow(this->genreForWatchList, this->genreForWatchList->buddy());
	leftLayoutUser->addLayout(getThePreferedGenre);

	//create the place where the current movie will be displayed
	this->currentMovie = new QListWidget{};
	leftLayoutUser->addWidget(this->currentMovie);

	
	
	QHBoxLayout* watchListButtons = new QHBoxLayout{};
	this->nextButton = this->createButton("Next");
	this->addWatchListButton = this->createButton("Add");
	this->stopCreating = this->createButton("Stop");
	watchListButtons->addWidget(this->nextButton);
	watchListButtons->addWidget(this->addWatchListButton);
	watchListButtons->addWidget(this->stopCreating);
	leftLayoutUser->addLayout(watchListButtons);
	
	//create the button for seeing a watch list
	this->seeWatchListButton = this->createButton("My Watch List");
	QHBoxLayout* seewtchl = new QHBoxLayout{};
	seewtchl->addWidget(this->seeWatchListButton);
	leftLayoutUser->addLayout(seewtchl);
	//The delete option for a movie existing in the
	//created watch list

	QFormLayout* deleteFromWtchl = new QFormLayout{};
	this->removeFromWatchList = this->createLabel("Remove from watch list: ");
	this->removeWatchlTitleBox = this->createBudy(this->removeFromWatchList);
	deleteFromWtchl->addRow(this->removeFromWatchList, this->removeFromWatchList->buddy());

	//last button ...
	this->removewtcl = this->createButton("Remove");
	this->bonusButton = this->createButton("Bonus");
	QVBoxLayout* lastlay = new QVBoxLayout{};
	lastlay->addWidget(this->removewtcl);
	lastlay->addWidget(this->bonusButton);
	leftLayoutUser->addLayout(deleteFromWtchl);
	leftLayoutUser->addLayout(lastlay);
	mainLayout->addLayout(leftLayoutUser);
	//this->bonusButton->setText(QString::fromStdString("Bonus"));	
	//this->setStyleSheet("* {color: qlineargradient(spread:pad, x1:0 y1:0, x2:1 y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));""background: qlineargradient( x1:0 y1:0, x2:1 y2:0, stop:0 lightsteelblue, stop:1 grey);}");
	//connecting the Admin Buttons
	QObject::connect(this->deleteButton, &QPushButton::clicked, this, &gui::deleteWasClickedAdmin);
	
	QObject::connect(this->addButton, &QPushButton::clicked, this, &gui::addClickedAdmin);
	
	QObject::connect(this->updateButton, &QPushButton::clicked, this, &gui::updateClickedAdmin);

	//connecting the User Buttons
	QObject::connect(this->createWatchListButton, &QPushButton::clicked, this, &gui::preferedGenreClicked);

	QObject::connect(this->addWatchListButton,&QPushButton::clicked,this,&gui::addWtchlClicked);

	QObject::connect(this->nextButton, &QPushButton::clicked, this, &gui::nextWtchlClicked);

	QObject::connect(this->stopCreating, &QPushButton::clicked, this, &gui::stopLookingClicked);

	QObject::connect(this->seeWatchListButton, &QPushButton::clicked, this, &gui::showWtchlClicked);

	QObject::connect(this->removewtcl, &QPushButton::clicked, this, &gui::removeFromWatchlClicked);

	QObject::connect(this->bonusButton, &QPushButton::clicked, this, &gui::bonusClicked);

	QObject::connect(this->undoButton, &QPushButton::clicked, this, &gui::undoClicked);

	QObject::connect(this->redoButton, &QPushButton::clicked, this, &gui::redoClicked);

	QShortcut* undoSh=new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z), this);
	QObject::connect(undoSh, &QShortcut::activated, this, &gui::undoClicked);

	QShortcut* redoSh = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y), this);
	QObject::connect(redoSh, &QShortcut::activated, this, &gui::redoClicked);
}

QPushButton* gui::createButton(std::string nameOfTheButton)
{
	//create the button
	QPushButton* createdButton = new QPushButton{ nameOfTheButton.c_str() };
	//create a font for the button
	QFont buttonFont("Courier", 10, 10, true);
	createdButton->setFont(buttonFont);
	//return the created button
	return createdButton;
}

void gui::populateDataBase()
{
	int nr = 0;
	this->allMovies->addItem("\t Available movies:");
	for (auto movie : this->contr.getAllFromRepo()) {
		std::string row;
		std::stringstream ss;
		std::stringstream order;
		nr++;
		order << nr;
		ss << movie.getYear();
		row.append(order.str()+" "+movie.getName()+" "+ss.str()+"  "+movie.getGenre());
		this->allMovies->addItem(row.c_str());
	}
}

QLabel* gui::createLabel(std::string nameOfTheLabel)
{
	
	QLabel* toCreate = new QLabel{ nameOfTheLabel.c_str() };
	QFont font("Courier", 10, 10, true);
	toCreate->setFont(font);
	return toCreate;
}

QLineEdit* gui::createBudy(QLabel* theLabel)
{
	QLineEdit* textBox = new QLineEdit{};
	theLabel->setBuddy(textBox);
	return textBox;
}

void gui::deleteWasClickedAdmin()
{
	QString titleN = this->title->text();
	Movie key{};
	try {
		std::string name = this->titleBox->text().toStdString();
		Movie key{};
		key.setName(name);
		this->titleBox->clear();
		this->contr.deleteMovieRepo(key);
		this->allMovies->clear();
		this->populateDataBase();
		this->contr.saveData();
	}
	catch (std::runtime_error & err) {
		std::string er = err.what();
		QErrorMessage* msg = new QErrorMessage();
		msg->showMessage(er.c_str());
		

	}
}

void gui::addClickedAdmin()
{
	try {
		std::string name = this->titleBox->text().toStdString();
		std::string genre = this->genreBox->text().toStdString();
		std::string trailer = this->trailerBox->text().toStdString();
		int year, likes;
		Movie toAdd{};
		toAdd.setName(name);
		toAdd.setGenre(genre);
		toAdd.setTrailer(trailer);
		try {
			year = std::stoi(this->yrOfReleaseBox->text().toStdString());
			likes = std::stoi(this->likesBox->text().toStdString());
		}
		catch(...){
			throw(std::runtime_error(std::string("Make sure you have introduced valid data!")));
		}
		toAdd.setLikes(likes);
		toAdd.setYear(year);

		this->contr.addMovieRepo(toAdd);
		this->yrOfReleaseBox->clear();
		this->genreBox->clear();
		this->titleBox->clear();
		this->likesBox->clear();
		this->trailerBox->clear();
		
		this->allMovies->clear();
		this->populateDataBase();

		this->contr.saveData();
		
	}
	catch (std::runtime_error & err) {
		std::string er = err.what();
		QErrorMessage* msg = new QErrorMessage();
		msg->showMessage(er.c_str());
	}
}

void gui::updateClickedAdmin()
{
	
	Movie key{};
	try {
		std::string name = this->nameForUpdateBox->text().toStdString();
		Movie key{};
		key.setName(name);
		this->contr.deleteMovieRepo(key);
		this->nameForUpdateBox->clear();
		this->allMovies->clear();
		this->populateDataBase();
		this->addClickedAdmin();
	}
	catch (std::runtime_error & err) {
		std::string er = err.what();
		QErrorMessage* msg = new QErrorMessage();
		msg->showMessage(er.c_str());


	}
}


//         SLOTS FOR THE USER BUTTONS
void gui::preferedGenreClicked()
{
	try {
		std::string preferedGenre = this->preferedGenreBox->text().toStdString();
		Movie keyMovie{};
		keyMovie.setGenre(preferedGenre);
		this->resources = this->contr.sortByGenre(keyMovie);

		if (this->resources.size() == 0) {
			throw std::runtime_error(std::string("Searched returned no results!"));
		}
		this->contr.clearWtch();
		//also update the current seen movie in the list - for sincronization with the next bttn
		this->currentMovie->clear();
		this->currentIndex = 0;
		Movie movie = this->resources[0];
		std::string row;
		std::stringstream ss;
		std::stringstream order;
	
		ss << movie.getYear();
		row.append(order.str() + " " + movie.getName() + " " + ss.str() + "  " + movie.getGenre());
		this->currentMovie->addItem(row.c_str());
		ShellExecuteA(NULL, NULL, "chrome.exe", movie.getTrailer().c_str(), NULL, SW_SHOWMAXIMIZED);
		
	}
	catch (std::runtime_error & err) {
		std::string er = err.what();
		QErrorMessage* msg = new QErrorMessage();
		msg->showMessage(er.c_str());
	}
}

void gui::addWtchlClicked()
{
	
	try {
	
		
		if (this->resources.size() == 0) {
			throw std::runtime_error(std::string("No available movies"));
		}

		if (this->currentIndex == this->resources.size()) {
			this->currentIndex = 0;
		}

		this->contr.addWatchList(this->resources[this->currentIndex]);
		this->currentIndex++;
		if (this->currentIndex == this->resources.size()) {
			this->currentIndex = 0;
		}

		//move to the next movie
		Movie movie = this->resources[this->currentIndex];
		this->currentMovie->clear();
		std::string row;
		std::stringstream ss;
		std::stringstream order;

		ss << movie.getYear();
		row.append(order.str() + " " + movie.getName() + " " + ss.str() + "  " + movie.getGenre());
		this->currentMovie->addItem(row.c_str());
		ShellExecuteA(NULL, NULL, "chrome.exe", movie.getTrailer().c_str(), NULL, SW_SHOWMAXIMIZED);

	}
	catch (std::runtime_error & err) {
		std::string er = err.what();
		QErrorMessage* msg = new QErrorMessage();
		msg->showMessage(er.c_str());
	}
}

void gui::nextWtchlClicked()
{

	try {


		if (this->resources.size() == 0) {
			throw std::runtime_error(std::string("No available movies"));
		}

		this->currentIndex++;
		if (this->currentIndex == this->resources.size()) {
			this->currentIndex = 0;
		}

		//move to the next movie
		Movie movie = this->resources[this->currentIndex];
		this->currentMovie->clear();
		std::string row;
		std::stringstream ss;
		std::stringstream order;

		ss << movie.getYear();
		row.append(order.str() + " " + movie.getName() + " " + ss.str() + "  " + movie.getGenre());
		this->currentMovie->addItem(row.c_str());
		ShellExecuteA(NULL, NULL, "chrome.exe", movie.getTrailer().c_str(), NULL, SW_SHOWMAXIMIZED);

	}
	catch (std::runtime_error & err) {
		std::string er = err.what();
		QErrorMessage* msg = new QErrorMessage();
		msg->showMessage(er.c_str());
	}
}

void gui::stopLookingClicked()
{
	this->currentMovie->clear();
	this->currentIndex = 0;
	this->resources.clear();
}

void gui::showWtchlClicked()
{
	try {
		if (this->contr.getWatchList().size() == 0) {
			throw std::runtime_error(std::string("No movies registered"));
		}

		this->contr.saveWatchList();
		myModel* mod = new myModel(this->contr);
		
		MovieWatch* newWind = new MovieWatch(mod);
		newWind->setWindowModality(Qt::WindowModal);
		newWind->show();
		//this->contr.openWatchList();
	}
	catch (std::runtime_error & err) {
		std::string er = err.what();
		QErrorMessage* msg = new QErrorMessage();
		msg->showMessage(er.c_str());
	}
}

void gui::removeFromWatchlClicked()
{
	try {

		if (this->contr.getWatchList().size() == 0) {
			throw std::runtime_error(std::string("No watch list!"));
		}
		std::string name = this->removeWatchlTitleBox->text().toStdString();
		Movie key{};
		key.setName(name);
		this->contr.removeFromWatchList(key);
		this->removeWatchlTitleBox->clear();
	}
	catch (std::runtime_error & err) {
		std::string er = err.what();
		QErrorMessage* msg = new QErrorMessage();
		msg->showMessage(er.c_str());
	}
}

void gui::bonusClicked()
{
	bonus* bon = new bonus(this->contr);
	bon->setWindowModality(Qt::WindowModal);
	bon->show();
}

void gui::undoClicked()
{

	try {
		this->contr.undo();
		this->allMovies->clear();
		this->populateDataBase();
		this->allMovies->clear();
		this->populateDataBase();
	}
	catch (...) {
		QErrorMessage* msg = new QErrorMessage();
		msg->showMessage("No more undos available");
	}
}

void gui::redoClicked()
{
	try {
		this->contr.redo();
		this->allMovies->clear();
		this->populateDataBase();
	}
	catch (...) {
		QErrorMessage* msg = new QErrorMessage();
		msg->showMessage("No redo available");
	}
}





