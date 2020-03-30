#pragma once
#include "Repository.h"

class Undo
{
public:
	Undo();
	virtual void executeUndo() = 0; //pure virtual functions
	virtual ~Undo();
};


class UndoAdd :public Undo
{
private:
	Movie addedMovie;
	Repository& repo;
public:
	UndoAdd(Movie mov, Repository& repo);

	void executeUndo() override;
	
	~UndoAdd();
};


class UndoDelete :public Undo {
private:
	Movie deletedMovie;
	Repository& repo;
public:
	UndoDelete(Movie mov, Repository& rep);

	void executeUndo() override;
	~UndoDelete();
};

class UndoUpdate :public Undo {
private:
	Movie toDelete, toCreate;
	Repository& repo;
public:
	UndoUpdate(Movie tod, Movie toc, Repository& re);

	void executeUndo() override;
	~UndoUpdate();
};
