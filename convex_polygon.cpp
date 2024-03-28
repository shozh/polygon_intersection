#include "convex_polygon.h"
#include <algorithm>
#include <set>
#include <cmath>

ConvexPolygon::ConvexPolygon(const ConvexPolygon& other) {
	vertices = other.vertices;
	n = other.n;
}

ConvexPolygon::ConvexPolygon(std::vector<r>& rs) {

	sort(rs.begin(), rs.end());


	// point, seg, triangle
	if (rs.size() <= 3) {
		vertices = rs;
		n = rs.size();
		return;
	}

	// quadrilateral
	if (rs.size() == 4) {
		r A, B;
		if (IsIntersected(seg(rs[0], rs[1]), seg(rs[2], rs[3]))) {
			A = rs[0];
			B = rs[1];
		} else {
			A = rs[1];
			B = rs[0];
		}
		
		r C, D;
		if (IsIntersected(seg(B, rs[2]), seg(A, rs[3]))) {
			C = rs[3];
			D = rs[2];
		} else {
			C = rs[2];
			D = rs[3];
		}

		vertices = {A, B, C, D};
		n = 4;
		return;
	}

	// ge 4 vertices
	std::vector<r> order(rs.size());
	std::vector<r> nexts(++rs.begin(), rs.end());

	order[0] = *rs.begin();

	for (int i = 1; i < rs.size() - 3; ++i) {
		for (auto it = nexts.begin(); it != nexts.end(); ++it) {
			r next = *it;
			line l(order[i-1], next);
			PointLinePosition plps[rs.size() - 2];
			size_t j = 0;
			for (r p: rs)
				if (p != next && p != order[i-1])
					plps[j++] = l.findPointPosition(p);

			bool flag = true;
			for (size_t k = 1; k < rs.size() - 2; ++k)
				if (plps[0] != plps[k]) {
					flag = false;
					break;
				}
			if (flag) {
				order[i] = next;
				nexts.erase(it);
                break;
			}	
		}
	}

	r real_preprepreprev = order[rs.size()-5];
	r real_prepreprev = order[rs.size()-4];
	r preprev = nexts[0];
	r prev = nexts[1];
	r last = nexts[2];

	r real_preprev;
	r real_prev;
	r real_last;

	std::vector<r> temp_vec = {real_preprepreprev, preprev, prev, last};

	for (auto it = temp_vec.begin(); it != temp_vec.end(); ++it) {
        r temp = *it;
        if (temp == real_preprepreprev)
            continue;
		line l(temp, real_prepreprev);
		PointLinePosition plps[3];
		size_t i = 0;
		for (r remp: temp_vec)
            if (remp != temp)
			    plps[i++] = l.findPointPosition(remp);

		if (plps[0] == plps[1] && plps[1] == plps[2]) {
            temp_vec.erase(it);
			real_preprev = temp;
			break;
		}
	}


    prev = temp_vec[1];
    last = temp_vec[2];

	line l(real_preprev, prev);

	if (l.findPointPosition(last) == l.findPointPosition(real_prepreprev)) {
		real_prev = prev;
		real_last = last;
	} else {
		real_prev = last;
		real_last = prev;
	}

	order[rs.size()-3] = real_preprev;
	order[rs.size()-2] = real_prev;
	order[rs.size()-1] = real_last;

	vertices = order;
	n = order.size();
}


//ConvexPolygon::ConvexPolygon(std::initializer_list<r> rlist) {}


PointPolygonPosition ConvexPolygon::findPointPosition(r p) {

    // Point case
    if (n == 1) {
        if (vertices[0] == p)
            return PointPolygonPosition::on;
        else
            return PointPolygonPosition::outside;
    }

    // Segment case
    if (n == 2) {
        seg t(vertices[0], vertices[1]);

        if (IsPointOnSeg(t, p))
            return PointPolygonPosition::on;
        else
            return PointPolygonPosition::outside;
    }

    TripletOrientation o1 = orientation(vertices[0], vertices[1], p);
    if (IsPointOnSeg(seg(vertices[0], vertices[1]), p))
        return PointPolygonPosition::on;


    for (size_t i = 2; i != n; ++i) {
        seg s(vertices[i-1], vertices[i]);
        if (IsPointOnSeg(s, p))
            return PointPolygonPosition::on;
        TripletOrientation o = orientation(vertices[i-1], vertices[i], p);

        if (o != o1)
            return PointPolygonPosition::outside;
        }


    TripletOrientation on = orientation(vertices[n-1], vertices[0], p);
    if (IsPointOnSeg(seg(vertices[n-1], vertices[0]), p))
        return PointPolygonPosition::on;

    if (o1 != on)
        return PointPolygonPosition::outside;
    
    return PointPolygonPosition::inside;
}

double ConvexPolygon::area() {
	double s = 0;
	for (size_t i = 0; i != n; ++i)
		s += vertices[i] ^ vertices[(i + 1) % n];
	return fabs(s) / 2.;
}

//ConvexPolygon& intersect(const ConvexPolygon& T, const ConvexPolygon& Y);