#include "myModel.h"
#include <qcolor.h>
myModel::myModel(Controller& co):contr(co)
{

}

myModel::~myModel()
{
}

int myModel::columnCount(const QModelIndex& parent) const
{
	return 5;
}

QVariant myModel::data(const QModelIndex& index, int role) const
{
	int row = index.row();
	int col = index.column();
	Movie mov = this->contr.getWatchList()[row];

	if (role == Qt::DisplayRole)
		switch (col)
		{
		case 0:
			return QString::fromStdString(mov.getName());
		case 1:
			return QString::fromStdString(mov.getGenre());
		case 2:
			return QString::number(mov.getYear());
		case 3:
			return QString::number(mov.getLikes());
		case 4:
			return QString::fromStdString(mov.getTrailer());
		default:
			break;
		}

	if (role == Qt::BackgroundRole) {
		if (row % 2 == 0) {
			return QColor{ Qt::green };
		}
	}
	
	return QVariant();
}

QVariant myModel::headerData(int section, Qt::Orientation orientation, int role) const
{

	if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
		switch (section) {
		case 0:
			return "Title";
		case 1:
			return "Genre";
		case 2:
			return "Year";
		case 3:
			return "Number of Likes";
		case 4:
			return "Link";
		default:
			break;
		}
	}

	return QVariant();
}

bool myModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
	Movie mov = this->contr.getWatchList()[index.row()];
	if(role==Qt::EditRole)
		switch (index.column())
		{
		case 0:
			mov.setName(value.toString().toStdString());
			break;
		case 1:
			mov.setGenre(value.toString().toStdString());
			break;
		case 2:
			mov.setYear(value.toString().toInt());
		case 3:
			mov.setLikes(value.toString().toInt());
		case 4:
			mov.setTrailer(value.toString().toStdString());
		default:
			break;
		}
	emit dataChanged(index, index);
	return true;
}


int myModel::rowCount(const QModelIndex& parent) const
{
	return this->contr.getWatchList().size();
}
