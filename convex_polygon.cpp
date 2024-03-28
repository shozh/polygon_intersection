#include "convex_polygon.h"
#include <algorithm>
#include <set>


ConvexPolygon::ConvexPolygon(const ConvexPolygon& other) {
	vertices = other.vertices;
	n = other.n;
}

	ConvexPolygon::ConvexPolygon(const std::vector<r>& rs) {

	sort(rs.begin(), rs.end());


	if (rs.size() <= 3) {
		vertices = rs;
		n = rs.size();
		return;
	}

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


	std::vector<r> order(rs.size());
	std::vector<r> nexts(++rs.begin(), rs.end());

	order[0] = *rs.begin();
	size_t chosen = 1;

	for (int i = 1; i < rs.size() - 3; ++i) {
		chosen++;
		for (auto it = nexts.begin(); it != nexts.end(); ++it) {
			r next = *it;
			line l(order[i-1], next);
			PointLinePosition plps[rs.size() - chosen];
			size_t j = 0;
			for (r p: nexts)
				if (p != next)
					plps[j++] = l.findPointPosition(p);
			
			bool flag = true;
			for (size_t k = 1; k < rs.size() - chosen; ++k)
				if (plps[0] != plps[k]) {
					flag = false;
					break;
				}
			if (flag) {
				order[i] = next;
				nexts.erase(it);
			}	
		}		
	}

	r preprepreprev = order[rs.size()-5];
	r prepreprev = order[rs.size()-4];
	r preprev = nexts[0];
	r prev = nexts[1];
	r last = nexts[2];

	std::vector<r> temp_vec = {preprepreprev, preprev, prev, last};

	for (temp: temp_vec) {
		
	}
	
}


//ConvexPolygon::ConvexPolygon(std::initializer_list<r> rlist) {}


PointPolygonPosition ConvexPolygon::findPointPosition(r p) {
	
}

double ConvexPolygon::area() {
	double s = 0;
	for (size_t i = 0; i != n; ++i)
		s += vertices[i] ^ vertices[(i + 1) % n];
	return abs(s) / 2;
}

ConvexPolygon& intersect(const ConvexPolygon& T, const ConvexPolygon& Y);