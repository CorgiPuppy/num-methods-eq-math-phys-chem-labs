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
			u[0][j] = std::exp(j * Constants::h);
		}	

		int n = 0;
		while (!(n == (N_t[i] - 1))) {
			for (int j = 1; j <= N_x - 2; j++)
				u[n + 1][j] = u[n][j] + (Constants::delta_t[i]) / (std::pow(Constants::h, 2)) * (u[n][j + 1] - 2 * u[n][j] + u[n][j - 1]);
			
			u[n + 1][0] = std::exp((n + 1) * Constants::delta_t[i]);
			u[n + 1][N_x - 1] = std::exp((n + 1) * Constants::delta_t[i] + 1);
		
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
