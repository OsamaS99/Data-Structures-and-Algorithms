#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <string>

using std::cin;
using std::string;
using std::vector;

// Find all occurrences of the pattern in the text and return a
// vector with all positions in the text (starting from 0) where 
// the pattern starts in the text.
vector<int> ComputePrefix(const string& s) {
    size_t s_length = s.length();
    vector<int> result (s_length);
    result[0] = 0;
    int border = 0;
    for (int i = 1; i < s_length; i++) {
        while (border > 0 && s[i] != s[border]) {
            border = result[border - 1];
        }
        if (s[i] == s[border]) {
            border++;
        }
        else {
            border = 0;
        }
        result[i] = border;
    }
    return result;
}
vector<int> find_pattern(const string& pattern, const string& text) {
    vector<int> result;
    string search_string = pattern + '$' + text;
    size_t pattern_length = pattern.length();
    size_t text_length = text.length();
    vector<int> bds = ComputePrefix(search_string);
    for (int i = pattern_length + 1; i < pattern_length + 1 + text_length; i++) {
        if (bds[i] == pattern_length) {
            result.push_back(i - 2 * pattern_length);
        }
    }

    // Implement this function yourself
    return result;
}

int main() {
    string pattern, text;
    cin >> pattern;
    cin >> text;
    vector<int> result = find_pattern(pattern, text);
    for (int i = 0; i < result.size(); ++i) {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}
