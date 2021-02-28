#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <climits>
#include <cmath>
#include <algorithm>

using std::vector;
using std::queue;
using std::pair;
using std::make_pair;
using std::priority_queue;

class Heap_Queue {
private :
    vector<pair<int, int>> hp;
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
        hp[ind].second = pow(10,9) ;
        sift_up(ind);
        Extract_Max();
    }
public:
    Heap_Queue() : hp(vector<pair<int, int>>()), size(-1) {}
    void insert(pair<int, int> element) {
        size++;
        hp.push_back(element);
        sift_up(size);
    }
    pair<int, int> Extract_Max() {
        auto result = hp[0];
        hp[0] = hp[size];
        size--;
        hp.pop_back();
        sift_down(0);
        return result;
    }
    void Change_Priority(pair<int, int> p) {
        auto it = std::find_if(hp.begin(), hp.end(),
            [&p](const pair<int, int>& element) { return element.first == p.first; });
        int index = it - hp.begin();
        int old_second = it->second;
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
    
};


long long distance(vector<vector<int> >& adj, vector<vector<int>>& cost, int s, int t) {
    vector<int> costs(adj.size(),pow(10,9) );
    vector<int> prev(adj.size());
    prev[s] = -1;
    costs[s] = 0;
    Heap_Queue H;

    for (int i = 0; i < costs.size(); i++) {
        H.insert(make_pair(i, costs[i]));
    }
    while (!H.empty()) {
        pair<int, int> u = H.Extract_Max();
        
        
        for (int i = 0; i < adj[u.first].size(); i++) {
            if (costs[adj[u.first][i]] >= costs[u.first] + cost[u.first][i]) {
                costs[adj[u.first][i]] = costs[u.first] + cost[u.first][i];
                prev[adj[u.first][i]] = u.first;
                pair<int, int> to_update(adj[u.first][i], costs[adj[u.first][i]]);
                H.Change_Priority(to_update);
              
            }
        }
    }


    int to_return = costs[t];
    if (to_return == pow(10,9)) {
        return -1;
    }
    else {
        return to_return;
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    vector<vector<int> > cost(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y, w;
        std::cin >> x >> y >> w;
        adj[x - 1].push_back(y - 1);
        cost[x - 1].push_back(w);
    }
    int s, t;
    std::cin >> s >> t;
    s--, t--;
    std::cout << distance(adj, cost, s, t);
}
