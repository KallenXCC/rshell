//FILE NOT CHANGED SINCE ASSIGNMENT 3
//FILE NOT CHANGED SINCE ASSIGNMENT 3
//FILE NOT CHANGED SINCE ASSIGNMENT 3
//FILE NOT CHANGED SINCE ASSIGNMENT 3
//FILE NOT CHANGED SINCE ASSIGNMENT 3

#include "../header/Oror.h"

int Oror::execute() {
    //If previous execute() is not 0, perform next command's execute()
    if(previous != 0) {
        return current->execute();
    }
    //Otherwise, skip the next command
    return -1;
}