#include "../include/Triangle.h"
extern std::map<int, int> hashmap;


Triangle::Triangle(Point *a , Point *b, Point *c)
{
	first = a;
	second = b;
	third = c;

};

int Triangle::Size() {//判断面积是否为0.5
	num x1 = first->pos_x;
	num x2 = second->pos_x;
	num x3 = third->pos_x;

	num y1 = first->pos_y;
	num y2 = second->pos_y;
	num y3 = third->pos_y;

	return abs(x1 * y2 - x1 * y3 + x2 * y3 - x2 * y1 + x3 * y1 - x2 * y2)==0;
	
};

int Triangle::hash() {
	Line(first, second).hash();
	Line(third, second).hash();
	Line(first, third).hash();
}

Triangle::~Triangle()
{

};