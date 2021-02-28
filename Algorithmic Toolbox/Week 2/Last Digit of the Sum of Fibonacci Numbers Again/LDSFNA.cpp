#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>


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

long long get_fibonacci_partial_sum_fast(long long from, long long to) {
    
    std::vector<int> pison_of_ten(get_pison_period(10));
    int accumulated_period = std::accumulate(pison_of_ten.begin(), pison_of_ten.end(), 0);
    long long to_repeats = (long long)ceil(to / pison_of_ten.size());
    long long from_repeats = (long long)ceil(from / pison_of_ten.size());
    long long repeats = to_repeats - from_repeats;
    int to_number_of_remainders = to % pison_of_ten.size();
    int from_number_of_remainders = from % pison_of_ten.size();
    long long sum = to_repeats * accumulated_period - from_repeats * accumulated_period;
    for (int i = 0; i < to_number_of_remainders + 1; i++) {
        sum += pison_of_ten[i];
    }
    for (int i = 0; i < from_number_of_remainders ; i++) {
        sum -= pison_of_ten[i];
    }
    return sum % 10;
}




int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
