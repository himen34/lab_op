#include "TPoint.h"
TPoint::TPoint() {
	x = y = 1;
}
TPoint::TPoint(double x, double y) {
	this->x=x;
	this->y=y;
}
TPoint::TPoint(TPoint& TPoint) {
	x = TPoint.x;
	y = TPoint.y;

}
double TPoint::GetX() const {
	return x;
}
double TPoint::GetY() const {
	return y;
}
void TPoint::ShowPoint(string s) {
	cout << s << " point coordinates: (" << x << "," << y <<  ")" << endl;
}
void TPoint::ShowPoint(string s, string time ) {
	cout << s << "point coordinates" <<time << ": (" << x << "," << y << ")" << endl;
}
TPoint& TPoint::operator++() {
	x++;
	return *this;
}
TPoint TPoint::operator++(int temp)
{
	TPoint tmp = *this;
	y++;
	return tmp;
}
double TPoint::operator-(TPoint comppoint)
{
	double dx = comppoint.x - this->x;
	double dy = comppoint.y - this->y;
	double distance = sqrt(dx*dx + dy * dy);
	return distance;
}
void TPoint::checker() 
{
	if (x > 0 && y > 0) {
		cout<<"Point belong to first degree\n";
	}
	else if (x < 0 && y > 0) {
		cout << "Point belong to second degree\n";
	}
	else if (x < 0 && y < 0) {
		cout << "Point belong to third degree\n";
	}
	else if (x > 0 && y < 0) {
		cout << "Point belong to fourth degree\n";
	}
}