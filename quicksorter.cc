//
//  quicksorter.cc
//  LearningCpp
//
//  Created by Justin Horowitz on 12/14/15.
//  Copyright (c) 2015 Justin Horowitz. All rights reserved.
//

#include "quicksorter.h"
#include <random>
#include <iostream>

SortTester::SortTester(std::list<double> &l) : list(l) {
    barf();
}

SortTester::SortTester(int n) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(-10, 10);

    for (int i = 0; i < n; ++i)
        list.push_back(dis(gen));
    barf();
}

void SortTester::barf() {
    std::cout<<"List contents: ";
    for (ListIt it = list.begin(); it!=list.end(); it++)
        std::cout<<*it<<" ";
    std::cout<<std::endl;
}

bool SortTester::compswap(double &A, double &B)
{
    bool swapped;
    if ((swapped = B < A))
    {
        double C=A;
        A=B;
        B=C;
    }
    return swapped;
}

void SortTester::InsertionSort0(ListIt first, ListIt last) {
    ListIt left=first++;
    ListIt temp;
    for (ListIt i = left; i!=last; i++)
        for (ListIt j = i; j!=left; j--) {
            temp=j;
            temp--;
            compswap(*temp,*j);
            //Could just break this loop on first false compswap?
        }
}

void SortTester::InsertionSort1(ListIt first, ListIt last) {
    ListIt left=first++;
    double val;
    ListIt j, temp;
    bool swapped;
    for (ListIt i = left; i!=last; i++) {
        j=i;
        do {
            temp=j;
            temp--;
            swapped=compswap(*temp, *j);
            //Performs too many swaps, but whatevs
        } while ( j-- != left && !swapped );
        //Could just break this loop on first false compswap?
    }
}

