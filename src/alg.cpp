// Copyright 2021 NNTU-CS
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include "bst.h"

void makeTree(BST<std::string>& tree, const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return;
    }

    std::string wrd;
    char ch;

    while (file.get(ch)) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            if (ch >= 'A' && ch <= 'Z') {
                ch = ch - 'A' + 'a';
            }
            wrd += ch;
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
    if (!out.is_open()) {
        return;
    }
    for (size_t i = 0; i < nodes.size(); i++) {
        out << nodes[i].first << ": " << nodes[i].second << std::endl;
    }
    out.close();
}
