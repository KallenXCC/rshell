#ifndef COMMAND_H
#define COMMAND_H

#include "Base.h"

#include <sys/wait.h>

using namespace std;

class Command : public Base {
    public:
       string command;
       Command(string command) {this->command = command;}
       int execute();   //Will call execvp()
       void parse(string&); //necessary?
};

#endif