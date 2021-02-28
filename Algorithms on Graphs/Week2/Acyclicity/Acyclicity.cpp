#include <iostream>
#include <vector>
using std::vector;
using std::pair;


struct Vertex {
    vector<int> edges;
    int state; //1 = Unexplored , 2 = On Stack , 3 = Done
};



void explore (vector<Vertex>& adj , int current) {
    if (adj[current].state == 1 && adj[current].edges.empty()) {
        adj[current].state = 3;

        return ;
    }
    else if (adj[current].state == 1 && !adj[current].edges.empty()) {
        adj[current].state = 2;
        for (auto edge : adj[current].edges) {
            if (adj[edge].state == 1) {
                explore(adj, edge);
            }
            else if (adj[edge].state == 2) {
                adj[current].state = 4; //cycle ;
                return ;
            }
        }
        adj[current].state = 3;
    }
    return;
}
void DFS(vector<Vertex>& adj) {
    for (int i = 0; i < adj.size(); i++) {
        if (adj[i].state == 1) {
            explore(adj, i);
        }
    }
}
int check(vector<Vertex>& adj) {
    for (auto item : adj) {
        if (item.state == 4) {
            return 1;
        }
    }
    return 0;
}

int main() {
    size_t n, m;
    std::cin >> n >> m;
    vector<Vertex> adj(n);
    for (size_t i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].edges.push_back(y - 1);
        adj[x - 1].state = 1;
    }
    DFS(adj);
    std::cout << check(adj);
}
