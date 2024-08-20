#ifndef NZENGI_METHOD_H
#define NZENGI_METHOD_H

class NzengiMethod {
public:
    // Calculate dynamic parameters based on the input value x
    double dynamicParameters(double x, double& alpha, int& k);

    // Perform fractal decomposition recursively up to a specified depth
    double fractalDecomposition(double x, int depth);

    // Correct the result by iterating and adjusting based on the error
    double errorCorrection(double initialResult, double expectedResult, int iterations);

    // Compute the final result based on input parameters and depth
    double compute(double x, int n, int depth);
};

#endif
