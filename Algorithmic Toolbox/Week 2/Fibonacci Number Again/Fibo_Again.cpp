#include <algorithm>
#include <vector>
#include <iostream>
#include <vector>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;


long long get_fibonacci_huge_fast(long long n, long long m) {
    std::vector<int> v;
    v.push_back(0); 
    v.push_back(1); 

    while (true)
    {
        v.push_back((v[v.size() - 2] + v[v.size() - 1]) % m); 
        bool sequence = std::equal(v.begin(), v.begin() + v.size() / 2, v.begin() + v.size() / 2, v.end());
        bool even = v.size() % 2 == 0;
        if (even && sequence)
        {
            break;
        }
    }
    int remainder = n % v.size();
    return v[remainder];
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}