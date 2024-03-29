#include "convex_polygon.h" // convex polygon
#include "segline.h" // segment and line
#include "r.h" // point and vector

#include <iostream>
#include <vector>
using namespace std;

int main() {

    ConvexPolygon A = {{-2, 0}, {0, 2}, {-2, 3}};
    ConvexPolygon B = {{0, 0}, {2, 0}, {0, 2}};
    ConvexPolygon C = {{0, 2}, {0, 4}, {2, 4}};

    vector<ConvexPolygon> v = {A, B, C};

    intersects(v);
	return 0;
}
