#include "convex_polygon.h" // convex polygon
#include "segline.h" // segment and line
#include "r.h" // point and vector

#include <iostream>
#include <vector>
using namespace std;

int main() {

   vector<r> vec { {2, 1}, {9, 10}, {4, 1}, {1, 3}, {4, 9}, {1, 6}, {10, 3}, {10, 7} };

    ConvexPolygon cp(vec);

   r p(3, 3);

   for (auto ver: cp.vertices)
       cout << ver << " ";
   cout << "\n";


//   line l(r(1, 3), r(1, 6) );

//   r p(-1, 9);
//
//    PointLinePosition plp = l.findPointPosition(p);
//
//    switch (plp) {
//        case PointLinePosition::above:
//            std::cout << "above" << "\n";
//            break;
//        case PointLinePosition::below:
//            std::cout << "below" << "\n";
//            break;
//        case PointLinePosition::on:
//            std::cout << "on" << "\n";
//            break;
//    }

//        switch (o) {
//            case TripletOrientation::collinear:
//                std::cout << "collinear" << "\n";
//                break;
//            case TripletOrientation::clockwise:
//                std::cout << "clockwise" << "\n";
//                break;
//            case TripletOrientation::counterclockwise:
//                std::cout << "counterclockwise" << "\n";
//                break;


    cout << cp.area() << endl;

	return 0;
}
