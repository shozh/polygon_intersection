#include "convex_polygon.h" // convex polygon
#include "segline.h" // segment and line
#include "r.h" // point and vector

#include <iostream>
#include <vector>
using namespace std;

int main() {

//   vector<r> vec { {2, 1}, {9, 10}, {4, 1}, {1, 3}, {4, 9}, {1, 6}, {10, 3}, {10, 7} };
//
//    ConvexPolygon cp(vec);
//
//   for (auto ver: cp.vertices)
//       cout << ver << " ";
//   cout << "\n";


    r A(0, 0), B(2, 0), C(0, 2);
    r a(0, 2), b(2, 4), c(0, 4);

    vector<r> v1 = {A, B, C};
    vector<r> v2 = {a, b, c};

    ConvexPolygon T(v1), Y(v2);

    ConvexPolygon Z = intersect(T, Y);

   for (auto ver: Z.vertices)
       cout << ver << " ";
   cout << "\n";

	return 0;
}
