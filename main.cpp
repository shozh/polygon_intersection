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



    ConvexPolygon T =  {{0, -2}, {3, 1}, {-3, 1}};
    ConvexPolygon Y = {{-1, -1}, {1, -1}, {0, 3}};

    ConvexPolygon Z = intersect(T, Y);

   for (auto ver: Z.vertices)
       cout << ver << " ";
   cout << "\n";

   cout << Z.area() << "\n";

	return 0;
}
