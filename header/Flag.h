//FILE NOT CHANGED SINCE ASSIGNMENT 3
//FILE NOT CHANGED SINCE ASSIGNMENT 3
//FILE NOT CHANGED SINCE ASSIGNMENT 3
//FILE NOT CHANGED SINCE ASSIGNMENT 3
//FILE NOT CHANGED SINCE ASSIGNMENT 3

#ifndef FLAG_H
#define FLAG_H

#include "Base.h"
#include "Command.h"
#include <cstdlib>
#include <string>
using namespace std;

class Flag : public Base {
    protected:
        //Current command being run
        Command* command;
    public:
        Flag(string command) {
            this->command = new Command(command);
        }
        //This will call Command's execute();
        int execute();
        
        //Default check (-e). -f and -d will be resolved in subclasses of Flag
        //virtual int check(string) = 0; //Assuming that check() is given the parsed string already
};

#endif