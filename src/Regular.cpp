#include "../header/Regular.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int Regular::execute() {
    return 0; //temporary
}

//Assuming "-f" is the input
int Regular::check(string flag) {
    struct stat sb;
    if (stat(flag.c_str(), &sb) == 0) {
        if (S_ISREG(sb.st_mode)) {
            cout << "(True)" << endl;
        }
        else {
            cout << "(False)" << endl;
        }
    }
    
    return 0; //temporary
}

// http://stackoverflow.com/questions/18460849/can-we-use-stat-with-relative-path-to-a-file-in-c