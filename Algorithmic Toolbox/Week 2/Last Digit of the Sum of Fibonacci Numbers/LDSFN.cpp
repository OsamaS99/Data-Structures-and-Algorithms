#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;
    long long sum = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}
std::vector <int> get_pison_period(long long m) {
    std::vector<int> v;
    v.push_back(0);
    v.push_back(1);

    while (true)
    {
        v.push_back((v[v.size() - 2] + v[v.size() - 1]) % m); // saving the remainder only
        // true if all elemenets between the begining and half way are the same as the elements between the halfway and the end 
        bool sequence = std::equal(v.begin(), v.begin() + v.size() / 2, v.begin() + v.size() / 2, v.end());
        bool even = v.size() % 2 == 0;
        if (even && sequence)
        {
            break;
        }
    }
    return std::vector<int>(v.begin(), v.begin() + (v.size() / 2));
}

int fibonacci_sum_fast(long long n) {
    if (n <= 1)
        return n;
    std::vector<int> pison_of_ten(get_pison_period(10));
    int accumulated_period = std::accumulate(pison_of_ten.begin(), pison_of_ten.end(), 0);
    long long repeats = (long long)ceil(n / pison_of_ten.size());
    int number_of_remainders = n % pison_of_ten.size();
    long long sum = repeats * accumulated_period;
    for (int i = 0; i < number_of_remainders + 1; i++) {
        sum += pison_of_ten[i];
    }
    return sum % 10;
}




int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}
