#include <iostream>
#include <string>
#include<vector>
#include <algorithm>


using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int EditDistance(const string &first,const string &second);
int mini(int x, int y, int z) {
	vector<int> mint{ x , y , z };
	std::sort(mint.begin(), mint.end());
	return mint[0];
}

int main() {
	string first;
	string second;
	cin >> first >> second;
	cout << EditDistance(first, second) << endl;
	return 0;
}


int EditDistance(const string &first, const string &second) {
	string first_cpy = " " + first;
	string second_cpy = " " + second;
	int first_l = first_cpy.length(); 
	int second_l = second_cpy.length(); 
	vector <int> intitilizer(first_l);
	vector <vector<int>> D_array;
	for (int i = 0; i < second_l; i++) {
		D_array.push_back(intitilizer);
	}
	for (int i = 0; i < first_l; i++) {
		D_array[0][i] = i;
	}
	for (int i = 0; i < second_l; i++) {
		D_array[i][0] = i;
	}
	for (int i = 1; i < second_l; i++) {
		for (int j = 1; j < first_l; j++) {
			int insertion = D_array[i][j-1] +1 ;
			int deletion = D_array[i-1][j] +1 ;
			int mismatch = D_array[i-1][j-1] +1 ;
			int match = D_array[i-1][j-1] ;
			if (first_cpy[j] == second_cpy[i]) {
				D_array[i][j] = mini(insertion, match, deletion);
			}
			else {
				D_array[i][j] = mini(insertion, mismatch, deletion);
			}

		}
	}
	return D_array[second_l - 1][first_l - 1];
}
