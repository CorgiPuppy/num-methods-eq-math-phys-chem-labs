#include <iostream>
#include <cmath>

#include "../include/Constants.h"

int main() {
	int N_x = (Constants::x_end - Constants::x_start) / Constants::h;
	int N_t[Constants::amount_of_delta_t] = {0};
	for (int i = 0; i < Constants::amount_of_delta_t; i++)
		N_t[i] = (Constants::t_end - Constants::t_start) / Constants::delta_t[i];

	double u[N_t[0]][N_x] = {0.0};
	for (int j = 0; j <= N_x - 1; j++) {
		u[0][j] = std::exp((j - 1) * Constants::h);
	}	

	int n = 0;

	while (!(n == (N_t[0] - 1))) {
		for (int j = 1; j <= N_x - 2; j++)
			u[n + 1][j] = u[n][j] + (Constants::delta_t[2]) / (std::pow(Constants::h, 2)) * (u[n][j + 1] - 2 * u[n][j] + u[n][j - 1]);
		
		u[n + 1][0] = std::exp((n + 1) * Constants::delta_t[2]);
		u[n + 1][N_x - 1] = std::exp((n + 1) * Constants::delta_t[2] + 1);
	
		n++;
	}

	for (int n = 0; n < N_t[0]; n++) {
		for (int j = 0; j < N_x; j++)
		       printf("%.3f ", u[n][j]);
		std::cout << std::endl;
	}

	return 0;
}
