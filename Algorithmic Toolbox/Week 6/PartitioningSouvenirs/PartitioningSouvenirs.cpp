#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <stdlib.h>


using namespace std;


int Partitioning(vector<int> elements) {
	int Total_Value = accumulate(elements.begin(), elements.end(), 0);
	std::sort(elements.begin(), elements.end());
	std::reverse(elements.begin(), elements.end());
	if (Total_Value % 3 != 0) {
		return 0;
	}
	int Each_Value = Total_Value / 3;
	for (int x = 0; x < 3; x++) {
		int in_Value = Each_Value;
		auto it = elements.begin();
		while (it != elements.end()) {
			if (*it <= in_Value) {
				in_Value -= *it;
				it = elements.erase(it);
				if (in_Value == 0) {
					break;
				}
			}
			else {
				it++;
			}
		}
		if (in_Value > 0) {
			return 0;
		}
	}
	if (elements.size() == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int partition3(vector<int>& A)
{
	int sum = accumulate(A.begin(), A.end(), 0);
	if (sum % 3 != 0)
	{
		return false;
	}
	int size = A.size();

	vector<vector<int>> Table(sum + 1, vector<int>(sum + 1, 0));
	Table[0][0] = true;

	// process the numbers one by one
	for (int i = 0; i < size; i++)
	{
		for (int j = sum; j >= 0; --j)
		{
			for (int k = sum; k >= 0; --k)
			{
				if (Table[j][k])
				{
					Table[j + A[i]][k] = true;
					Table[j][k + A[i]] = true;
				}
			}
		}
	}
	return Table[sum / 3][sum / 3];
}


int main() {
	srand(time(NULL));
	while (true){
		int x = (rand() % 10) + 1;
		cout << x << endl;
		vector<int> z;
		for (int i = 0 ; i < x ; i++) {
			int y = rand() % 50 + 1;
			cout << y << " ";
		    z.push_back(y);
		}
		cout << endl;
		int p3 = partition3(z);
		int p = Partitioning(z);
		if (p == p3) {
			cout << "P :" << p << endl;
			cout << "P3 :" << p3 << endl;
			cout << "OK" << endl;
		}
		else {
			cout << "P :" << p << endl;
			cout << "P3 :" << p3 << endl;
			cout << "Error" << endl;
			return 1;
		}
	}

	return 0;
}
