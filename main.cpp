#include "lab5_12_bon.h"
#include <QtWidgets/QApplication>

#include "gui.h"
#include "csv_watchList.h"
#include "html_watchList.h"
#include "LabWork.h"
#include "csvOrhtml.h"

int main(int argc, char* argv[])
{

	QApplication a{ argc,argv };


	csvOrhtml op{};
	op.show();


	return a.exec();

}

