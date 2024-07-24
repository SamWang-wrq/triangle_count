#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <map>

#define num int 
#define DEBUG


using namespace std;


class Point
{
public:

	num pos_x;
	num pos_y;
	
	Point(num x, num y);
#ifdef DEBUG
	const char* Print();
#endif // DEBUG
	~Point();
	

private:

#ifdef DEBUG
	char* printBuffer;
#endif // DEBUG


};

class Line
{
public:
	Line( Point * a, Point *b);
#ifdef DEBUG
	const char* Print();
#endif // DEBUG
	int digit();
	void hash();

	~Line();

private:
	Point * begin;
	Point * end;
#ifdef DEBUG
	char* printBuffer;
#endif // DEBUG



};


