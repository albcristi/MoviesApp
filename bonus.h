#pragma once

#include <QWidget>
#include "ui_bonus.h"
#include <QtCharts/qchartglobal.h>
#include <QtCharts/qchartview.h>
#include <QtCharts/qpieseries.h>
#include<QtCharts/qpieslice.h>
#include "Controller.h"

using namespace QtCharts;

class bonus : public QWidget
{
	Q_OBJECT

public:
	bonus(Controller contr,QWidget *parent = Q_NULLPTR);
	~bonus();

private:
	Ui::bonus ui;
	Controller data;
};
