#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

string BWT(const string& text) {
	size_t txt = text.length();
	string result (txt , 'C');
	vector<string> table(txt , text);
	for (int i = 1; i < txt; i++) {
		for (int j = 1; j < txt; j++) {
			table[i][j] = table[i - 1][j - 1];
		}
		table[i][0] = table[i - 1][txt - 1];
	}
	std::sort(table.begin(), table.end());
	for (int i = 0; i < txt; i++) {
		result[i] = table[i][txt-1];
	}

	return result;
}

int main() {
	string text;
	cin >> text;
	cout << BWT(text) << endl;
	return 0;
}