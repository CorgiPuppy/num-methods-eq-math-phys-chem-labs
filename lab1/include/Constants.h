#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

namespace Constants {
	const int x_start = 0;
	const int x_end = 1;

	const int t_start = 0;
	const int t_end = 1;

	const int amount_of_delta_t = 3;
	const double delta_t[] = { 0.1, 0.01, 0.001 };
	const double h = 0.1;
	
	const std::string csvPath = "outputs/output.csv";
	const std::string plotPath = "plots/dat-files/u_t_x.dat";
}

#endif
