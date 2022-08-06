#include <iostream>
#include "pol.h"

int main()
{
	Pol pol
	{
		{
			{ 10.2, 36.4, "Center", 4.9 },
			{ 53.6, 90.1, "Cafe", 3.0 },
			{ 1.6, 50.6, "Church", 0.9 },
			{ 96.6, 70.6, "Office", 4.0 },
			{ 23.6, 25.9, "Park", 2.0 },
		}
	};

	Point myLocation{ 0.0, 0.0, "My location", 0.0 };
	Point randomPlace{ 30.0, 40.0, "Random place", 5.0 };

	pol.nearest_point(myLocation, 40, 0.5);
	pol.points_count(myLocation, 110, 3);
	pol.search_by_name("Office");
	pol.azimuth(myLocation, randomPlace);

	std::cin.get();
	return 0;
}