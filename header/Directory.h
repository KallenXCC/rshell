//FILE NOT CHANGED SINCE ASSIGNMENT 3
//FILE NOT CHANGED SINCE ASSIGNMENT 3
//FILE NOT CHANGED SINCE ASSIGNMENT 3
//FILE NOT CHANGED SINCE ASSIGNMENT 3
//FILE NOT CHANGED SINCE ASSIGNMENT 3

#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "Flag.h"

class Directory : public Flag {
    public:
        Directory(string current) : Flag(current) { }
        int execute();
        int check(string);
};

#endif 
