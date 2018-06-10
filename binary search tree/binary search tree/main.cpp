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

int main(int argc, const char * argv[]) {
    Stack<int> s;
    s.push(1);
    cout << s.pop() << "\t" << s.empty() << endl;
    
    Queue<int> q;
    q.enqueue(11);
    cout << q.dequeue() << "\t" << q.empty() << endl;
    return 0;
}
