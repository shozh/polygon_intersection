#ifndef __SEGLINE_H__
#define __SEGLINE_H__

#include <r.h>

struct seg {
	r p, q;

	seg(r a, r b);
};

struct line {
	double a, b, c;

	line(double a, double b, double c);

	line(r a, r b);
};

bool is_intersected(seg s, seg t);
//bool is_intersected(line l, line w);



r intersection_point(seg s, seg t);
//r intersection_point(line l, line w);


#endif // __SEGLINE_H__