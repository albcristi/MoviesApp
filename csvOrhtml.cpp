#include "csvOrhtml.h"
#include "Controller.h"
#include "csv_watchList.h"
#include "html_watchList.h"
#include "gui.h"


csvOrhtml::csvOrhtml(QWidget *parent)
	: QWidget(parent)
{
	
	ui.setupUi(this);
	this->setWindowModality(Qt::WindowModal);
	this->setStyleSheet("* {color: qlineargradient(spread:pad, x1:0 y1:0, x2:1 y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));""background: qlineargradient( x1:0 y1:0, x2:1 y2:0, stop:0 lightsteelblue, stop:1 grey);}");
	QObject::connect(this->ui.csvButton, &QPushButton::clicked, this, &csvOrhtml::csvPushed);
	QObject::connect(this->ui.hmtlButton, &QPushButton::clicked, this, &csvOrhtml::htmlPushed);
}

csvOrhtml::~csvOrhtml()
{
}

void csvOrhtml::csvPushed()
{
	Repository repo{};
	repo.readData();
	csv_watchList* wtchl = new csv_watchList{ "csv.txt" };
	Controller contr{ repo,wtchl };
	gui* menu = new gui(contr);
	menu->setWindowModality(Qt::WindowModal);
	menu->show();
	
}

void csvOrhtml::htmlPushed()
{
	Repository repo{};
	repo.readData();
	html_watchList* wtchl = new html_watchList("html_file.html");
	Controller contr{ repo,wtchl };
	gui* menu = new gui(contr);
	menu->setWindowModality(Qt::WindowModal);
	menu->show();
	
}
