//FILE NOT CHANGED SINCE ASSIGNMENT 3
//FILE NOT CHANGED SINCE ASSIGNMENT 3
//FILE NOT CHANGED SINCE ASSIGNMENT 3
//FILE NOT CHANGED SINCE ASSIGNMENT 3
//FILE NOT CHANGED SINCE ASSIGNMENT 3

#include "../header/Directory.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <linux/stat.h>

int Directory::execute() {
    return 0; //temporary
}

//Assuming "-d" is the input
int Directory::check(string flag) {
    struct stat sb;
    if (stat(flag.c_str(), &sb) == 0) {
        if (S_ISDIR(sb.st_mode)) {
            cout << "(True)" << endl;
        }
        else {
            cout << "(False)" << endl;
        }
    }
    
    return 0; //temporary
}