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
        
        Node(const T& val) : data(val), cnt(1), left(nullptr), right(nullptr) {}
    };
    
    Node* root;
    int size;
    
    Node* add(Node* node, const T& val) {
        if (node == nullptr) {
            size++;
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
    
    int getDepth(Node* node) const {
        if (node == nullptr) return 0;
        return 1 + std::max(getDepth(node->left), getDepth(node->right));
    }
    
    bool find(Node* node, const T& val) const {
        if (node == nullptr) return false;
        if (val == node->data) return true;
        if (val < node->data) return find(node->left, val);
        return find(node->right, val);
    }
    
    void clean(Node* node) {
        if (node == nullptr) return;
        clean(node->left);
        clean(node->right);
        delete node;
    }
    
    void collect(Node* node, std::vector<std::pair<T, int>>& out) const {
        if (node == nullptr) return;
        collect(node->left, out);
        out.push_back({node->data, node->cnt});
        collect(node->right, out);
    }
    
public:
    BST() : root(nullptr), size(0) {}
    
    ~BST() {
        clean(root);
    }
    
    void insert(const T& val) {
        root = add(root, val);
    }
    
    int depth() const {
        return getDepth(root);
    }
    
    bool search(const T& val) const {
        return find(root, val);
    }
    
    int getSize() const {
        return size;
    }
    
    bool empty() const {
        return root == nullptr;
    }
    
    std::vector<std::pair<T, int>> getNodes() const {
        std::vector<std::pair<T, int>> res;
        collect(root, res);
        return res;
    }
};

#endif  // INCLUDE_BST_H_
