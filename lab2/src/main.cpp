#include <iostream>
#include <cmath>
#include <fstream>

#include "../include/Constants.h"

int main() {
	int N_x = 1 + (Constants::x_end - Constants::x_start) / Constants::h;
	int N_t[Constants::amount_of_delta_t] = {0};
	for (int i = 0; i < Constants::amount_of_delta_t; i++)
		N_t[i] = 1 + (Constants::t_end - Constants::t_start) / Constants::delta_t[i];

	for (int i = 0; i < Constants::amount_of_delta_t; i++) {
		double** u = new double*[N_t[i]];
		for (int n = 0; n < N_t[i]; n++) {
		    u[n] = new double[N_x]();
		}

		for (int j = 0; j <= N_x - 1; j++) {
			u[0][j] = std::exp(j * Constants::h);
		}	

		double* a = new double[N_x]();
		double* b = new double[N_x]();
		double* c = new double[N_x]();
		double* ksi = new double[N_x]();
		double* alpha = new double[N_x]();
		double* beta = new double[N_x]();

		int n = 0;
		while (!(n == (N_t[i] - 1))) {
			alpha[0] = 0.0;
			beta[0] = std::exp((n + 1) * Constants::delta_t[i]);

			for (int j = 1; j <= N_x - 2; j++) {
				a[j] = - (Constants::delta_t[i]) / (std::pow(Constants::h, 2));
				b[j] = 1 + 2 * (Constants::delta_t[i]) / (std::pow(Constants::h, 2));
				c[j] = - (Constants::delta_t[i]) / (std::pow(Constants::h, 2));
				ksi[j] = u[n][j];
				alpha[j] = - (a[j]) / (b[j] + c[j] * alpha[j - 1]);
				beta[j] = (ksi[j] - c[j] * beta[j - 1]) / (b[j] + c[j] * alpha[j - 1]);
			}
			
			u[n + 1][N_x - 1] = std::exp((n + 1) * Constants::delta_t[i] + 1);
			
			for (int j = N_x - 2; j >= 0; j--) {
				u[n + 1][j] = alpha[j] * u[n + 1][j + 1] + beta[j];
			}

			n++;
		}

		std::ofstream csvFile(Constants::csvPath[i]);	
		csvFile << "t\\x,";
		for (int j = 0; j <= N_x - 1; j++) {
			csvFile << j * Constants::h;
			if (j != (N_x - 1)) csvFile << ",";
		}
		csvFile << "\n";
		for (int n = 0; n < N_t[i]; n++) {
			double t = (n + 1) * Constants::delta_t[i];
			csvFile << t << ",";
			for (int j = 0; j < N_x; j++) {
				csvFile << u[n][j];
				if (j != (N_x - 1)) csvFile << ",";
			}
			csvFile << "\n";
		}
		csvFile.close();

		std::ofstream plotFile(Constants::plotPath[i]);
		for (int n = 0; n < N_t[i]; n++) {
			double t = (n + 1) * Constants::delta_t[i];
			for (int j = 0; j < N_x; j++) {
				double x = j * Constants::h;
				plotFile << t << " " << x << " " << u[n][j] << "\n";
			}
			plotFile << "\n";
		}
		plotFile.close();

		for (int n = 0; n < N_t[i]; n++) {
		    delete[] u[n];
		}

		delete[] u;
		delete[] a;
		delete[] b;
		delete[] c;
		delete[] ksi;
		delete[] alpha;
		delete[] beta;
	}

	return 0;
}
