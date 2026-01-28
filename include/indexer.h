#ifndef INDEXER_H
#define INDEXER_H

#include <string>
#include <unordered_map>
#include <map>

// word -> (document -> frequency)
using InvertedIndex = std::unordered_map<
    std::string,
    std::map<std::string, int>
>;

InvertedIndex buildIndex(const std::string& docsPath);
void printIndexSummary(const InvertedIndex& index);

#endif
