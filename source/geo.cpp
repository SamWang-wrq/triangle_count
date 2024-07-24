#include "../include/geo.h"

extern std::map<int, int> hashmap;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

Point::Point(num x, num y)
{
	pos_x = x;
	pos_y = y;

}

#ifdef DEBUG
const char* Point::Print() {
	//cout << "(" << pos_x << "," << pos_x << ")" << endl;s
	if (printBuffer != nullptr) {
		return printBuffer;
	}
	string temp = string("(") + to_string(pos_x) + string(",") + to_string(pos_y) + string(")");
	char* name;
	name = (char*)malloc(temp.size());
	printBuffer = name;
	strcpy(name, temp.c_str());
	return name;
#endif // DEBUG




}

Point::~Point()
{
	if (!printBuffer) {
		free(printBuffer);
	}
	
};



Line::Line(Point * a, Point * b)
{
	begin = a;
	end = b;

}

#ifdef DEBUG
const char *  Line::Print() {

	if (printBuffer != nullptr) {
		//cout << "defined";
		return printBuffer;
	}
	string temp = string("[") + string(begin->Print()) + string("-") + string(end->Print()) + string("]");

	char* name;
	name = (char*)malloc(temp.size());
	printBuffer = name;
	strcpy(name, temp.c_str());
	return name;
}
#endif // DEBUG

int Line::digit() {
	//注意这里只能处理最小单位基础线段
	int digit = 1;
	
	if ((begin->pos_x == 0 && begin->pos_y == 0) && (end->pos_x == 0 || end->pos_y == 0)) {//需要跨文件调用mn
		//digit = -1;//边线线段
	}
	if (begin->pos_x >= end->pos_x) {
		if (begin->pos_x == end->pos_x) {
			if (begin->pos_y < end->pos_y) {
				return (end->pos_x * 1000000 + end->pos_y * 10000 + begin->pos_x * 100 + begin->pos_y) * digit;

			}
		}
		return (begin->pos_x * 1000000 + begin->pos_y * 10000 + end->pos_x * 100 + end->pos_y)*digit;
		

	}
	else {
		return (end->pos_x * 1000000 + end->pos_y * 10000 + begin->pos_x * 100 + begin->pos_y) * digit;

	}
	
	return digit;
		
}


void Line::hash() {
	int x1 = begin->pos_x;
	int x2 = end->pos_x;
	int y1 = begin->pos_y;
	int y2 = end->pos_y;
	int temp;
	if (x1 > x2) {
		temp = x1;
		x1 = x2;
		x2 = temp;

		temp = y1;
		y1 = y2;
		y2 = temp;
	}
	if (x1 == x2) {
		if (y1 == y2) {
			//cout << "重合点" << endl;
			return ;
		}
		if (y1 > y2) {
			temp = y1;
			y1 = y2;
			y2 = temp;
		}


		for (int i = 1; i < (y2 - y1); i++) {
			//cout << dy << endl;
			Point point1 = Point(x1, y1 + i);
			Point point2 = Point(x1, y1 + i - 1);

			int digit = Line(&point1, &point2).digit();
			if (hashmap.find(digit) == hashmap.end()) {
				hashmap.insert(pair<int, int>(digit, 1));
			}
			else {
				hashmap[digit]++;
			}
			//cout << x1 << " " << y1 + i << "竖直直线" << endl;;

		}
		return;
	}
	int g = abs(gcd(x2 - x1, y2 - y1));
	//cout << g << endl;
	if (g == 0) {
		return;
	}
	int dx = (x2 - x1) / g;
	int dy = (y2 - y1) / g;

	for (int i = 1; i < (x2 - x1) / dx; i++) {
		//cout << x1 + i * dx << " " << y1 + i * dy << endl;
					//cout << dy << endl;
		Point point1 = Point(x1 + i * dx, y1 + i * dy);
		Point point2 = Point(x1 + (i - 1) * dx, y1 + (i - 1) * dy);
		int digit = Line(&point1, &point2).digit();
		if (hashmap.find(digit) == hashmap.end()) {
			hashmap.insert(pair<int, int>(digit, 1));
		}
		else {
			hashmap[digit]++;
		}


	}
}


Line::~Line()
{
	if (!printBuffer) {
		free(printBuffer);
	}
};