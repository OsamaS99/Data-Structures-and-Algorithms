#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

pair<int, int> partition(int* arr, int f, int l) {
	int j = f ;
	pair<int, int> ms {0,0};
	for (int i = f+1; i < l; i++) {
		if (arr[i] < arr[f]) {
			j++;
			swap(arr[i] , arr[j]);
		}
	}
	swap(arr[f], arr[j]);
	int q = j;
	ms.first = q;
	for (int i = j + 1; i < l; i++) {
		if (arr[i] == arr[ms.first]) {
			q++;
			swap(arr[i], arr[q]);
		}
		
	}
	ms.second = q;
	return ms;
}

void QuickSort(int* arr, int f, int l) {
	if (f >= l) {
		return;
	}
	int k = (rand() % (l -f) + 1) + f - 1;
	swap(arr[f], arr[k]);
	pair<int,int> lr = partition(arr, f, l);
	QuickSort(arr, f, lr.first);
	QuickSort(arr, lr.second + 1 , l);
}


int main() {
	srand(time(NULL));
	int n = 0;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		int  x = 0;
		cin >> x;
		arr[i] = x;
	}
	QuickSort(arr, 0, n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	delete[] arr;
	return 0;
}