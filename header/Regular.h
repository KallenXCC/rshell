//FILE NOT CHANGED SINCE ASSIGNMENT 3
//FILE NOT CHANGED SINCE ASSIGNMENT 3
//FILE NOT CHANGED SINCE ASSIGNMENT 3
//FILE NOT CHANGED SINCE ASSIGNMENT 3
//FILE NOT CHANGED SINCE ASSIGNMENT 3

#ifndef REGULAR_H
#define REGULAR_H

#include "Flag.h"

class Regular : public Flag {
    public:
        Regular(string current) : Flag(current) { }
        int execute();
        int check(string);
};

#endif 