#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "Base.h"

class Connector : public Base {
    protected:
        //Current command being run
        Base* current;
        //Based on the value of the last instance of execute(). 
        //Will play a role in the three types of connectors
        int previous;
    public:
       Connector(Base* current, int previous) {
           this->current = current;
           this->previous = previous;
       }
       //This will call Command's execute();
       int execute() {
           return 0; //temporary
       } 
};

#endif