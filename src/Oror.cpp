#include "../header/Oror.h"

int Oror::execute() {
    //If previous execute() is -1, perform next command's execute()
    if(previous != 0) {
        return current->execute();
    }
    //Otherwise, skip the next command
    return 1;
}