#include "bonus.h"
#include <sstream>

bonus::bonus(Controller contr,QWidget *parent)
	: QWidget(parent)
{

	
	this->data = contr;
	ui.setupUi(this);
	QPieSeries* genres = new QPieSeries();
	std::vector<QPieSlice*> datas;
	std::vector<std::string> all_genres = this->data.getGenres();
	std::vector<Movie> allMovies = this->data.getAllFromRepo();
	int i;
	for (i = 0; i < all_genres.size(); i++) {
		Movie key{};
		key.setGenre(all_genres[i]);
		std::string genre_number;
		genre_number.append(all_genres[i]);

		std::stringstream ss;
		ss << this->data.sortByGenre(key).size();
		genre_number.append(" : " + ss.str());
		genres->append(genre_number.c_str(),this->data.sortByGenre(key).size());
		datas.push_back(genres->slices().at(i));
		datas[i]->setLabelVisible();
	}


	QChart* theChart = new QChart();
	//setting the theme of the chart
	theChart->setTheme(theChart->ChartThemeQt);
	//add data to our chart
	theChart->addSeries(genres);
	//set the title of our chart
	theChart->setTitle("Number of movies that have a certain genre");

	QChartView* view = new QChartView(theChart);
	view->setRenderHint(QPainter::Antialiasing);
	view->setMidLineWidth(599);


	ui.mainLayout->addWidget(view);
}

bonus::~bonus()
{
}
