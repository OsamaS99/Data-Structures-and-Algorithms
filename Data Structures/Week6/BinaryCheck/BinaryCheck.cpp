#include <algorithm>
#include <iostream>
#include <vector>
#include <limits.h>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
    int key;
    int left;
    int right;

    Node() : key(0), left(-1), right(-1) {}
    Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

int mx(const vector<Node>& tree , int i) {
    if (i == -1) {
        return INT_MIN;
    }
    if (tree[i].right == -1) {
        return tree[i].key;
    }
    mx(tree, tree[i].right);
}
int mn(const vector<Node>& tree, int i) {
    if (i == -1) {
        return INT_MAX;
    }
    if (tree[i].left == -1) {
        return tree[i].key;
    }
    mn(tree, tree[i].left);
}

bool IsBinarySearchTree(const vector<Node>& tree , int i) {
    // Implement correct algorithm here

        if (tree.size() == 0) {
            return true;
        }
        else if ((tree[i].left == -1 && tree[i].right == -1)) {
            return true;
        }
        else if (tree[i].key <= mx(tree, tree[i].left) || tree[i].key > mn(tree, tree[i].right)) {
            return false;
        }
        else if(tree[i].left == -1){
            return IsBinarySearchTree(tree, tree[i].right);
        }
        else if (tree[i].right == -1) {
            return IsBinarySearchTree(tree, tree[i].left);
        }
        else {
            return IsBinarySearchTree(tree, tree[i].left) && IsBinarySearchTree(tree, tree[i].right);
        }
        return false;
}

int main() {
    int nodes;
    cin >> nodes;
    vector<Node> tree;
    for (int i = 0; i < nodes; ++i) {
        int key, left, right;
        cin >> key >> left >> right;
        tree.push_back(Node(key, left, right));
    }
    if (IsBinarySearchTree(tree ,0)) {
        cout << "CORRECT" << endl;
    }
    else {
        cout << "INCORRECT" << endl;
    }
    return 0;
}
