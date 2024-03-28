#ifndef __CONVEX_POLYGON_H__
#define __CONVEX_POLYGON_H__

#include <vector>
#include <cstdint>
#include <initializer_list>
#include "r.h"
#include "segline.h"

struct ConvexPolygon {
	uint32_t n;
	std::vector<r> vertices;

	ConvexPolygon(const ConvexPolygon& other);
	ConvexPolygon(const std::vector<r>& rs);
	ConvexPolygon(std::initializer_list<r> rlist);

};

ConvexPolygon intersect(ConvexPolygon T, ConvexPolygon Y);


#endif // __CONVEX_POLYGON_H__