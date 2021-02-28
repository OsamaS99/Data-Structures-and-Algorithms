#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;




class HeapBuilder {
private:
    vector<int> data_;
    vector< pair<int, int> > swaps_;

    void WriteResponse() const {
        cout << swaps_.size() << "\n";
        for (int i = 0; i < swaps_.size(); ++i) {
            cout << swaps_[i].first << " " << swaps_[i].second << "\n";
        }
    }

    void ReadData() {
        int n;
        cin >> n;
        data_.resize(n);
        for (int i = 0; i < n; ++i)
            cin >> data_[i];
    }
    int left_child(int i) {
        return (i) *2  +1;
    }
    int right_child(int i) {
        return (i)*2 +2;
    }
    void sift_down(int i) {
        int minIndex = i;
        int size = data_.size();
        int l = left_child(i);
        if (l <= size - 1 && data_[minIndex] > data_[l]) {
            minIndex = l;
        }
        int r = right_child(i);
        if (r <= size - 1 && data_[minIndex] > data_[r]) {
            minIndex = r;
        }
        if (i != minIndex) {
            swap(data_[i], data_[minIndex]);
            swaps_.push_back(make_pair(i, minIndex));
            sift_down(minIndex);
        }
    }

    void GenerateSwaps() {
        swaps_.clear();
        // The following naive implementation just sorts 
        // the given sequence using selection sort algorithm
        // and saves the resulting sequence of swaps.
        // This turns the given array into a heap, 
        // but in the worst case gives a quadratic number of swaps.
        //
        // TODO: replace by a more efficient implementation
        for (int i = data_.size() / 2; i >= 0; --i)
            sift_down(i);
    }

public:
    void Solve() {
        ReadData();
        GenerateSwaps();
        WriteResponse();
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    HeapBuilder heap_builder;
    heap_builder.Solve();
    return 0;
}
