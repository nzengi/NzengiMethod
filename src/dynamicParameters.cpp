#include <cmath>
#include "NzengiMethod.h"

double NzengiMethod::dynamicParameters(double x, double& alpha, int& k) {
    alpha = log2(x) / 10;
    k = std::max(5, static_cast<int>(floor(log10(x))));
    return alpha;
}
