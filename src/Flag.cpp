#include "../header/Flag.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

//Assuming "-e" flag (whether given or no flag is given)
/*int Flag::check(string flag) {
    struct stat sb;
    if (stat(flag.c_str(), &sb) == 0) {
        cout << "(True)" << endl;
    }
    else {
        cout << "(False)" << endl;
    }
    
    return 0; //temporary
}*/

int Flag::execute() {
    struct stat buf;
    if(command->size == 1) {
        if(stat(command->command[0], &buf)) {
            cout << "(False)" << endl;
            return 1;
        } else {
            cout << "(True)" << endl;
            return 0;
        }
    } else if(command->command[0][1] == 'e') {
        if(stat(command->command[1], &buf)) {
            cout << "(False)" << endl;
            return 1;
        } else {
            cout << "(True)" << endl;
            return 0;
        }
    } else if(command->command[0][1] == 'f') {
        if(stat(command->command[1], &buf)) {
            cout << "(False)" << endl;
            return 1;
        } else {
            if(S_ISREG(buf.st_mode)) {
                cout << "(True)" << endl;
                return 0;
            } else {
                cout << "(False)" << endl;
                return 1;
            }
        }
    } else if(command->command[0][1] == 'd') {
        if(stat(command->command[1], &buf)) {
            cout << "(False)" << endl;
            return 1;
        } else {
            if(S_ISDIR(buf.st_mode)) {
                cout << "(True)" << endl;
                return 0;
            } else {
                cout << "(False)" << endl;
                return 1;
            }
        }
    } else {
        perror("invalid command");
        exit(1);
    }
    return 1;
}