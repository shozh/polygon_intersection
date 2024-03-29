#include "convex_polygon.h" // convex polygon
#include "segline.h" // segment and line
#include "r.h" // point and vector

#include <iostream>
#include <fstream>
#include <vector>

std::vector<r> parse_line(const std::string& str) {

	std::vector<double> nums;
	std::string num;
	bool numing = false;
	for (char ch: str) {
		if (isdigit(ch) || ch == '.') {
			numing = true;
			num.push_back(ch);
		}
		else {
			if (num == ".") {
				numing = false;
				num.clear();
			}
			if (numing) {
				nums.push_back(std::stod(num));
				numing = false;
				num.clear();
			}

		}
	}
	if (numing) {
		nums.push_back(std::stod(num));
	}

	// нету проверки для нечётного количества чисел
	std::vector<r> ret;

	bool firstEmpty = true;
	double first;
	double second;
	for (double num : nums) {
		if (firstEmpty) {
			first = num;
			firstEmpty = false;
		}
		else {
			firstEmpty = true;
			second = num;
			ret.push_back(r(first, second));
		}
	}

	return ret;
}

int main() {
	std::ifstream ifs("input.txt");

	std::string str;


	int N;
	getline(ifs, str);
	N = str[0] - '0';

   std::vector<ConvexPolygon> polygons;

   while (std::getline(ifs, str)) {
	   std::vector<r> rs = parse_line(str);
	   polygons.push_back(ConvexPolygon(rs));
   }

	intersects(polygons);

   ifs.close();
	return 0;
}
