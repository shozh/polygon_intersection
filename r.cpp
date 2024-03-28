#include "r.h"
#include <iostream>
#include "utils.h"
#include <cmath>


r::r() {}
r::r(double x, double y): x(x), y(y) {}

void r::set(double x, double y) {
	this->x = x;
	this->y = y;
}

double r::len() {
	return hypot(x, y);
}

double dist(r a, r b) {
	return hypot(a.x - b.x, a.y - b.y);
}

bool operator== (r a, r b) {
	return floatCom::eq(a.x, b.x) && floatCom::eq(a.y, b.y);
}

bool operator!= (r a, r b) {
	return !(a == b);
}

bool operator< (r a, r b) {
	return (a.x < b.x) && (a.y < b. y);
}

bool operator> (r a, r b) {
	return (a.x > b.x) && (a.y > b. y);
}

bool operator<= (r a, r b) {
	return floatCom::le(a.x, b.x) && floatCom::le(a.y, b.y);
}

bool operator>= (r a, r b) {
	return floatCom::ge(a.x, b.x) && floatCom::ge(a.y, b.y);
}

r operator+ (r a) {
	return a;
}

r operator- (r a) {
	return {-a.x, -a.y};
}

r operator+ (r a, r b) {
	return {a.x + b.x, a.y + b.y};
}

r operator- (r a, r b) {
	return {a.x - b.x, a.y - b.y};
}

r operator* (double x, r a) {
	return {x * a.x, x * a.y};
}

r operator/ (r a, double x) {
	if (floatCom::eq(x, 0))
		return a;
	return {a.x / x, a.y / x};
}

double operator* (r a, r b) {
	return a.x * b.x + a.y * b.y;
}

double operator^ (r a, r b) {
	return a.x*b.y - b.x*a.y;
}

bool operator|| (r a, r b) {
	return floatCom::eq(a ^ b, 0);
}
bool codirected(r a, r b) {
	return (a||b) && (a*b > 0);
}
bool oppdirected(r a, r b) {
    return (a || b) && (a*b < 0);
}

std::ostream& operator<< (std::ostream& out, r a) {
	out << "(" << a.x << ", " << a.y << ")";
	return out;
}
std::istream& operator>>(std::istream &in, r &a) {
	in >> a.x >> a.y;
	return in;
}