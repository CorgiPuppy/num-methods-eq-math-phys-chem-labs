#include <iostream>

#include "../include/Constants.h"

void calc_explicit();

int main() {
	int N_x = (Constants::x_end - Constants::x_start) / Constants::h;
	int N_t[Constants::amount_of_delta_t] = {0};
	for (int i = 0; i < Constants::amount_of_delta_t; i++)
		N_t[i] = (Constants::t_end - Constants::t_start) / Constants::delta_t[i];

	std::cout << N_x << std::endl;	
	for (int i = 0; i < Constants::amount_of_delta_t; i++)
		std::cout << N_t[i] << std::endl;
	
	int u[N_x][N_t] = {0};

	return 0;
}

void calc_explicit() {
}
