#ifndef FLAG_H
#define FLAG_H

#include "Base.h"
#include <string>
using namespace std;

class Flag : public Base {
    protected:
        //Current command being run
        Base* current;
    public:
        Flag(Base* current) {
           this->current = current;
        }
        //This will call Command's execute();
        int execute() = 0;
        
        //Default check (-e). -f and -d will be resolved in subclasses of Flag
        virtual int check(string); //Assuming that check() is given the parsed string already
};

#endif