//
//  BinarySearchTree.hpp
//  binary search tree
//
//  Created by 胡欣妍 on 2018/6/10.
//  Copyright © 2018年 胡欣妍. All rights reserved.
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include <stack>
#include <queue>

template<typename T>
class Stack : public std::stack<T> {
public:
    T pop() {
        T tmp = std::stack<T>::top();
        std::stack<T>::pop();
        return tmp;
    }
};

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

#endif /* BinarySearchTree_hpp */
