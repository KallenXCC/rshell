#include "../header/Semicolon.h"

int Semicolon::execute() {
    //Perform command no matter what
    return current->execute();
}