#ifndef COMMAND_H
#define COMMAND_H

#include "Base.h"

#include <sys/wait.h>

using namespace std;

class Command : public Base {
    public:
       string command;
       Command(string command) {
            if(command.find("#", 0) == string::npos) {
                this->command = command;
            } else {
                this->command = command.substr(0, command.find("#", 0));
            }
        }
        int execute();   //This will call execvp()
};

#endif