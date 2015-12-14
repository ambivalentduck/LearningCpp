//
//  playwithheaps.h
//  LearningCpp
//
//  Created by Justin Horowitz on 12/13/15.
//  Copyright (c) 2015 Justin Horowitz. All rights reserved.
//

#ifndef __LearningCpp__playwithheaps__
#define __LearningCpp__playwithheaps__

#include <vector>

class HeapMe {
   
    public:
        HeapMe(std::vector<double> &v);
        double popMax();
        void barf();
        void push(double d);
        bool isEmpty();
    
    private:
        std::vector<double> vec;
};

#endif /* defined(__LearningCpp__playwithheaps__) */
