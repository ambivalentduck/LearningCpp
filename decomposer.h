//
//  decomposer.h
//  LearningCpp
//
//  Created by Justin Horowitz on 12/14/15.
//  Copyright (c) 2015 Justin Horowitz. All rights reserved.
//

#ifndef __LearningCpp__decomposer__
#define __LearningCpp__decomposer__

#include <iostream>
#include <list>
#include <queue>

struct node {
    int remainder;
    std::list<int> options_used;
    int f;
    int depth;
};

class Decomposer {
public:
    Decomposer(std::list<int> o);
    std::list<int> decompose(int decompose_me);
    
private:
    node root;
    std::list<int> options;
};

bool operator<(const node &nodeA, const node &nodeB);

#endif /* defined(__LearningCpp__decomposer__) */
