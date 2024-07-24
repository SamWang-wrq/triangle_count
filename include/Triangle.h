#pragma once
#include "geo.h"

class Triangle
{
public:
	Triangle(Point* a, Point* b, Point* c);
	~Triangle();
	int Size();
	int hash();

	Point * first;
	Point * second;
	Point * third;
};





