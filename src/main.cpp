#include <iostream>
#include <string>
#include "indexer.h"
#include "search.h"
#include <cctype>


using namespace std;

int main() {
    cout << "Mini Search Engine - Phase 2: Search Queries\n";

    InvertedIndex index = buildIndex("data/docs");

    string query;
    cout << "\nEnter a word to search: ";
    cin >> query;

    // Normalize input to lowercase
    for (char& c : query) c = tolower(c);

    searchWord(index, query);

    return 0;
}
