package com.stateEquation;

import java.lang.Math;

public class Main {
	private static final int x_start = 0;
	private static final int x_end = 1;

	// private static final int t_start = 0;
	// private static final int t_end = 1;

	private static final double[] delta_t = { 0.1, 0.01, 0.001 };
	private static final double[] h = { 0.1, 0.01 };

	private static final double[] xPoints = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
	private static final double epsilon = 1e-6;
	private static final int maxIterations = 10000;

    public static void main( String[] args ) {
		for (int index_h = 0; index_h < h.length; index_h++) {
			int N = (int) (1 + (x_end - x_start) / h[index_h]);

			for (int index_delta_t = 0; index_delta_t < delta_t.length; index_delta_t++) {
				// int N_t = (int) (1 + (t_end - t_start) / delta_t[index_delta_t]);

				double[][] u = new double[2][(int) N];
				for (int j = 0; j <= N - 1; j++)
					u[0][j] = 4.0;

			// int n = 0;
			// boolean flag = false;
			// while (!flag && n < maxIterations) {
			// 	for (int j = 1; j <= N - 2; j++)
			// 		u[1][j] = (u[0][j + 1] + (1 + 1 * h[index_h]) * u[0][j - 1] + Math.pow(h[index_h], 2) * 4) / (1 * h[index_h] + 2 * 1);
			// 	u[1][0] = 1.0;
			// 	u[1][N - 1] = 6.7;

			// 	double sum = 0.0;
			// 	for (int j = 0; j < N; j++)
			// 		sum += Math.pow(u[1][j] - u[0][j], 2);
			// 	double norma = Math.sqrt(h[index_h] * sum);
			// 	
			// 	if (norma <= epsilon)
			// 		flag = true;	
			// 	else {
			// 		double[] temp = u[0];
			// 		u[0] = u[1];
			// 		u[1] = temp;
			// 		n++;
			// 	}
			// }

				double a = - 0.5 * delta_t[index_delta_t] / (h[index_h] * h[index_h]);
				double b = 1.0 + 0.5 * delta_t[index_delta_t] / h[index_h] + delta_t[index_delta_t] / (h[index_h] * h[index_h]);
				double c = - (0.5 * delta_t[index_delta_t] / h[index_h] + 0.5 * delta_t[index_delta_t] / (h[index_h] * h[index_h]));

				int n = 0;
				boolean flag = false;
				while (!flag && n < maxIterations) {
				// for (int n = 0; n < N_t - 1; n++) { 
					double[] alpha = new double[N];
					double[] beta = new double[N];

					alpha[0] = 0.0;
					beta[0] = 1.0;

					for (int j = 1; j <= N - 2; j++) {
						double xi = u[0][j] + 0.5 * delta_t[index_delta_t] / (h[index_h] * h[index_h]) * (u[0][j + 1] - 2.0 * u[0][j] + u[0][j - 1]) - 0.5 * delta_t[index_delta_t] / h[index_h] * (u[0][j] - u[0][j - 1]) + delta_t[index_delta_t] * 4;
						alpha[j] = - a / (b + c * alpha[j - 1]);
						beta[j] = (xi - c * beta[j - 1]) / (b + c * alpha[j - 1]);
					}

					u[1][N - 1] = 6.7;

					for (int j = N - 2; j >= 0; j--)
						u[1][j] = alpha[j] * u[1][j + 1] + beta[j];
					
					double sum = 0.0;
					for (int j = 0; j < N; j++)
						sum += Math.pow(u[1][j] - u[0][j], 2);
					double norma = Math.sqrt(h[index_h] * sum);

					if (norma <= epsilon)
						flag = true;	
					else {
						double[] temp = u[0];
						u[0] = u[1];
						u[1] = temp;
						n++;
					}
				}

				System.out.println("dt\t\th\t\tx\tu(x)");
				for (double x : xPoints) {
					int j = (int) Math.round(x / h[index_h]);
					if (j >= N) j = N-1;
					System.out.printf("%f\t%f\t%.1f\t%.6f\n", delta_t[index_delta_t], h[index_h], x, u[1][j]);
				}
			}
		}
    }
}
