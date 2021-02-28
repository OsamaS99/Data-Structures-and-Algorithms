#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <string>

using std::string;
using std::vector;
using std::cin;
using std::map;
using std::string;

struct Query {
    string type, name;
    int number;
};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}

vector<string> process_queries(const vector<Query>& queries) {
    vector<string> result;
    // Keep list of all existing (i.e. not deleted yet) contacts.
    vector<Query> contacts;
    map<long, string> phone_book;
    for (size_t i = 0; i < queries.size(); ++i)
        if (queries[i].type == "add") {
            phone_book[queries[i].number] = queries[i].name;
        }
        else if (queries[i].type == "del") {
            auto it = phone_book.find(queries[i].number);
            if (it != phone_book.end()) {
                phone_book.erase(it);
            }
        }
        else {
            string response = "not found";
            auto it = phone_book.find(queries[i].number);
            if (it != phone_book.end()) {
                response = it->second;
            }
            result.push_back(response);
        }
    return result;
}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}
