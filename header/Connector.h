#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "Base.h"

class Connector : public Base {
    public:
       Base* current;
       int previous; //necessary?
       Connector(Base* current, int previous) {
           this->current = current;
           this->previous = previous;
       }
       int execute();   //Will call Command's execute();
};

#endif

/* 
   Note on execute(): Have Command's execute() return either -1, 0, or 1.
   If execvp() fails, it will return a negative number. This will determine
   the next command.
   
   Note on fork(): if pid returns < 0, then exit()
   
   Quick note on source files: When adding header files from another folder, use
   the format: "#include "../header/NAME_OF_HEADER_FILE"
*/