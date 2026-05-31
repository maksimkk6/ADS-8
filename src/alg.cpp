// Copyright 2021 NNTU-CS
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>
#include "bst.h"

void makeTree(BST<std::string>& tree, const char* fname) {
    std::ifstream file(fname);
    
    if (!file) {
        std::cout << "File error!" << std::endl;
        return;
    }
    
    std::string word;
    char ch;
    
    while (file.get(ch)) {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            word += std::tolower(ch);
        } else {
            if (!word.empty()) {
                tree.insert(word);
                word.clear();
            }
        }
    }
    
    if (!word.empty()) {
        tree.insert(word);
    }
    
    file.close();
}

void printFreq(BST<std::string>& tree) {
    if (tree.empty()) {
        std::cout << "Tree empty" << std::endl;
        return;
    }
    
    std::vector<std::pair<std::string, int>> nodes = tree.getNodes();
    
    std::sort(nodes.begin(), nodes.end(), 
        [](const std::pair<std::string, int>& a, 
           const std::pair<std::string, int>& b) {
            return a.second > b.second;
        });
    
    std::ofstream out("result/freq.txt");
    
    if (!out) {
        std::cout << "Cannot create file" << std::endl;
        return;
    }
    
    std::cout << "Frequency (descending):" << std::endl;
    std::cout << "=======================" << std::endl;
    
    out << "Frequency (descending):" << std::endl;
    out << "=======================" << std::endl;
    
    for (const auto& p : nodes) {
        std::cout << p.first << ": " << p.second << std::endl;
        out << p.first << ": " << p.second << std::endl;
    }
    
    out.close();
}
