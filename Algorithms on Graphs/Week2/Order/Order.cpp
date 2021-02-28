#include <iostream>
#include <vector>
#include <stack>
using std::vector;
using std::pair;
using std::stack;

struct Vertex {
    vector<int> edges;
    int state; //1 = Unexplored , 2 = On Stack , 3 = Done
    Vertex() : state(1), edges(vector<int>()) {}
};



void explore(vector<Vertex>& adj, int current , stack<int>& to_print) {
    if (adj[current].state == 1 && adj[current].edges.empty()) {
        adj[current].state = 3;
        to_print.push(current + 1);
        return;
    }
    else if (adj[current].state == 1 && !adj[current].edges.empty()) {
        adj[current].state = 2;
        for (auto edge : adj[current].edges) {
            if (adj[edge].state == 1) {
                explore(adj, edge,to_print);
            }
            else if (adj[edge].state == 2) {
                adj[current].state = 4; //cycle ;
                return;
            }
        }
        adj[current].state = 3;
        to_print.push(current + 1);
    }
    return;
}
void DFS(vector<Vertex>& adj, stack<int> &to_print) {
    for (int i = 0; i < adj.size(); i++) {
        if (adj[i].state == 1) {
            explore(adj, i,to_print);
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
    }
    stack <int> to_print;
    DFS(adj,to_print);
    while (!to_print.empty()) {
        std::cout << to_print.top()<<" ";
        to_print.pop();
    }
}
