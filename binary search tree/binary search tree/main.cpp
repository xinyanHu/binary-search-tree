//
//  main.cpp
//  binary search tree
//
//  Created by 胡欣妍 on 2018/6/10.
//  Copyright © 2018年 胡欣妍. All rights reserved.
//

#include <iostream>
#include "BinarySearchTree.hpp"
using namespace std;

template <typename T>
class BST {
protected:
    BSTNode<T> *root;
    
    void clear(BSTNode<T> *);
    T* search(BSTNode<T> *, const T&) const;
    void preorder(BSTNode<T> *);
    void inorder(BSTNode<T> *);
    void postorder(BSTNode<T> *);
    
    virtual void visit(BSTNode<T> *p) {
        std::cout << p->el << " ";
    }
public:
    BST() : root(0) {}
    ~BST() { clear(); }
    
    void clear() {
        clear(root);
        root = 0;
    }
    bool isEmpty() const { return !root;}
    void preorder() { preorder(root); }
    void inorder() { inorder(root); }
    void postorder() { postorder(root); }
    T* search(const T& el) const { return search(root, el); }
    void breadthFirst();
};

template <typename T>
T* BST<T>::search(BSTNode<T> *p, const T& el) const {
    while (p) {
        if (el == p->el)
            return p;
        else if (el < p->el)
            p = p->left;
        else
            p = p->right;
    }
    return 0;
}

template <typename T>
void BST<T>::breadthFirst() {
    Queue<BSTNode<T> *> queue;
    BSTNode<T> *p = root;
    
    if (p) {
        queue.enqueue(p);
        while (!queue.empty()) {
            p = queue.dequeue();
            visit(p);
            if (p->left) {
                queue.enqueue(p->left);
            }
            if (p->right) {
                queue.enqueue(p->right);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
