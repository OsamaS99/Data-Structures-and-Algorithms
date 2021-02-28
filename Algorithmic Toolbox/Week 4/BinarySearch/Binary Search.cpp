#include <iostream>
#include <map>


using namespace std;


int BinarySerch(int *v ,int low, int high, int key) {
	if (high < low) {
		return - 1;
	}
	int middle = low + (high - low) / 2;
	if ((key) == v[middle]) {
		return middle;
	}
	else if(key < v[middle]){
		return BinarySerch(v, low, middle - 1, key);
	}
	else {
		return BinarySerch(v,middle + 1,high, key);
	}
}

int main() {
	int n = 0;
	cin >> n;
	int *p_array = new int[n];
	for (int i = 0; i < n; i++) {
		int x = 0;
		cin >> x;
		p_array[i] = x;
	}
	int k = 0;
	cin >> k;
	int *p_keys =  new int [k];
	for (int i = 0; i < k; i++) {
		int x = 0;
		cin >> x;
		p_keys[i] = x;
	}
	map<int, int > store;
	map<int, int>::iterator  it;
	for (int i = 0; i < k; i++) {
		int key = p_keys[i];
		it = store.find(key);
		if ( it == store.end()) {
			int index = BinarySerch(p_array, 0, n- 1, key);
			store[key] = index;
			cout << index << " ";
		}
		else {
			cout << it->second << " ";
		}
		      
	}
	delete [] p_array;
	delete [] p_keys;

	return 0;

}

