#include <iostream>
#include "NzengiMethod.h"

int main() {
    NzengiMethod nzengi;
    
    double x = 1e6;  // Example input number
    int n = 2;       // Example exponent
    int depth = 5;   // Depth of fractal decomposition
    
    double result = nzengi.compute(x, n, depth);
    std::cout << "Nzengi Method result for x=" << x << ", n=" << n << ", depth=" << depth << ": " << result << std::endl;
    
    return 0;
}
