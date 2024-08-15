#include <cmath>
#include "NzengiMethod.h"

double NzengiMethod::compute(double x, int n, int depth) {
    double alpha;
    int k;
    dynamicParameters(x, alpha, k);
    
    double decomposedResult = fractalDecomposition(x, depth);
    double transformedResult = (log(pow(decomposedResult, n)) / log(alpha) + n * sqrt(x)) / k;
    
    return errorCorrection(transformedResult, decomposedResult, k);
}
