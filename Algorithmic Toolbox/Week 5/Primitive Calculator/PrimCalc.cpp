#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


pair<int, vector<int>> PrimCalc(int num) {
	vector<int> MinCalcs(num + 1, 0);
	MinCalcs[0] = 0;
	MinCalcs[1] = 0;
	
	for (int i = 2; i <= num; i++) {
		MinCalcs[i] = MinCalcs[i - 1] + 1;
		if (i % 2 == 0) {
			MinCalcs[i] = (1 + MinCalcs[i / 2] < MinCalcs[i]) ? 1 + MinCalcs[i / 2] : MinCalcs[i];
		}
		if (i % 3 == 0) {
			MinCalcs[i] = (1 + MinCalcs[i / 3] < MinCalcs[i]) ? 1 + MinCalcs[i / 3] : MinCalcs[i];
		}
	}
	vector<int> steps;
	int div = num;
	for (int i = 0; i < MinCalcs[num]; i++) {
		if (div % 3 == 0 && MinCalcs[div / 3] == MinCalcs[div] - 1) {
			steps.push_back(div / 3);
			div /= 3;
		}
		else if (div % 2 == 0 && MinCalcs[div / 2] == MinCalcs[div] - 1) {
			steps.push_back(div / 2);
			div /= 2;
		}
		else {
			steps.push_back(div - 1);
			div -= 1;
		}
	}
	reverse(steps.begin(), steps.end());

	return pair<int,vector<int>>(MinCalcs[num] , steps);
}

int main() {
	int x = 0;
	cin >> x; 
	pair<int, vector<int>> out = PrimCalc(x);
	cout << out.first << endl;
	for (int ele : out.second) {
		cout << ele << " ";
	}
	cout << x << endl;

	return 0;
}