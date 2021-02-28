#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int const Letters = 4;
int const NA = -1;
struct Node;

struct Node
{
	int next[Letters];
	bool pattern;

	Node() : pattern{false}
	{
		fill(next, next + Letters, NA);
	}

	
};
typedef vector<Node> Trie;



int letterToIndex(const char &letter)
{
	switch (letter)
	{
	case 'A': return 0; break;
	case 'C': return 1; break;
	case 'G': return 2; break;
	case 'T': return 3; break;
	default: assert(false); return -1;
	}
}
Trie Build_Trie(const vector<string>& patterns) {
	Trie result; 
	Node root;
	int Node_Counter = 0;
	result.push_back(root);
	for (auto pattern : patterns) {
		int Current_Node = 0;
		size_t pat_len = pattern.length();
		for (int i = 0; i < pat_len; i++) {
			int current_symbol = letterToIndex(pattern[i]);
			if (result[Current_Node].next[current_symbol] != NA) {
				Current_Node = result[Current_Node].next[current_symbol];
			}
			else {
				Node_Counter++;
				result[Current_Node].next[current_symbol] = Node_Counter;
				Node temp;
				result.push_back(temp);
				Current_Node = Node_Counter;

			}
		}
		result[Current_Node].pattern = true;
	}
	return result;
}

bool PrefixTrieMatching(const string &text, const Trie &patts) {
	int current_symbol = letterToIndex(text[0]);
	Node current_node = patts[0];
	int current_letter_index = 0;
	while (true) {
		if (current_node.next[current_symbol] != -1) {
		    if (patts[current_node.next[current_symbol]].pattern) {
			    return true;
		    }
			current_node = patts[current_node.next[current_symbol]];
			current_letter_index++;
			if (text[current_letter_index] == '\0') {
				return false;
			}
			current_symbol = letterToIndex(text[current_letter_index]);
		}
		else {
			return false;
		}
		
	}
}

vector<int> TrieMatching(const string &Text, const Trie &patts) {
	string cpy = Text;
	vector<int> result;
	int current_index = 0;
	while (cpy[0] != '\0') {
		if (PrefixTrieMatching(cpy, patts)) {
			result.push_back(current_index);
		}
		cpy = Text.substr(++current_index);
	}
	return result;
}


vector <int> solve(const string& text, int n, const vector <string>& patterns)
{
	vector <int> result;
	Trie t = Build_Trie(patterns);
	result = TrieMatching(text, t);
	return result;
}

int main(void)
{
	string t;
	cin >> t;

	int n;
	cin >> n;

	vector <string> patterns(n);
	for (int i = 0; i < n; i++)
	{
		cin >> patterns[i];
	}

	vector <int> ans;
	ans = solve(t, n, patterns);

	for (int i = 0; i < (int)ans.size(); i++)
	{
		cout << ans[i];
		if (i + 1 < (int)ans.size())
		{
			cout << " ";
		}
		else
		{
			cout << endl;
		}
	}

	return 0;
}
