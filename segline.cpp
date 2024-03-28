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

TripletOrientation orientation(r p, r q, r t) 
{ 
	double val = (q.y - p.y) * (t.x - q.x) - (q.x - p.x) * (t.y - q.y);

	if (floatCom::eq(val, 0))
		return TripletOrientation::collinear;
	if (val > 0)
		return TripletOrientation::clockwise;
	return TripletOrientation::counterclockwise;
} 

bool IsPointOnSeg(seg s, r p) {

	if ( ((s.p - p) || (s.q - s.p)) && \
	floatCom::le(p.x, max(s.p.x, s.q.x)) && \
	floatCom::ge(p.x, min(s.p.x, s.q.x)) && \
	floatCom::le(p.y, max(s.p.y, s.q.y)) && \
	floatCom::ge(p.y, min(s.p.y, s.q.y)) )
		return true;
	return false;

	// old realisation using dist
	//return floatCom::eq( dist(s.p, p) + dist(s.q, p),  s.len() );
}

// Is Seg s on Seg t
bool IsSegOnSeg(seg s, seg t) {
	if (IsPointOnSeg(t, s.p) && IsPointOnSeg(t, s.q))
		return true;

	if (IsPointOnSeg(s, t.p) && IsPointOnSeg(s, t.q))
		return true;
	
	return false;
}

// return inner seg 
seg SegIntersected(seg s, seg t) {
	if (IsPointOnSeg(t, s.p))
		return s;
	return t;
}


// without Seg on Seg case
bool IsIntersected(seg s, seg t) {
	if (IsSegOnSeg(s, t))
		return false;

	if (IsPointOnSeg(t, s.p) || IsPointOnSeg(t, s.q))
		return true;
	
	if (IsPointOnSeg(s, t.p) || IsPointOnSeg(s, t.q))
		return true;

	r p1 = s.p;
	r q1 = s.q;
	r p2 = s.p;
	r q2 = s.q;

	TripletOrientation o1 = orientation(p1, q1, p2);
	TripletOrientation o2 = orientation(p1, q1, q2);
	TripletOrientation o3 = orientation(p2, q2, p1);
	TripletOrientation o4 = orientation(p2, q2, q1);

	if (o1 != o2 && o3 != o4) 
		return true; 

	return false;
}

r IntersectedPoint(seg s, seg t) {
	line sl = line(s);
	line st = line(t);
	return IntersectedPoint(sl, st);
}