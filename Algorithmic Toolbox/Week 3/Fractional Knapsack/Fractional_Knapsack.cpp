#include <iostream>
#include <vector>
#include <algorithm>


using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;
    vector<std::pair<double , int>> values_sorted;
    for (int i = 0; i < values.size(); i++) {
      
        values_sorted.push_back(std::pair<double,int>(static_cast<double>(values[i]) / weights[i] , i));
    }
    std::sort(values_sorted.begin(), values_sorted.end());
    auto end_it = values_sorted.rbegin();
    auto begin_it = values_sorted.rend();
    for (int i = 0; end_it != begin_it; end_it++ , i++) {
        if (weights[end_it->second] > 0 && capacity > 0) {
            double weight = (weights[end_it->second] < capacity) ? weights[end_it->second] : capacity;
            value += weight * end_it->first;
            capacity -= weight;
            weights[end_it->second] -= weight;
        }
    }
    return value;
}

int main() {
    int n;
    int capacity;
    std::cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
    return 0;
}
