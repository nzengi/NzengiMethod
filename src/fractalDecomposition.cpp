#include <cmath>
#include "NzengiMethod.h"

double NzengiMethod::fractalDecomposition(double x, int depth) {
    if (depth == 0) {
        return sqrt(x);
    } else {
        return pow(fractalDecomposition(sqrt(x), depth - 1), 2);
    }
}
