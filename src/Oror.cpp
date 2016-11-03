#include "../header/Oror.h"

int Oror::execute() {
    if(previous == -1) {
        return current->execute();
    }
    return -1;
}