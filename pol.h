#pragma once

#include <iostream>
#include <string>
#include <list>
#include <initializer_list>
#include <cmath>
#include <algorithm>

const double PI = 3.14159265;

struct Point
{
	double lat, lon;
	std::string name;
	double rating;
};

class Pol
{
private:
	std::list<Point> points;

public:
	Pol(const std::initializer_list<Point>&);
	void nearest_point(const Point&, double, double) const;
	void points_count(const Point&, double, double) const;
	void search_by_name(const std::string&);
	void azimuth(const Point&, const Point&);
};