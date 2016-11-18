#include "../header/Flag.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int Flag::execute() {
    return 0; //temporary
}

//Assuming "-e" flag (whether given or no flag is given)
int Flag::check(string flag) {
    struct stat sb;
    if (stat(flag.c_str(), &sb) == 0) {
        cout << "(True)" << endl;
    }
    else {
        cout << "(False)" << endl;
    }
    
    return 0; //temporary
}