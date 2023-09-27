#include <iostream>
#include "value.h"
#include "myFunctions.h"


int main() {
   Value x1{2.0};
   Value x2{0.0};
   Value w1{-3.0};
   Value w2{1.0};
   Value b{6.8813735870195432};
   Value x1w1 = x1 * w1;
   Value x2w2 = x2 * w2;
   Value x1w1x2w2 = x1w1 + x2w2;
   Value n = x1w1x2w2 + b;
   Value o = n.tanh_h();
   //Value o = tan_h(n); // Think this works if I call it as a method from the Value class
   o.backward();

    std::cout << "w2: " << w2 << "\n";
    std::cout << "x2: " << x2 << "\n";
    std::cout << "x1: " << x1 << "\n";
    std::cout << "w1: " << w1 << "\n";
    std::cout << "x2w2: " << x2w2 << "\n";
    std::cout << "x1w1: " << x1w1 << "\n";
    std::cout << "x1w1w2: " << x1w1x2w2 << "\n";
    std::cout << "b: " << b << "\n";
    std::cout << "n: " << n << "\n";
    std::cout << "o: " << o << "\n";













    return 0;
}
