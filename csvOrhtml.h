#pragma once

#include <QWidget>
#include "ui_csvOrhtml.h"

class csvOrhtml : public QWidget
{
	Q_OBJECT

public:
	csvOrhtml( QWidget* parent = Q_NULLPTR);
	~csvOrhtml();

private:
	Ui::csvOrhtml ui;



private slots:
	void csvPushed();

	void htmlPushed();
};
