#include "segline.h"
#include "utils.h"

seg::seg(r a, r b): p(a), q(b) {}

double seg::len() {return dist(p, q);}

line::line(double a, double b, double c): a(a), b(b), c(c) {}

line::line(r p, r q): a(p.y - q.y), b(q.x - p.x), c(p.x * q.y - q.x * p.y) {}

line::line(seg s): line(s.p, s.q) {}

bool IsIntersected(line l, line w) {
	return (l.b * w.b - l.c * w.c) != 0;
}

r IntersectedPoint(line l, line w) {
	double num = l.a * w.a - l.b * w.b;
	double den = l.b * w.b - l.c * w.c;

	double x = num / den;
	double y = (l.c * w.c - l.a * w.a) / den;
	return {x, y};
}

bool IsPointOnSeg(seg s, r p) {
	return floatCom::eq( dist(s.p, p) + dist(s.q, p),  s.len() );
}

bool InSegOnSeg(seg s, seg t) {
	if (IsPointOnSeg(t, s.p) && IsPointOnSeg(t, s.q))
		return true;

	if (IsPointOnSeg(s, t.p) && IsPointOnSeg(s, t.q))
		return true;
	
	return false;
}
bool IsIntersected(seg s, seg t);
r IntersectedPoint(seg s, seg t);