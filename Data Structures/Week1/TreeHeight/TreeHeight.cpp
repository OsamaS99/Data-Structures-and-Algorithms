#include <algorithm>
#include <iostream>
#include <vector>


class Node;

class Node {
public:
    int key{0};
    Node* parent;
    std::vector<Node*> children;

    Node() {
        this->parent = NULL;
    }

    void setParent(Node* theParent) {
        parent = theParent;
        parent->children.push_back(this);
    }
};
int MaxHeight(const Node &node) {
    if (node.children.empty()) {
        return 1;
    }
    std::vector<int> ffs(node.children.size());
    for (int i = 0, n = ffs.size(); i < n; i++) {
        ffs[i] = MaxHeight(*(node.children[i]));
    }
    std::sort(ffs.begin(), ffs.end());
    
    return ffs[node.children.size()-1] + 1;
}

int main_with_large_stack_space() {
    std::ios_base::sync_with_stdio(0);
    int n;
    std::cin >> n;

    std::vector<Node> nodes;
    nodes.resize(n);
    int parents_index = 0;
    for (int child_index = 0; child_index < n; child_index++) {
        int parent_index;
        std::cin >> parent_index;
        if (parent_index == -1) {
            parents_index = child_index;
        }
        if (parent_index >= 0)
            nodes[child_index].setParent(&nodes[parent_index]);
        nodes[child_index].key = child_index;
    }

    // Replace this code with a faster implementation
    

    std::cout << MaxHeight(nodes[parents_index]) << std::endl;
    return 0;
}

int main(int argc, char** argv)
{
    return main_with_large_stack_space();
}
