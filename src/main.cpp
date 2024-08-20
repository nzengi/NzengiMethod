#include <iostream>
#include "NzengiMethod.h"

int main() {
    try {
        NzengiMethod method;

        double x = 256;
        int n = 5;
        int depth = 3;

        double result = method.compute(x, n, depth);
        std::cout << "Final Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
