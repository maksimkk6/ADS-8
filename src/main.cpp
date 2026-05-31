// Copyright 2021 NNTU-CS
#include "bst.h"
#include <iostream>

void makeTree(BST<std::string>& tree, const char* fname);
void printFreq(BST<std::string>& tree);

int main() {
    BST<std::string> tree;
    
    makeTree(tree, "src/war_peace.txt");
    
    if (tree.empty()) {
        std::cout << "No words found!" << std::endl;
        return 1;
    }
    
    std::cout << "Unique words: " << tree.getSize() << std::endl;
    std::cout << "Tree depth: " << tree.depth() << std::endl;
    std::cout << std::endl;
    
    printFreq(tree);
    
    std::string w = "war";
    if (tree.search(w)) {
        std::cout << "\nWord '" << w << "' found." << std::endl;
    }
    
    return 0;
}
