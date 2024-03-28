#ifndef __CONVEX_POLYGON_H__
#define __CONVEX_POLYGON_H__

#include <vector>
#include <cstdint>
//#include <initializer_list>
#include "r.h"
#include "segline.h"

//switch (fpp) {
//case PointPolygonPosition::inside:
//cout << "inside" << endl;
//break;
//case PointPolygonPosition::outside:
//cout << "outside" << endl;
//break;
//case PointPolygonPosition::on:
//cout << "on" << endl;
//break;
//}
enum class PointPolygonPosition {
	outside, inside, on
};


struct ConvexPolygon {
	size_t n;
	std::vector<r> vertices;

	ConvexPolygon(const ConvexPolygon& other);
	ConvexPolygon(std::vector<r>& rs);
	//ConvexPolygon(std::initializer_list<r> rlist);

	PointPolygonPosition findPointPosition(r p) const;

	double area();
};

ConvexPolygon intersect(const ConvexPolygon& T, const ConvexPolygon& Y);


#endif // __CONVEX_POLYGON_H__