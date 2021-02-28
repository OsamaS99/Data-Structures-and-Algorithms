#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

int negative_cycle(vector<vector<int> >& adj, vector<vector<int> >& cost) {
    vector<int> costs(adj.size(), pow(10, 4));
    vector<int> previous(adj.size());
    previous[0] = -1;
    costs[0] = 0;
    for (int i = 0; i <= adj.size(); i++) {
        for (int j = 0; j <adj.size() ; j++) {
            for (int k = 0; k < adj[j].size(); k++) {
                if (costs[adj[j][k]] > costs[j] + cost[j][k]) {
                    if (i == adj.size()) {
                        return 1;
                    }
                    costs[adj[j][k]] = costs[j] + cost[j][k];
                    previous[adj[j][k]] = j;
                }
            }
            
        }
    }
    return 0;
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
    std::cout << negative_cycle(adj, cost);
}
