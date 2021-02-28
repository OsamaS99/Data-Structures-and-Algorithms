#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;



string InverseBWT(const string& bwt) {
	size_t txt_size = bwt.length();
	vector<int> txt(boost::counting_iterator<int> (0) , boost::counting_iterator<int>(txt_size-1));
	string result (txt_size ,'0');
	std::sort(txt.begin(), txt.end(), [bwt](const std::size_t& a, const std::size_t& b) -> bool{ return bwt[a] == bwt[b] ? a < b : bwt[a] < bwt[b]; });
	int current_symbol = txt[0];
	for (int i = 0; i < txt_size; i++) {
		current_symbol = txt[current_symbol];
		result [i] = bwt[current_symbol];
	}
	return result;
}


int main() {
	string bwt;
	cin >> bwt;
	cout << InverseBWT(bwt) << endl;
	return 0;
}
