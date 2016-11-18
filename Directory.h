#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "Flag.h"

class Directory : public Flag {
    public:
        Directory(Base* current) : Flag(current) { }
        int execute();
        int check(string);
};

#endif 