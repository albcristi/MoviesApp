#pragma once
#include "Repository.h"
class Redo
{
public:
	Redo();
	virtual void redoAction() = 0;
	virtual ~Redo();
};


class RedoAdd :public Redo
{
private:
	Movie addedMovie;
	Repository& repo;
public:
	RedoAdd(Movie mov, Repository& rep);

	void redoAction() override;

	~RedoAdd();
};

class RedoDelete :public Redo
{
private:
	Movie deletedMovie;
	Repository& repo;
public:
	RedoDelete(Movie mo, Repository& re);

	void redoAction()  override;

	~RedoDelete();
};


class RedoUpdate : public Redo
{
private:
	Movie toDel, toAdd;
	Repository& repo;
public:
	RedoUpdate(Movie tod, Movie toa, Repository& re);

	void redoAction() override;
};
