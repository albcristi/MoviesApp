#pragma once

#include <QWidget>
#include "ui_MovieWatch.h"
#include "myModel.h"

class MovieWatch : public QWidget
{
	Q_OBJECT
private:
	QAbstractItemModel* model;
public:
	MovieWatch(QAbstractItemModel* mod,QWidget *parent = Q_NULLPTR);
	~MovieWatch();

private:
	Ui::MovieWatch ui;
};
