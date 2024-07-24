#pragma once
#include "./geo.h"


class Shape
{
public:
	Shape(vector<Point> * points);

	void Split(Line * splitLine);
	~Shape();

private:
	vector<Point> * data;


};

