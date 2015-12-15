//
//  geneticminimizer.h
//  LearningCpp
//
//  Created by Justin Horowitz on 12/12/15.
//  Copyright (c) 2015 Justin Horowitz. All rights reserved.
//

#ifndef LearningCpp_geneticminimizer_h
#define LearningCpp_geneticminimizer_h

#include <random>

class GeneticMinimizer {
    public:
        //All a genetic algorithm knows is a list of params and something to judge their fitness, void pointers would be more general as well as explicitly adding a mutator
        GeneticMinimizer( double (*minimizeme)(double*, int), int n, int m);
        ~GeneticMinimizer();
        void refine();
        void barf();
    
    private:
        double (*objective)(double*, int);
        int N, M;
        std::random_device rd;
        std::mt19937 gen;
        std::uniform_real_distribution<double> dis;
        double **parents, **children;
        double *winner;
        bool winner_known;
    double * fitness;
};

#endif
