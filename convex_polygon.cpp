#include "convex_polygon.h"


ConvexPolygon::ConvexPolygon(const ConvexPolygon& other) {
}



ConvexPolygon::ConvexPolygon(const std::vector<r>& rs) {

}


ConvexPolygon::ConvexPolygon(std::initializer_list<r> rlist) {

}


PointPolygonPosition ConvexPolygon::findPointPosition(r p) {
	
	
}

double ConvexPolygon::area() {
	double s = 0;
	for (size_t i = 0; i != n; ++i)
		s += vertices[i] ^ vertices[(i + 1) % n];
	return abs(s) / 2;
}

ConvexPolygon& intersect(const ConvexPolygon& T, const ConvexPolygon& Y);