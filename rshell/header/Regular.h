#ifndef REGULAR_H
#define REGULAR_H

#include "Flag.h"

class Regular : public Flag {
    public:
        Regular(Base* current) : Flag(current) { }
        int execute();
        int check(string);
};

#endif 