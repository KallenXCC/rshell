//FILE NOT CHANGED SINCE ASSIGNMENT 3
//FILE NOT CHANGED SINCE ASSIGNMENT 3
//FILE NOT CHANGED SINCE ASSIGNMENT 3
//FILE NOT CHANGED SINCE ASSIGNMENT 3
//FILE NOT CHANGED SINCE ASSIGNMENT 3

#ifndef COMMAND_H
#define COMMAND_H

#include "Base.h"

#include <sys/wait.h>
#include <cstdio>

using namespace std;

class Command : public Base {
    public:
        char** command;
        unsigned size;
        
        /*const char* file;
        char* argv[10];*/
        
        Command(string command) {
            // if(command.find("#", 0) != string::npos) {
            //     command = command.substr(0, command.find("#", 0));
            // }
            this->size = 0;
            
            this->command = new char*[command.size() + 1];
            char* temp  = new char[command.size() + 1];             
            strcpy(temp, command.c_str());
            this->command[0] = strtok(temp, " \n");
            while(this->command[size] != NULL) {
                ++size;
                this->command[size] = strtok (NULL, " \n");
            }
            this->command[size] = NULL;
            
            /*int spaceIndex = command.find(' ', 0);
            this->file = command.substr(0, spaceIndex).c_str();
            command = command.substr(spaceIndex, command.size() - spaceIndex);
            this->argv[0] = new char[10];
            strcpy(this->argv[0], this->file);
            
            int count = 1;
            const char* temp;
            while(command.size() > 0) {
                spaceIndex = command.find(' ', 0);
                temp = command.substr(0, spaceIndex).c_str();
                command = command.substr(spaceIndex, command.size() - spaceIndex);
                this->argv[count] = new char[10];
                strcpy(this->argv[count], temp);
                ++count;
            }
            this->argv[count] = NULL;*/
        }
        int execute();   //This will call execvp()
};

#endif