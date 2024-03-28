#include "convex_polygon.h"
#include <algorithm>
#include <set>


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

	r real_preprepreprev = order[rs.size()-5];
	r real_prepreprev = order[rs.size()-4];
	r preprev = nexts[0];
	r prev = nexts[1];
	r last = nexts[2];

	r real_preprev;
	r real_prev;
	r real_last;

	std::vector<r> temp_vec = {real_preprepreprev, preprev, prev, last};

	for (r temp: temp_vec) {
		line l(temp, real_prepreprev);
		PointLinePosition plps[4];
		size_t i = 0;
		for (r remp: temp_vec)
			plps[i++] = l.findPointPosition(remp);

		if (plps[0] == plps[1] && plps[1] == plps[2] && plps[2] == plps[3]) {
			r real_preprev = temp;
			break;
		}
	}

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


//PointPolygonPosition ConvexPolygon::findPointPosition(r p) {}

double ConvexPolygon::area() {
	double s = 0;
	for (size_t i = 0; i != n; ++i)
		s += vertices[i] ^ vertices[(i + 1) % n];
	return abs(s) / 2;
}

//ConvexPolygon& intersect(const ConvexPolygon& T, const ConvexPolygon& Y);