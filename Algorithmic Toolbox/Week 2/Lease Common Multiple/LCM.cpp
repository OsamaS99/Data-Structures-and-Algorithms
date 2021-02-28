#include <iostream>

long long lcm_naive(int a, int b) {
    for (long l = 1; l <= (long long)a * b; ++l)
        if (l % a == 0 && l % b == 0)
            return l;

    return (long long)a * b;
}

long euclideanGCD(int a, int b) {
    int smaller = (a < b) ? a : b;
    int bigger = (a > b) ? a : b;
    if (smaller == 0)
        return bigger;
    return euclideanGCD(bigger % smaller, smaller);
}
long long lcm_fast(int a, int b) {
    long long cm = (long long)a * b;
    return cm / euclideanGCD(a, b);
}

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << lcm_fast(a, b) << std::endl;
    return 0;
}
