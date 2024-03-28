#include "convex_polygon.h" // convex polygon
#include "segline.h" // segment and line
#include "r.h" // point and vector

#include <iostream>
#include <vector>
using namespace std;

int main() {

   vector<r> vec { {2, 0}, {4, 0}, {6, 2}, {4, 4}, {2, 4}, {0, 2} };

   ConvexPolygon cp(vec);

   for (auto ver: cp.vertices)
       cout << ver << " ";
   cout << "\n";

    cout << "eh" << "\n";
	return 0;
}
