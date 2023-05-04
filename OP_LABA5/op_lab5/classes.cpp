#include "classes.h"
EqTriangle::EqTriangle() {
	a = b = c = rand() % 50 + 1;
}
IsTriangle::IsTriangle() {
	a = b = rand() % 50 + 1;
	do {
		c = rand() % 50 + 1;
	} while (c == a || c == b || a + b <= c || a + c <= b || b + c <= a);
}
RtTriangle::RtTriangle() {
	do {
		a = rand() % 50 + 1;
		b = rand() % 50 + 1;
		c = sqrt(a * a + b * b);
	} while (c * c != a * a + b * b || c != (int)c || a==b);
	
}
void EqTriangle::printTriangle() {
	cout << "Рiвностороннiй трикутник:"<<"(" << this->a << ";"<< this->b<< ";"<< this->c << ")"<<endl;
}
void IsTriangle::printTriangle() {
	cout << "Рiвнобедренний трикутник:" << "(" << this->a << ";" << this->b << ";" << this->c << ")" << endl;
}
void RtTriangle::printTriangle() {
	cout << "Прямокутний трикутник:" << "(" << this->a << ";" << this->b << ";" << this->c << ")" << endl;
}
double EqTriangle::square() {
	return ((sqrt(3) / 4) * a * a);
}
int IsTriangle::perimetr() {
	return 2*a + c;
}
double RtTriangle::square() {
	return (0.5 * a * b);
}