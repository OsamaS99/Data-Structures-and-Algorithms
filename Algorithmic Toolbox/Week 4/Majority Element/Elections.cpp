#include <iostream>
#include <map>


using namespace std;


int MajorityElement(int v[] ,size_t size) {
	map<int, int> elements;
	int majority = size / 2;
	map<int, int>::iterator it;
	for (int i = 0; i < size; i++) {
		it = elements.find(v[i]);
		if (it != elements.end()) {
			it->second++;
		}
		else {
			elements[v[i]] = 1;
		}
	}
	for (auto a : elements) {
		if (a.second > majority) {
			return 1;
		}
	}
	return 0;
}

int main() {
	int n = 0;
	cin >> n;
	int* votes_ptr = new int[n];
	for (int i = 0; i < n; i++) {
		int x = 0;
		cin >> x;
		votes_ptr[i] = x;
	}
	cout << MajorityElement(votes_ptr, n);
	return 0;

}