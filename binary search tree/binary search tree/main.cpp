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
    void iterativePreorder();
    void iterativeInorder();
    void iterativePostorder();
    void insert(const T&);
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

#pragma mark  广度遍历
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

#pragma mark  递归深度遍历
template <typename T>
void BST<T>::inorder(BSTNode<T> *p) {
    if (p) {
        inorder(p->left);
        visit(p);
        inorder(p->right);
    }
}

template <typename T>
void BST<T>::preorder(BSTNode<T> *p) {
    if (p) {
        visit(p);
        preorder(p->left);
        preorder(p->right);
    }
}

template <typename T>
void BST<T>::postorder(BSTNode<T> *p) {
    if (p) {
        postorder(p->left);
        preorder(p->right);
        visit(p);
    }
}

#pragma mark  插入节点
template <typename T>
void BST<T>::insert(const T& el) {
    BSTNode<T> *p = root, *prev = 0;
    while (p) {
        prev = p;
        if (el < p->el)
            p = p->left;
        else
            p = p->right;
    }
    if (!root)
        root = new BSTNode<T>(el);
    else if (el < prev->el)
        prev->left = new BSTNode<T>(el);
    else
        prev->right = new BSTNode<T>(el);
}

int main(int argc, const char * argv[]) {
    BST<int> tree;
    return 0;
}
