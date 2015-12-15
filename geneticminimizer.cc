#include "geneticminimizer.h"
//  geneticminimizer.cc
//  LearningCpp
//
//  Created by Justin Horowitz on 12/12/15.
//  Copyright (c) 2015 Justin Horowitz. All rights reserved.
//
#include <iostream>

GeneticMinimizer::GeneticMinimizer(double (*minimizeme)(double*, int), int n, int m) :
    objective(minimizeme),
    N(n), M(m), winner_known(false),
    rd(), gen(rd()), dis(1,9)
{
    parents=new double*[M];
    children=new double*[M];
    for (int i = 0; i < M; ++i) {
        parents[i] = new double[N];
        children[i] = new double[N];
        for (int j=0; j < N; ++j)
            parents[i][j]=dis(gen);
    }
    fitness=new double[M];
}

GeneticMinimizer::~GeneticMinimizer() {
    for (int i = 0; i < M; i++) {
        delete[] parents[i];
        delete[] children[i];
    }
    delete[] parents;
    delete[] children;
    delete[] fitness;
}

void GeneticMinimizer::refine() {
    if (winner_known)
        return; // Perfect -> no need for further refinement
    // For each row, fire a pointer over to the objective function
    // Convert from cost to fitness by fitness=1/cost. If cost = 0, you win. Done.
    double lowest_cost=HUGE_VAL;
    int lowest_cost_row=0;
    for (int i=0; i<M; i++) {
        fitness[i]=objective(parents[i],N);
        if (fitness[i]<lowest_cost) {
            lowest_cost=fitness[i];
            lowest_cost_row=i;
        }
        if (fitness[i]==0) {
            winner_known=true;
            winner=parents[i];
            return;
        }
        //Cumulative sum just makes it easier to select later
        fitness[i]=1l/fitness[i]+(i>0?fitness[i-1]:0);
    }
    //Always make the best member of the population a child verbatim to guarantee no backslide
    for (int i=0; i<N; ++i)
        children[0][i]=parents[lowest_cost_row][i];
    
    std::uniform_real_distribution<double> picker(0,fitness[M-1]);
    std::uniform_real_distribution<double> mutation(-.5,.5);
    double pickedfit;
    int picked;
    // for each M, for each N, select children from parents proportional to fitness
    for (int i=1; i<M; ++i)
        for (int j=0; j<N; ++j) {
            pickedfit=picker(gen);
            picked=0;
            //Since we do M*N searches, skip list should replace this while loop
            while ( fitness[picked] <= pickedfit )
                picked++;
            children[i][j] = parents[picked][j] + mutation(gen);
            if (children[i][j] < 1)
                children[i][j] = 1;
            else if (children[i][j] > 9)
                children[i][j] = 9;
        }
    // This generation's children are next generation's parents. Easier to switch a pointer than to copy.
    double **switcheroo = children;
    children = parents;
    parents = switcheroo;
    std::cout<<"Lowest cost was: "<<lowest_cost<<std::endl;
}

void GeneticMinimizer::barf() {
    double fitness;
    std::cout << "The winner is: ";
    if (!winner_known) {
        //Need to locate a winner
        double lowest_cost = HUGE_VAL;
        for (int i = 0; i < M; ++i) {
            fitness=objective( parents[i], N);
            if ( fitness < lowest_cost ) {
                winner=parents[i];
                lowest_cost=fitness;
            }
        }
    }
    fitness = objective( winner, N);
    for (int i = 0; i < N; ++i)
        std::cout << winner[i] << " ";
    std::cout << "with final cost " << fitness << std::endl;
}
