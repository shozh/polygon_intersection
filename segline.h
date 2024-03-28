#ifndef __SEGLINE_H__
#define __SEGLINE_H__

#include <r.h>

enum class TripletOrientation {
	collinear, clockwise, counterclockwise
};

enum class PointLinePosition {
	below = -1, on, above
};

struct seg {
	r p, q;

	seg(r a, r b);

	double len();
};

struct line {
	double a, b, c;

	line(double a, double b, double c);

	line(r a, r b);

	line(seg s);

	PointLinePosition findPointPosition(r p);
};



bool IsIntersected(line l, line w);
r IntersectedPoint(line l, line w);




bool IsIntersected(seg s, seg t);
r IntersectedPoint(seg s, seg t);


TripletOrientation orientation(r p, r q, r t);

bool IsPointOnSeg(seg s, r p);
bool IsSegOnSeg(seg s, seg t);
seg SegIntersected(seg s, seg t);



#endif // __SEGLINE_H__