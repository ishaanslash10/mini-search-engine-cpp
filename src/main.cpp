#include <iostream>
#include "indexer.h"

using namespace std;

int main() {
    cout << "Mini Search Engine - Phase 1: Indexing Engine\n";

    InvertedIndex index = buildIndex("data/docs");
    printIndexSummary(index);

    return 0;
}
