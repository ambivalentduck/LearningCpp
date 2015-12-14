//
//  playwithheaps.cc
//  LearningCpp
//
//  Created by Justin Horowitz on 12/13/15.
//  Copyright (c) 2015 Justin Horowitz. All rights reserved.
//

#include "playwithheaps.h"
#include <algorithm>
#include <iostream>

HeapMe::HeapMe(std::vector<double> &v) : vec(v) {
    std::make_heap(vec.begin(), vec.end());
}

void HeapMe::barf() {
    std::cout << "Heap looks like: ";
    for (std::vector<double>::iterator it = vec.begin(); it<vec.end(); ++it)
        std::cout << *it << " ";
    std::cout<<std::endl;
}

double HeapMe::popMax() {
    std::pop_heap(vec.begin(), vec.end());
    double returnme=vec.back();
    vec.pop_back();
    return returnme;
}

void HeapMe::push(double d) {
    vec.push_back(d);
    std::push_heap(vec.begin(), vec.end());
}

bool HeapMe::isEmpty() {
    return vec.empty();
}