#ifndef __UTILS_H__
#define __UTILS_H__


#include <cmath>
#define EPS 1e-7

namespace floatCom {

	inline bool eq(double a, double b) {
		return std::fabs(a - b) < EPS;
	}

	inline bool ge(double a, double b) {
		return a > b || eq(a, b);
	}

	inline bool le(double a, double b) {
		return a < b || eq(a, b);
	}

	inline bool ne(double a, double b) {
		return !eq(a, b);
	}

};


inline double det2(double a, double b, double c, double d) {
	return a*d - b*c;
}

#endif // __UTILS_H__