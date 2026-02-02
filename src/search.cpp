#include "search.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void searchWord(const InvertedIndex& index, const string& query) {
    auto it = index.find(query);

    if (it == index.end()) {
        cout << "\nNo results found\n";
        return;
    }

    vector<pair<string, int>> results(
        it->second.begin(), it->second.end()
    );

    sort(results.begin(), results.end(),
         [](const auto& a, const auto& b) {
             return a.second > b.second;
         });

    for (const auto& [doc, count] : results) {
        cout << doc << " (" << count << ")\n";
    }
}
