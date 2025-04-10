#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

#include "../include/Constants.h"

int main() {
	int N_x = 1 + (Constants::x_end - Constants::x_start) / Constants::h;
	int N_t[Constants::amount_of_delta_t] = {0};
	for (int i = 0; i < Constants::amount_of_delta_t; i++) {
		N_t[i] = 1 + (Constants::t_end - Constants::t_start) / Constants::delta_t[i];
	}

	for (int i = 0; i < Constants::amount_of_delta_t; i++) {
		double** u = new double*[N_t[i]];
		for (int n = 0; n < N_t[i]; n++) {
		    u[n] = new double[N_x] {0.0};
		}

		for (int j = 0; j <= N_x - 1; j++) {
			u[0][j] = 0.0;
		}	

		int n = 0;
		while (!(n == (N_t[i] - 1))) {
			u[n + 1][N_x - 1] = std::pow((n + 1) * Constants::delta_t[i], 2) + (n + 1) * Constants::delta_t[i];
			for (int j = N_x - 2; j >= 0; j--)
				u[n + 1][j] = (u[n][j] + 2 * (Constants::delta_t[i]) / Constants::h * u[n + 1][j + 1] + Constants::delta_t[i] * (j * Constants::h)) / (1 + 2 * Constants::delta_t[i] / Constants::h);	
		// for (int j = 0; j <= N_x - 2; j++)
		// 	u[n + 1][j] = u[n][j] + 2 * Constants::delta_t[i] / Constants::h * (u[n][j + 1] - u[n][j]) + Constants::delta_t[i] * (j * Constants::h);
			n++;
		}

		std::ofstream csvFile(Constants::csvPath[i]);	
		csvFile << std::fixed << std::setprecision(4);

		csvFile << "t\\x,";
		for (int j = 0; j <= N_x - 1; j++) {
			csvFile << j * Constants::h;
			if (j != (N_x - 1)) csvFile << ",";
		}
		csvFile << "\n";
		for (int n = 0; n < N_t[i]; n++) {
			double t = n * Constants::delta_t[i];
			csvFile << t << ",";
			for (int j = 0; j < N_x; j++) {
				csvFile << u[n][j];
				if (j != (N_x - 1)) csvFile << ",";
			}
			csvFile << "\n";
		}
		csvFile.close();

		std::ofstream plotPath (Constants::plotPath[i]);
		for (int n = 0; n <= N_t[i] - 1; n++) {
			double t = n * Constants::delta_t[i];
			for (int j = 0; j <= N_x - 1; j++) {
				double x = j * Constants::h;
				plotPath << t << " " << x << " " << u[n][j] << "\n";
			}
			plotPath << "\n";
		}
		plotPath.close();

		for (int n = 0; n < N_t[i]; n++) {
		    delete[] u[n];
		}
		delete[] u;
	}

	return 0;
}
