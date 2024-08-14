#include <cmath>
#include "NzengiMethod.h"

double NzengiMethod::dynamicParameters(double x, double& alpha, int& k) {
    alpha = log2(x) / 10;
    k = std::max(5, static_cast<int>(floor(log10(x))));
    return alpha;
}

double NzengiMethod::fractalDecomposition(double x, int depth) {
    if (depth == 0) {
        return sqrt(x);
    } else {
        return pow(fractalDecomposition(sqrt(x), depth - 1), 2);
    }
}

double NzengiMethod::errorCorrection(double initialResult, double expectedResult, int iterations) {
    double finalResult = initialResult;
    for (int i = 0; i < iterations; ++i) {
        double error = (finalResult - expectedResult) / pow(2, i);
        finalResult -= error;
    }
    return finalResult;
}

double NzengiMethod::compute(double x, int n, int depth) {
    double alpha;
    int k;
    dynamicParameters(x, alpha, k);
    
    double decomposedResult = fractalDecomposition(x, depth);
    double transformedResult = (log(pow(decomposedResult, n)) / log(alpha) + n * sqrt(x)) / k;
    
    return errorCorrection(transformedResult, decomposedResult, k);
}
