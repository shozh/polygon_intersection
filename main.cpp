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


    r A(1, 0), B(0, 2), C(5, 2);
    r a(4, 0), b(1, 3), c(6, 4);

    vector<r> v1 = {A, B, C};
    vector<r> v2 = {a, b, c};

    ConvexPolygon T(v1), Y(v2);

    ConvexPolygon Z = intersect(T, Y);

   for (auto ver: Z.vertices)
       cout << ver << " ";
   cout << "\n";

	return 0;
}
