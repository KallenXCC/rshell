//FILE NOT CHANGED SINCE ASSIGNMENT 3
//FILE NOT CHANGED SINCE ASSIGNMENT 3
//FILE NOT CHANGED SINCE ASSIGNMENT 3
//FILE NOT CHANGED SINCE ASSIGNMENT 3
//FILE NOT CHANGED SINCE ASSIGNMENT 3

#include "../header/Command.h"

#include <cstdlib>
#include <cstdio>

int Command::execute() {
    //pid_t parent = getpid();
    pid_t pid = fork();
    int process;
    cout << "Executing: ";
    printf("%s \n", command[0]);
    cout << "Arguments: ";
    unsigned i = 0;
    while(command[i] != NULL) {
        printf("%s, ", command[i]);
        ++i;
    }
    cout << endl;
    
    //Calls perror() here, then exits out
    if (pid == -1)
    {
        perror("fork failed");
        exit(1);
    } 
    //Waits for the child to finish processing
    else if (pid > 0)
    {
        cout << "parent: " << pid << endl;
        while(waitpid(pid, &process, 0) != pid) {};
    }
    //Calls execvp() here
    else
    {
        /*Parsing using strtok()*/
        cout << "child: " << pid << endl << endl;
        //char* const a[];
        //printf ("%s \n", command[0]);
        if (execvp(command[0], command) == -1) {
            perror("exec");  
            exit(1);
        }
        //if (execvp(command.c, ))
        
        //It will only reach this point if execvp() fails. When it does, -1 will
        //determine what to do next
    }
    if(process != 0) {
        return -1;
    }
    return 0;
}