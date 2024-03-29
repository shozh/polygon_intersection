#include "convex_polygon.h"
#include <algorithm>
#include <unordered_set>
#include <cmath>

namespace std {
    template <>
    struct hash<r> {
        size_t operator()(const r& p) const {
            size_t h1 = std::hash<double>()(p.x);
            size_t h2 = std::hash<double>()(p.y);
            return h1 ^ (h2 << 1); // Простое комбинирование хэшей для Point
        }
    };
}

ConvexPolygon::ConvexPolygon(const ConvexPolygon& other) {
	vertices = other.vertices;
	n = other.n;
}

void ConvexPolygon::SetPoints(std::vector<r>& rs) {

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

ConvexPolygon::ConvexPolygon(std::vector<r>& rs) {
    SetPoints(rs);
}

ConvexPolygon::ConvexPolygon(std::initializer_list<r> rlist) {
    std::vector<r> vec(rlist.begin(), rlist.end());
    SetPoints(vec);
}

PointPolygonPosition ConvexPolygon::findPointPosition(r p) const {

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

ConvexPolygon intersect(const ConvexPolygon& T,  const ConvexPolygon& Y) {
    std::unordered_set<r> main_points;

    for (size_t i = 0; i != T.n; ++i) {
        for (size_t j = 0; j != Y.n; ++j) {

            seg tseg(T.vertices[i], T.vertices[(i+1) % T.n]);
            seg yseg(Y.vertices[j], Y.vertices[(j+1) % Y.n]);
            if (IsSegOnSeg(tseg, yseg)) {
                seg res = SegIntersected(tseg, yseg);
                main_points.insert(res.p);
                main_points.insert(res.q);
            }
            else if (IsIntersected(tseg, yseg))
                main_points.insert(IntersectedPoint(tseg, yseg));
        }

    }

    for (r v: T.vertices)
        if (Y.findPointPosition(v) == PointPolygonPosition::inside)
            main_points.insert(v);

    for (r v: Y.vertices)
        if (T.findPointPosition(v) == PointPolygonPosition::inside)
            main_points.insert(v);

    std::vector<r> vec(main_points.begin(), main_points.end());

    return ConvexPolygon(vec);
}

void intersects(std::vector<ConvexPolygon>& polygons) {
    size_t N = polygons.size();
    if (N == 0) {
        std::cout << "Нет пересечения!" << "\n";
        return;
    }

    if (N == 1) {
        if (polygons[0].n == 0) {
            std::cout << "Нет пересечения!" << "\n";
            return;
        }

        if (polygons[0].n == 1) {
            std::cout << "Точка пересечения: " << polygons[0].vertices[0] << "\n";
            return;
        }

        std::cout << "Точки персечения: ";
        for (r ver: polygons[0].vertices)
            std::cout << ver << "; ";
        std::cout << "\n";
        if (polygons[0].n >= 3)
            std::cout << "Площадь пересечения: " << polygons[0].area() << ".\n";
        if (polygons[0].n == 2)
            std::cout << "Длина пересечения: " << dist(polygons[0].vertices[0], polygons[0].vertices[1]) << ".\n";
        return;
    }

    ConvexPolygon intersection = intersect(polygons[0], polygons[1]);

    if (intersection.n == 0) {
        std::cout << "Нет пересечения!" << "\n";
        return;
    }

    for (size_t i = 2; i != N; ++i) {
        intersection = intersect(intersection, polygons[i]);
        if (intersection.n == 0) {
            std::cout << "Нет пересечения!" << "\n";
            return;
        }
    }

    if (intersection.n == 1) {
        std::cout << "Точка пересечения: " << intersection.vertices[0] << "\n";
        return;
    }

    std::cout << "Точки персечения: ";
    for (r ver: intersection.vertices)
        std::cout << ver << "; ";
    std::cout << "\n";
    if (intersection.n >= 3)
        std::cout << "Площадь пересечения: " << intersection.area() << ".\n";
    if (intersection.n == 2)
        std::cout << "Длина пересечения: " << dist(intersection.vertices[0], intersection.vertices[1]) << ".\n";
}