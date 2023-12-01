#include <iostream>
#include <cmath>

using namespace std;

// Function to perform Naive Gaussian Elimination
void naiveGaussElimination(double matrix[3][4]) {
    int n = 3;

    // Forward Elimination
    for (int i = 0; i < n - 1; i++) {
        for (int k = i + 1; k < n; k++) {
            double factor = matrix[k][i] / matrix[i][i];
            for (int j = i; j < n + 1; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }

    // Backward Substitution
    for (int i = n - 1; i >= 0; i--) {
        matrix[i][n] /= matrix[i][i];
        matrix[i][i] = 1;

        for (int k = i - 1; k >= 0; k--) {
            matrix[k][n] -= matrix[k][i] * matrix[i][n];
            matrix[k][i] = 0;
        }
    }
}

int main() {
    // Given velocity vs. time data
    double time[] = {5, 8, 12};
    double velocity[] = {106.8, 177.2, 279.2};

    // Initialize the augmented matrix
    double matrix[3][4];

    // Populate the matrix
    for (int i = 0; i < 3; i++) {
        matrix[i][0] = pow(time[i], 2);
        matrix[i][1] = time[i];
        matrix[i][2] = 1;
        matrix[i][3] = velocity[i];
    }

    // Apply Naive Gaussian Elimination
    naiveGaussElimination(matrix);

    // Output the results
    cout << "Results after Naive Gaussian Elimination:" << endl;
    cout << "a1 = " << matrix[0][3] << endl;
    cout << "a2 = " << matrix[1][3] << endl;
    cout << "a3 = " << matrix[2][3] << endl;

    // Calculate velocity at t = 6 seconds
    double t = 6;
    double v_at_t6 = matrix[0][3] * pow(t, 2) + matrix[1][3] * t + matrix[2][3];

    cout << "Velocity at t = 6 seconds: " << v_at_t6 << " m/s" << endl;

    return 0;
}
