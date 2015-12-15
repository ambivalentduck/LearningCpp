//
//  quicksorter.h
//  LearningCpp
//
//  Created by Justin Horowitz on 12/14/15.
//  Copyright (c) 2015 Justin Horowitz. All rights reserved.
//

#ifndef __LearningCpp__quicksorter__
#define __LearningCpp__quicksorter__

#include <stdio.h>
#include <list>

typedef std::list<double>::iterator ListIt;

class SortTester {

public:
    SortTester(int n);
    SortTester(std::list<double> &l);
    void InsertionSort0(ListIt first, ListIt last);
    void InsertionSort1(ListIt first, ListIt last);
    void InsertionSort2(ListIt first, ListIt last);
    void InsertionSort3(ListIt first, ListIt last);
    void InsertionAdaptive(ListIt first, ListIt last);
    void QuickSort(ListIt first, ListIt last);
    ListIt first() {return list.begin();}
    ListIt last() {return list.end();}
    void barf();
    
private:
    std::list<double> list;    
    bool compswap(double &A, double &B);
};

#endif /* defined(__LearningCpp__quicksorter__) */
