#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::string;
using std::vector;

int LettertoInt(const char& ffs) {
    switch(ffs) {
    case '$': return 0;
    case 'A': return 1;
    case 'C': return 2;
    case 'G': return 3;
    case 'T': return 4;
    }
}

vector<int> SortCharachters(const string& s) {
    size_t s_length = s.length();
    vector<int> alphas(5);
    vector<int> result(s_length);
    for (int i = 0; i < s_length; i++) {
        alphas[LettertoInt(s[i])] ++;
    }
    for (int i = 1; i < 5; i++) {
        alphas[i] += alphas[i - 1] ;
    }
    for (int i = s_length - 1; i >= 0; i--) {
        int c = LettertoInt(s[i]);
        alphas[c] --;
        result[alphas[c]] = i;
    }
    return result;
}

vector<int> ComputeClass(const string& s, vector<int> order) {
    size_t s_length = s.length();
    vector<int> result(s_length);
    result[order[0]] = 0;
    for (int i = 1; i < s_length; i++) {
        if (s[order[i]] == s[order[i - 1]]) {
            result[order[i]] = result[order[i - 1]];
        }
        else {
            result[order[i]] = result[order[i - 1]] +1;
        }
    }
    return result;
}

vector<int> sortDoubled(const string& S, int L, vector<int> clas, vector<int > order) {
    size_t S_length = S.length();
    vector<int> count(S_length);
    vector<int> newOrder(S_length);
    for (int i = 0; i < S_length; i++) {
        count[clas[i]] ++;
    }
    for (int i = 1; i < S_length; i++) {
        count[i] += count[i - 1];
    }
    for (int i = S_length - 1; i >= 0; i--) {
        int start = (order[i] - L + S_length) % S_length;
        auto c_Class = clas[start];
        count[c_Class] = count[c_Class] - 1;
        newOrder[count[c_Class]] = start;
    }
    return newOrder;
}

vector<int> updateDoubled(vector<int> Class, vector<int> newOrder, int L) {
    size_t n_length = newOrder.size();
    vector<int> newClass(n_length);
    newClass[newOrder[0]] = 0;
    for (int i = 1; i < n_length; i++) {
        auto cur = newOrder[i], prev = newOrder[i - 1];
        auto mid = (cur + L) % n_length, midPrev = (prev + L) % n_length;
        if (Class[cur] != Class[prev] || Class[mid] != Class[midPrev]) {
            newClass[cur] = newClass[prev] + 1;
        }
        else {
            newClass[cur] = newClass[prev];
        }
    }
    return newClass;
}


vector<int> BuildSuffixArray(const string& text) {
    vector<int> order = SortCharachters(text);
    vector<int> Class = ComputeClass(text, order);
    int L = 1;
    size_t txt = text.length();
    while (L < txt) {
        order = sortDoubled(text,L, Class, order);
        Class = updateDoubled(Class, order, L);
        L *= 2;
    }
    return order;
}

int main() {
    string text;
    cin >> text;
    vector<int> suffix_array = BuildSuffixArray(text);
    for (int i = 0; i < suffix_array.size(); ++i) {
        cout << suffix_array[i] << ' ';
    }
    cout << endl;
    return 0;
}
