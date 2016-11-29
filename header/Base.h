//FILE NOT CHANGED SINCE ASSIGNMENT 3
//FILE NOT CHANGED SINCE ASSIGNMENT 3
//FILE NOT CHANGED SINCE ASSIGNMENT 3
//FILE NOT CHANGED SINCE ASSIGNMENT 3
//FILE NOT CHANGED SINCE ASSIGNMENT 3

#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <cstring>
#include <unistd.h>

class Base {
    public:
        Base() {};
        virtual int execute() = 0;  //To be determined in subclasses (Pure virtual function)
};

#endif

/* Useful Link(s)

http://stackoverflow.com/questions/19099663/how-to-correctly-use-fork-exec-wait

http://web.mst.edu/~ercal/284/UNIX-fork-exec/Fork-Exec-2.cpp

http://www.csl.mtu.edu/cs4411.ck/www/NOTES/process/fork/exec.html

*/