#include <string>
#include <iostream>
#include <stack>



struct Node {
	char key;
	long long size;
	Node* parent;
	Node* left;
	Node* right;

	Node(char key) : key( key ), size( 1 ), parent( NULL ), left( NULL ), right( NULL ) {}
	Node(char key , long long size , Node * parent , Node * left , Node * right) : key{ key }, size{ size }, parent{ parent }, left{ left }, right{ left } {}

};


class Rope {
	std::string s;
	Node* root;
public:
	Rope(const std::string& s) : s(s) {
		root = NULL;
		for (int i = 0, l = s.length(); i < l; i++) {
			Node* Nnext = new Node(s[i]);
			root = merge(root, Nnext);
		}
	}
	void set_size(Node* n) {
		if (n == NULL) {
			return;
		}
		n->size = 1 + ((n->left != NULL) ? n->left->size : 0) + ((n->right != NULL) ? n->right->size : 0);
		if (n->left != NULL) {
			n->left->parent = n;
		}
		if (n->right != NULL) {
			n->right->parent = n;
		}
	}

	void Splay_Shifting(Node* N) {
		Node* parent = N->parent;
		if (parent == NULL) {
			return;
		}
		Node* GParent = N->parent->parent;
		if (parent->left == N) {
			Node* r = N->right;
			N->right = parent;
			parent->left = r;
		}
		else {
			Node* l = N->left;
			N->left = parent;
			parent->right = l;
		}
		set_size(parent);
		set_size(N);
		N->parent = GParent;
		if (GParent != NULL) {
			if (GParent->left == parent) {
				GParent->left = N;
			}
			else {
				GParent->right = N;
			}
		}
		
	}
	void Splay_Rotations(Node* N) {
		if (N->parent->left == N && N->parent->parent->left == N->parent) {
			Splay_Shifting(N->parent);
			Splay_Shifting(N);
		}
		else if (N->parent->right == N && N->parent->parent->right == N->parent) {
			Splay_Shifting(N->parent);
			Splay_Shifting(N);
		}
		else {
			Splay_Shifting(N);
			Splay_Shifting(N);
		}
	}
	void splay(Node*& root, Node* N) {
		if (N == NULL) {
			return;
		}
		while (N->parent != NULL) {
			if (N->parent->parent == NULL) {
				Splay_Shifting(N);
				break;
			}
			Splay_Rotations(N);
		}
		root = N;
	}
	Node* find_with_rank(Node*& root, int rank) {
		Node* N = root;
		while (N != NULL) {
			long long sz = (N->left != NULL) ? N->left->size : 0;
			if (rank == (sz + 1)) {
				break;
			}
			else if (rank > (sz+1)) {
				N = N->right;
				rank = rank - sz - 1;
			}
			else if (rank < (sz + 1)) {
				N = N->left;
			}
		}
		splay(root, N);
		return N;
	}
	void split(Node* root, int key, Node*& left, Node*& right) {
		right = find_with_rank(root, key);
		splay(root, right);
		if (right == NULL) {
			left = root;
			return;
		}
		left = right->left;
		right->left = NULL;
		if (left != NULL) {
			left->parent = NULL;
		}
		set_size(left);
		set_size(right);
	}

	Node* merge(Node* left, Node* right) {
		if (left == NULL) {
			return right;
		}
		if (right == NULL) {
			return left;
		}
		Node* min_right = right;
		while (min_right->left != NULL) {
			min_right = min_right->left;
		}
		splay(right, min_right);
		right->left = left;
		set_size(right);
		return right;
	}

	void insert_string_after(Node*& root, int k, Node*& SString) {
		Node* left = NULL;
		Node* right = NULL;
		split(root, k, left, right);
		root = merge(merge(left, SString), right);
	}

	std::string In_Order(Node* root) {
		std::string out = "";
		if (root == NULL) {
			return out;
		}
		std::deque<Node*> Dq;
		Node* looper = root;
		while (looper != NULL) {
			Dq.push_back(looper);
			looper = looper->left;
		}
		while (!Dq.empty()) {
		    looper = Dq.back();
			out.push_back(looper->key);
			Dq.pop_back();
			looper = looper->right;
			while (looper != NULL) {
				Dq.push_back(looper);
				looper = looper->left;
			}
		}
		return out;

	}
	void process(int i, int j, int k) {
		Node* left = NULL;
		Node* right = NULL;
		Node* middle = NULL;
		split(root, i + 1, left, middle);
		split(middle, j- i + 2, middle , right);
		root = merge(left, right);
		insert_string_after(root, k + 1, middle);
	}
	

	std::string result() {
		return In_Order(root);
	}
};

int main() {
	std::ios_base::sync_with_stdio(0);
	std::string s;
	std::cin >> s;
	Rope rope(s);
	int actions;
	std::cin >> actions;
	for (int action_index = 0; action_index < actions; ++action_index) {
		int i, j, k;
		std::cin >> i >> j >> k;
		rope.process(i, j, k);
	}
	std::cout << rope.result() << std::endl;
}
