//
//  BinarySearchTree.hpp
//  binary search tree
//
//  Created by 胡欣妍 on 2018/6/10.
//  Copyright © 2018年 胡欣妍. All rights reserved.
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include <iostream>
#include <stack>
#include <queue>

#pragma mark - Stack
template<typename T>
class Stack : public std::stack<T> {
public:
    T pop() {
        T tmp = std::stack<T>::top();
        std::stack<T>::pop();
        return tmp;
    }
};

#pragma mark - Queue
template <typename T>
class Queue : public std::queue<T> {
public:
    T dequeue() {
        T tmp = std::queue<T>::front();
        std::queue<T>::pop();
        return tmp;
    }
    
    void enqueue(const T& el) {
        std::queue<T>::push(el);
    }
};

#pragma mark - BSTNode
template <typename T>
class BSTNode {
public:
    T el;
    BSTNode<T> *left, *right;
    
    BSTNode(): left(0), right(0) {}
    BSTNode(const T&e, BSTNode<T> *l = 0, BSTNode<T> *r = 0) : el(e), left(l), right(r) {}
};
#endif /* BinarySearchTree_hpp */
