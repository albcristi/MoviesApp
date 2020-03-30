#include "MovieWatch.h"

MovieWatch::MovieWatch(QAbstractItemModel* mod,QWidget *parent)
	: QWidget(parent)
{
	this->model = mod;
	ui.setupUi(this);
	this->ui.wtchTable->setModel(mod);
}

MovieWatch::~MovieWatch()
{
}
