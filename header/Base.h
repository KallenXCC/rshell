#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <cstring>
#include <unistd.h>

class Base {
    public:
        Base() {};          //Note: backup is char argv[]
        virtual int execute() = 0;  //To be determined in subclasses
};

#endif

/* Useful Link(s)

http://stackoverflow.com/questions/19099663/how-to-correctly-use-fork-exec-wait

http://web.mst.edu/~ercal/284/UNIX-fork-exec/Fork-Exec-2.cpp

http://www.csl.mtu.edu/cs4411.ck/www/NOTES/process/fork/exec.html

*/