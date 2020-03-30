#pragma once
#include "Movie.h"

template <class T>
class Comparator
{
public:
	//Comparator();

	virtual bool compare(T e1, T e2) = 0;

	virtual ~Comparator() {};
};

//returns true if two movies are the same ( they have the same name)
class Comp1 : public Comparator<Movie>
{
public:
	bool compare(Movie m1, Movie m2) override { return m1.getName() == m2.getName(); }
};

//returns true if the first movie has less likes then the second one
class Comp2 : public Comparator<Movie>
{
public:
	bool compare(Movie m1, Movie m2) override { return m1.getLikes() < m2.getLikes(); }
};
