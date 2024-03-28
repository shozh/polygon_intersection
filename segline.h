#ifndef __SEGLINE_H__
#define __SEGLINE_H__

#include "r.h"

enum class TripletOrientation {
	collinear, clockwise, counterclockwise
};

enum class PointLinePosition {
	below = -1, on, above
};

struct seg {
	r p, q;

	seg(r a, r b);

	double len();
};

struct line {
	double a, b, c;

	line(double a, double b, double c);

	line(r p, r q);

	explicit line(seg s);


//    PointLinePosition plp = l.findPointPosition(p);
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
	PointLinePosition findPointPosition(r p);
};



bool IsIntersected(line l, line w);
r IntersectedPoint(line l, line w);




bool IsIntersected(seg s, seg t);
r IntersectedPoint(seg s, seg t);

//switch (o) {
//    case TripletOrientation::collinear:
//        std::cout << "collinear" << "\n";
//        break;
//    case TripletOrientation::clockwise:
//        std::cout << "clockwise" << "\n";
//        break;
//    case TripletOrientation::counterclockwise:
//        std::cout << "counterclockwise" << "\n";
//        break;
TripletOrientation orientation(r a, r b, r c);

bool IsPointOnSeg(seg s, r p);
bool IsSegOnSeg(seg s, seg t);
seg SegIntersected(seg s, seg t);



#endif // __SEGLINE_H__