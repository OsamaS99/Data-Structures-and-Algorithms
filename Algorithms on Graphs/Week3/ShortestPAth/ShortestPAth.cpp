#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::make_pair;


int distance(vector<pair<vector<int>,int> >& adj, int s, int t) {
    adj[s].second = 0;
    queue<pair<vector<int>, int>> tasks;
    tasks.push(adj[s]);
    while (!tasks.empty()) {
        auto temp = tasks.front();
        tasks.pop();
        for (auto item : temp.first) {
            if (adj[item].second == -1) {
                
                adj[item].second = temp.second + 1;
                tasks.push(adj[item]);
            }
        }
    }
    return adj[t].second;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    vector<pair<vector<int>, int> > adj(n, make_pair(vector<int>(), -1));
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].first.push_back(y - 1);
        adj[y - 1].first.push_back(x - 1);
    }
    int s, t;
    std::cin >> s >> t;
    s--, t--;
    std::cout << distance(adj, s, t);
}
