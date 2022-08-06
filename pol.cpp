#include "pol.h"

Pol::Pol(const std::initializer_list<Point>& lst)
{
	for (const auto& element : lst)
	{
		points.push_back(element);
	}
}

void Pol::nearest_point(const Point& location, double radius, double min_rating) const
{
	std::list<Point>::const_iterator it = points.cend();

	for (int i = 1; i <= radius; ++i)
	{
		it = std::find_if(points.begin(), points.end(),
			[location, i, min_rating](const Point& p)
			{
				double distance = sqrt(pow(p.lat - location.lat, 2) + pow(p.lon - location.lon, 2));

				return distance <= i && p.rating >= min_rating;
			});
		
		if (it != points.cend())
		{
			break;
		}
	}

	if (it != points.end())
	{
		std::cout << "The nearest point is " << it->name << std::endl;
	}
	else
	{
		std::cout << "The nearest point is not found" << std::endl;
	}
}

void Pol::points_count(const Point& location, double radius, double min_rating) const
{
	int cnt = std::count_if(points.begin(), points.end(),
		[location, radius, min_rating](const Point& p)
		{
			bool inCircle = (pow(p.lat - location.lat, 2) + pow(p.lon - location.lon, 2)) <= pow(radius, 2);

			return inCircle && p.rating >= min_rating;
		});

	std::cout << "There are " << cnt << " points with rating more than " << min_rating << std::endl;
}

void Pol::search_by_name(const std::string& search)
{
	auto it = std::find_if(points.begin(), points.end(),
		[search](const Point& p)
		{
			return p.name == search;
		});

	if (it != points.end())
	{
		std::cout << "The point named \"" << search << "\" was found" << std::endl;
	}
	else
	{
		std::cout << "The point named \"" << search << "\" was not found" << std::endl;
	}
}

void Pol::azimuth(const Point& p1, const Point& p2)
{
	std::cout << "Azimuth: " << 180 / PI * std::atan2(p2.lat - p1.lat, p2.lon - p1.lon) << " degrees" << std::endl;
}
