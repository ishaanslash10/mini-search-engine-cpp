#include "indexer.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cctype>

using namespace std;
namespace fs = std::filesystem;

static string normalize(const string& word) {
    string clean;
    for (char c : word) {
        if (isalnum(c))
            clean += tolower(c);
    }
    return clean;
}

InvertedIndex buildIndex(const string& docsPath) {
    InvertedIndex index;

    for (const auto& entry : fs::directory_iterator(docsPath)) {
        ifstream file(entry.path());
        string docName = entry.path().filename().string();
        string word;

        while (file >> word) {
            word = normalize(word);
            if (!word.empty()) {
                index[word][docName]++;
            }
        }
    }

    return index;
}

void printIndexSummary(const InvertedIndex& index) {
    cout << "\nIndexed " << index.size() << " unique words.\n";

    int shown = 0;
    for (const auto& [word, docs] : index) {
        cout << word << " -> ";
        for (const auto& [doc, count] : docs) {
            cout << doc << "(" << count << ") ";
        }
        cout << "\n";
        if (++shown == 10) break;  // don’t spam
    }
}
