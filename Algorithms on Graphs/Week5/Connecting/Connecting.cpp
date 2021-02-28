#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <numeric>

using std::vector;
using std::pair;
using std::make_pair;

class Heap_Queue {
private:
    vector<pair<int, double>> hp;
    int size;
    int parent(int ind) {
        return (ind - 1) / 2;
    }
    int left(int ind) {
        return ind * 2 + 1;
    }
    int right(int ind) {
        return ind * 2 + 2;
    }
    void sift_up(int ind) {
        while (ind > 0 && hp[parent(ind)].second > hp[ind].second) {
            std::swap(hp[parent(ind)], hp[ind]);
            ind = parent(ind);
        }
    }
    void sift_down(int ind) {
        int max_ind = ind;
        int l = left(ind);
        if (l <= size && hp[l].second < hp[max_ind].second) {
            max_ind = l;
        }
        int r = right(ind);
        if (r <= size && hp[r].second < hp[max_ind].second) {
            max_ind = r;
        }
        if (ind != max_ind) {
            std::swap(hp[ind], hp[max_ind]);
            sift_down(max_ind);
        }
    }
    void remove(int ind) {
        hp[ind].second = pow(10, 9);
        sift_up(ind);
        Extract_Max();
    }
public:
    Heap_Queue() : hp(vector<pair<int, double>>()), size(-1) {}
    void insert(pair<int, double> element) {
        size++;
        hp.push_back(element);
        sift_up(size);
    }
    pair<int, double> Extract_Max() {
        auto result = hp[0];
        hp[0] = hp[size];
        size--;
        hp.pop_back();
        sift_down(0);
        return result;
    }
    void Change_Priority(pair<int, double> p) {
        auto it = std::find_if(hp.begin(), hp.end(),
            [&p](const pair<int, double>& element) { return element.first == p.first; });
        int index = it - hp.begin();
        double old_second = it->second;
        it->second = p.second;
        if (p.second < old_second) {
            sift_up(index);
        }
        else {
            sift_down(index);
        }
    }
    bool empty() {
        return size == -1;
    }
    bool is_there(int x) {
        auto it = std::find_if(hp.begin(), hp.end(),
            [x](const pair<int, double>& element) { return element.first == x; });
        if (it != hp.end()) {
            return true;
        }
        else {
            return false;
        }
    }

};

double calculate_distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow((x1-x2) , 2) + pow((y1-y2) , 2));
}

vector<vector<pair<int, double>>> Calc_Weight(vector<int> x, vector<int> y) {
    size_t Vertices = x.size();
    vector<vector<pair<int, double>>> result(Vertices, vector<pair<int, double>>());
    for (int i = 0; i < Vertices; i++) {
        for (int j = 0; j < Vertices ; j++) {
            if (j == i) {
                continue;
            }
            result[i].push_back(make_pair(j, calculate_distance(x[i], y[i], x[j], y[j])));
        }
    }
    return result;
}

double minimum_distance(vector<int> x, vector<int> y) {
    size_t vertices = x.size();
    double max = pow(10, 6);
    vector<vector<pair<int, double>>> Weights = Calc_Weight(x,y) ;
    vector<double> costs(vertices, max);
    vector<int> Parent(vertices);
    Parent[0] = -1;
    costs[0] = 0;
    Heap_Queue H;
    for (int i = 0; i < vertices; i++) {
        H.insert(make_pair(i, costs[i]));
    }

    while (!H.empty()) {
        auto prio = H.Extract_Max();
        for (int i = 0; i < vertices - 1; i++) {
            if (H.is_there(Weights[prio.first][i].first) && costs[Weights[prio.first][i].first] > Weights[prio.first][i].second) {
                costs[Weights[prio.first][i].first] = Weights[prio.first][i].second;
                auto to_update = make_pair(Weights[prio.first][i].first , costs[Weights[prio.first][i].first]);
                H.Change_Priority(to_update);
            }
        }
    }

    return std::accumulate(costs.begin(), costs.end(), 0.0);


}

int main() {
    size_t n;
    std::cin >> n;
    vector<int> x(n), y(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }
    std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
