//
//  main.cpp
//  LearningCpp
//
//  Created by Justin Horowitz on 12/12/15.
//  Copyright (c) 2015 Justin Horowitz. All rights reserved.
//

#include <iostream>
#include "geneticminimizer.h"
#include <cmath>
#include "playwithheaps.h"

double objective(double *x,int n) {
    double x12=std::pow(x[0],2);
    double x22=std::pow(x[1],2);
    return std::abs(6l*x12*x22+18l*x12*x[3]-70l*x12-21l*x22*x[2]-63l*x[2]*x[3]+245l*x[2]+24l*x22+72l*x[3]-280);
}


int main(int argc, const char * argv[]) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(-10, 10);
    
    // insert code here...
    std::cout << "Hello, World!\n";
    
    GeneticMinimizer gm(&objective, 4, 50);
    for (int i = 0; i < 10; ++i)
        gm.refine();
    gm.barf();
    
    std::vector<double> v {1, 3, 5, 6, 8, 2, 1};
    HeapMe hm(v);
    hm.barf();
    hm.push(10);
    hm.barf();
    std::cout<<hm.popMax()<<std::endl;
    while (!hm.isEmpty()) {
        std::cout<<hm.popMax()<<std::endl;
        if (dis(gen)>=0)
            hm.push(dis(gen));
    }
    
    return 0;
}
