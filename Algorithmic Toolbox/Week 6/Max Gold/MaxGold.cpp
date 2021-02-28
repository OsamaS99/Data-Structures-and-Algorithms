#include <iostream>
#include <vector>

using namespace std;


int MaxGold(int weight, vector <int> barWeights);


int main() {
	int weight, bars;
	cin >> weight >> bars;
	vector<int> barWeights;
	for (int i = 0; i < bars; i++) {
		int barWeight = 0;
		cin >> barWeight;
		barWeights.push_back(barWeight);
	}
	cout << MaxGold(weight, barWeights);
}


int MaxGold(int weight, vector<int> barWeights) {
	int Av_Weigths = barWeights.size();
	vector<int> one_element_weight(weight +1  , 0);
	vector<vector<int>> Value_Table; 
	for (int i = 0; i < Av_Weigths + 1; i++) {
		Value_Table.push_back(one_element_weight);
	}
	for (int i = 1; i < Av_Weigths+1; i++) {
		for (int j = 1; j < weight + 1; j++) {
			Value_Table[i][j] = Value_Table[i - 1][j];
			if (j >= barWeights[i-1]) {
			   int value = Value_Table[i - 1][j - barWeights[i-1]] + barWeights[i-1];
			   Value_Table[i][j] = (value > Value_Table[i][j]) ? value : Value_Table[i][j];
		    }
		}
	}
	return Value_Table[Av_Weigths][weight];

}