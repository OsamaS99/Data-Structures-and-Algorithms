#include <iostream>
#include <vector>

using std::vector;
using std::pair;
using std::make_pair;





void reach(vector<pair<vector<int>, bool>>& adj, int start) {
    adj[start].second = true;
    for (int x : adj[start].first) {
        if (!adj[x].second) {
            reach(adj, x);
        }
    }

}

int main() {
    size_t n, m;
    std::cin >> n >> m;
    vector<pair<vector<int>,bool> > adj(n);
    for (size_t i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].first.push_back(y - 1);
        adj[y - 1].first.push_back(x - 1);
    }
    for (auto x : adj) {
        x.second = false;
    }
    int x, y;
    std::cin >> x >> y;
    reach(adj, x - 1);
    if (adj[x - 1].second && adj[y - 1].second) {
        std::cout << 1;
    }
    else {
        std::cout << 0;
    }
}
