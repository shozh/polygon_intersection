#include "r.h"
#include <iostream>
#include "utils.h"
#include <cmath>


r::r() {}
r::r(double x, double y): x(x), y(y) {}


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

}

r operator- (r a) {
	
}

r operator+ (r a, r b);
r operator- (r a, r b);

r operator* (double x, r a);
r operator/ (r a, double x);

double operator* (r a, r b);
double operator^ (r a, r b);

bool operator|| (r a, r b);
bool codirected(r a, r b);
bool oppdirected(r a, r b);


std::ostream& operator<< (std::ostream& out, r a);
std::istream& operator>>(std::istream &in, r &a);