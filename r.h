#ifndef __R_H__
#define __R_H__

#include <iostream>

struct r {
	double x, y;

	r();
	r(double x, double y);
	void set(double x, double y);

	double len();
};

double dist(r a, r b);

bool operator== (r a, r b);
bool operator!= (r a, r b);
bool operator< (r a, r b);
bool operator> (r a, r b);
bool operator<= (r a, r b);
bool operator>= (r a, r b);


r operator+ (r a);
r operator- (r a);

r operator+ (r a, r b);
r operator- (r a, r b);

r operator* (double x, r a);
r operator/ (r a, double x);

// скалярное произведение
double operator* (r a, r b);

// векторное произведение, возращает норму
double operator^ (r a, r b);

// коллинеарность
bool operator|| (r a, r b);

// сонапарвленность
bool codirected(r a, r b);

// противоположно направленность
bool oppdirected(r a, r b);


std::ostream& operator<< (std::ostream& out, r a);
std::istream& operator>>(std::istream &in, r &a);




#endif // __R_H__





