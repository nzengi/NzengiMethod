#include <cmath>
#include "NzengiMethod.h"

double NzengiMethod::errorCorrection(double initialResult, double expectedResult, int iterations) {
    double finalResult = initialResult;
    for (int i = 0; i < iterations; ++i) {
        double error = (finalResult - expectedResult) / pow(2, i);
        finalResult -= error;
    }
    return finalResult;
}
