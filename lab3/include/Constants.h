#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

namespace Constants {
	const int x_start = 0;
	const int x_end = 1;

	const int t_start = 0;
	const int t_end = 1;

	const int amount_of_delta_t = 1;
	const double delta_t[] = { 0.1 };
	const double h = 0.1;
	
	const std::string csvPath[] = {
		"outputs/output_0.1.csv",
	};
	const std::string plotPath[] = {
		"plots/dat-files/u_t_x_0.1.dat",
	};
}

#endif
