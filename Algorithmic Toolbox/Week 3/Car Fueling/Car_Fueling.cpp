#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int>& stops) {
    int stops_number = stops.size();
    int current = 0;
    int refills = 0;
    std::deque<int> dists (stops.begin(), stops.end());
    dists.push_front(0);
    dists.push_back(dist);
    while (current <= stops_number) {
        int previous = current;
        while (current <= stops_number && dists[current + 1] - dists[previous] <= tank) {
            current++;
        }
        if (current == previous) {
            return -1;
        }
        if (current <= stops_number) {
            refills++;
        }
    }
    return refills;    
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
