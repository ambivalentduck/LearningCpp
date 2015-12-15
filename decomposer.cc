//
//  decomposer.cc
//  LearningCpp
//
//  Created by Justin Horowitz on 12/14/15.
//  Copyright (c) 2015 Justin Horowitz. All rights reserved.
//
#include "decomposer.h"

Decomposer::Decomposer(std::list<int> o) : options(o) {
    root.depth=0;
}

bool operator<(const node &nodeA, const node &nodeB) {
    //Return opposite order because we want to expand LOWEST f first
    return nodeA.f > nodeB.f;
}

std::list<int> Decomposer::decompose(int decompose_me) {
    std::priority_queue<node> pqueue;
    root.remainder=decompose_me;
    root.f=decompose_me;
    pqueue.push(root);
    node best;
    node child;
    
    while (true) {
        best=pqueue.top();
        pqueue.pop();
       
        if (best.remainder==0) {
            break;
        }
        
        //Expand the "best" node
        for (std::list<int>::iterator it=options.begin(); it!=options.end(); it++) {
            if (*it>best.remainder) //No negative remainders.
                continue;
            child.options_used=best.options_used;
            child.options_used.push_back(*it);
            child.remainder=best.remainder-*it;
            child.depth=best.depth+1;
            child.f=child.remainder+child.depth;
           
            pqueue.push(child);
        }
    }
    best.options_used.sort();
    return best.options_used;
}