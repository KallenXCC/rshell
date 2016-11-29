#include "../header/Andand.h"

int Andand::execute() {
    //If previous execute() is 0, perform next command's execute()
    if(previous == 0) {
        return current->execute();
    }
    //Otherwise, do not perform next command
    return -1;
}