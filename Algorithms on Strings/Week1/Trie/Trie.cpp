#include <string>
#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::vector;
using std::string;

typedef map<char, int> edges;
typedef vector<edges> trie;

trie build_trie(vector<string>& patterns) {
    trie t;
    edges x; 
    t.push_back(x);
    int node_counter = 0 ;
    for (string pattern : patterns) {
        int current_node = 0;
        size_t pattern_length = pattern.length();
        for (int i = 0; i < pattern_length; i++) {
            char current_symbol = pattern[i];
            auto it = t[current_node].find(current_symbol);
            if (it != t[current_node].end()) {
                current_node = it->second;
            }
            else {
                t[current_node][current_symbol] = ++node_counter;
                edges temp;
                t.push_back(temp);
                current_node = node_counter;
            }
        }
    }
    return t;
}

int main() {
    size_t n;
    std::cin >> n;
    vector<string> patterns;
    for (size_t i = 0; i < n; i++) {
        string s;
        std::cin >> s;
        patterns.push_back(s);
    }

    trie t = build_trie(patterns);
    for (size_t i = 0; i < t.size(); ++i) {
        for (const auto& j : t[i]) {
            std::cout << i << "->" << j.second << ":" << j.first << "\n";
        }
    }

    return 0;
}