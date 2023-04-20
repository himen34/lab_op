#pragma once
#include <iostream>
using namespace std;
class TPoint
{
	double x, y;
public:
	TPoint();
	TPoint(double,double);
	TPoint(TPoint&);
	double GetX() const;
	double GetY() const;
	TPoint& operator ++();
	TPoint operator ++(int);
	void ShowPoint(string);
	void ShowPoint(string,string);
	double operator -(TPoint);
	void checker();

};