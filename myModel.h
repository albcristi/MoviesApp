#pragma once
#include "Controller.h"
#include <QAbstractTableModel>

class myModel : public QAbstractTableModel
{
private:
	Controller& contr;
public:
	myModel(Controller& co);
	~myModel();

	int rowCount(const QModelIndex& parent = QModelIndex()) const override;

	int columnCount(const QModelIndex& parent = QModelIndex()) const override;

	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole)const;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

	bool  setData(const QModelIndex& index, const QVariant& value, int role);
};
