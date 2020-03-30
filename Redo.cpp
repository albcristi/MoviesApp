#include "Redo.h"



Redo::Redo()
{
}


Redo::~Redo()
{
}

RedoAdd::RedoAdd(Movie mov, Repository& rep) :addedMovie{ mov },repo{rep}
{
}

void RedoAdd::redoAction()
{
	repo.addElement(addedMovie);
}

RedoAdd::~RedoAdd()
{
}

RedoDelete::RedoDelete(Movie mo, Repository& re) : deletedMovie{ mo }, repo{ re }
{
}

void RedoDelete::redoAction()
{
	repo.remove(deletedMovie);
}

RedoDelete::~RedoDelete()
{
}

RedoUpdate::RedoUpdate(Movie tod, Movie toa, Repository& re)
	:toDel{ tod }, toAdd{ toa }, repo{ re }
{
}

void RedoUpdate::redoAction()
{
	repo.update(toDel, toAdd);
}
