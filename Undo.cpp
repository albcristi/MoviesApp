#include "Undo.h"



Undo::Undo()
{
}


Undo::~Undo()
{
}

UndoAdd::UndoAdd(Movie mov, Repository& repo) :addedMovie{ mov }, repo{ repo }
{
}

void UndoAdd::executeUndo()
{
	this->repo.remove(addedMovie);
}

UndoAdd::~UndoAdd() {

}

UndoDelete::UndoDelete(Movie mov, Repository& rep): deletedMovie{mov},repo{rep}
{
}

void UndoDelete::executeUndo()
{
	repo.addElement(deletedMovie);
}

UndoDelete::~UndoDelete() {

}
UndoUpdate::UndoUpdate(Movie tod, Movie toc, Repository& re)
	:toDelete(tod),toCreate(toc),repo(re)
{
}

void UndoUpdate::executeUndo()
{
	repo.update(toCreate, toDelete);
}
UndoUpdate::~UndoUpdate() {

}

