#include "../header/Andand.h"

int Andand::execute() {
    if(previous >= 0) {
        return current->execute();
    }
    return -1;
}