// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

template<typename T>
class BST {
 private:
    struct Node {
        T data;
        int cnt;
        Node* left;
        Node* right;

        explicit Node(const T& val) : data(val), cnt(1), left(nullptr), right(nullptr) {}
    };

    Node* root;
    int sz;

    Node* add(Node* node, const T& val) {
        if (node == nullptr) {
            sz++;
            return new Node(val);
        }
        if (val < node->data) {
            node->left = add(node->left, val);
        } else if (val > node->data) {
            node->right = add(node->right, val);
        } else {
            node->cnt++;
        }
        return node;
    }

    int getDep(Node* node) const {
        if (node == nullptr) return -1;
        int ldep = getDep(node->left);
        int rdep = getDep(node->right);
        return (ldep > rdep ? ldep : rdep) + 1;
    }

    bool sea(Node* node, const T& val) const {
        if (node == nullptr) return false;
        if (val == node->data) return true;
        if (val < node->data) return sea(node->left, val);
        return sea(node->right, val);
    }

    void clr(Node* node) {
        if (node == nullptr) return;
        clr(node->left);
        clr(node->right);
        delete node;
    }

    void getAll(Node* node, std::vector<std::pair<T, int>>& vec) const {
        if (node == nullptr) return;
        getAll(node->left, vec);
        vec.push_back({node->data, node->cnt});
        getAll(node->right, vec);
    }

 public:
    BST() : root(nullptr), sz(0) {}

    ~BST() {
        clr(root);
    }

    void insert(const T& val) {
        root = add(root, val);
    }

    int depth() const {
        return getDep(root);
    }

    bool search(const T& val) const {
        return sea(root, val);
    }

    int size() const {
        return sz;
    }

    bool empty() const {
        return root == nullptr;
    }

    std::vector<std::pair<T, int>> getNodes() const {
        std::vector<std::pair<T, int>> res;
        getAll(root, res);
        return res;
    }
};

#endif  // INCLUDE_BST_H_
