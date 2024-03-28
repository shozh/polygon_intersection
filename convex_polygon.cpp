#include "convex_polygon.h"


ConvexPolygon(const ConvexPolygon& other);
ConvexPolygon(const std::vector<r>& rs);
ConvexPolygon(std::initializer_list<r> rlist);

PointPolygonPosition findPointPosition(r p);

double area();

ConvexPolygon& intersect(const ConvexPolygon& T, const ConvexPolygon& Y);