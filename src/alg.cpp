// Copyright 2021 NNTU-CS
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>
#include "bst.h"

void makeTree(BST<std::string>& tree, const char* filename) {
    std::ifstream file(filename);
    if (!file) {
        return;
    }
    
    std::string wrd;
    char c;
    
    while (file.get(c)) {
        if (std::isalpha(static_cast<unsigned char>(c))) {
            wrd += std::tolower(static_cast<unsigned char>(c));
        } else {
            if (!wrd.empty()) {
                tree.insert(wrd);
                wrd.clear();
            }
        }
    }
    
    if (!wrd.empty()) {
        tree.insert(wrd);
    }
    
    file.close();
}

void printFreq(BST<std::string>& tree) {
    std::vector<std::pair<std::string, int>> nodes = tree.getNodes();
    
    std::sort(nodes.begin(), nodes.end(),
        [](const std::pair<std::string, int>& a,
           const std::pair<std::string, int>& b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        });
    
    std::ofstream out("result/freq.txt");
    if (!out) {
        return;
    }
    for (size_t i = 0; i < nodes.size(); i++) {
        out << nodes[i].first << ": " << nodes[i].second << std::endl;
    }
    out.close();
}
