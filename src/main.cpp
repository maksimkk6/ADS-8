// Copyright 2021 NNTU-CS
#include <iostream>
#include <string>
#include "bst.h"

void makeTree(BST<std::string>& tree, const char* fname);
void printFreq(BST<std::string>& tree);

int main() {
    BST<std::string> tree;

    makeTree(tree, "src/war_peace.txt");

    if (tree.empty()) {
        std::cout << "No words found!" << std::endl;
        return 1;
    }

    printFreq(tree);

    return 0;
}
