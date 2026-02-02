#ifndef SEARCH_H
#define SEARCH_H

#include "indexer.h"
#include <string>

void searchWord(const InvertedIndex& index, const std::string& query);

#endif
