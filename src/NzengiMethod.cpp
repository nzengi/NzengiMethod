#include <cmath>
#include <algorithm> // For std::max and std::floor
#include "NzengiMethod.h"

// Calculate dynamic parameters based on the input value x
double NzengiMethod::dynamicParameters(double x, double& alpha, int& k) {
    if (x <= 0) {
        throw std::invalid_argument("x must be greater than zero");
    }
    alpha = log2(x) / 10;
    k = std::max(5, static_cast<int>(std::floor(log10(x))));
    return alpha;
}

// Perform fractal decomposition recursively up to a specified depth
double NzengiMethod::fractalDecomposition(double x, int depth) {
    if (depth < 0) {
        throw std::invalid_argument("Depth must be non-negative");
    }
    if (depth == 0) {
        return std::sqrt(x);
    } else {
        return std::pow(fractalDecomposition(std::sqrt(x), depth - 1), 2);
    }
}

// Correct the result by iterating and adjusting based on the error
double NzengiMethod::errorCorrection(double initialResult, double expectedResult, int iterations) {
    if (iterations < 0) {
        throw std::invalid_argument("Iterations must be non-negative");
    }
    double finalResult = initialResult;
    for (int i = 0; i < iterations; ++i) {
        double error = (finalResult - expectedResult) / std::pow(2, i);
        finalResult -= error;
    }
    return finalResult;
}

// Compute the final result based on input parameters and depth
double NzengiMethod::compute(double x, int n, int depth) {
    if (x <= 0 || n <= 0 || depth < 0) {
        throw std::invalid_argument("x, n must be positive and depth must be non-negative");
    }
    double alpha;
    int k;
    dynamicParameters(x, alpha, k);
    
    double decomposedResult = fractalDecomposition(x, depth);
    double transformedResult = (std::log(std::pow(decomposedResult, n)) / std::log(alpha) + n * std::sqrt(x)) / k;
    
    return errorCorrection(transformedResult, decomposedResult, k);
}
