#include "../header/Command.h"

#include <cstdlib>
#include <cstdio>

int Command::execute() {
    //pid_t parent = getpid();
    pid_t pid = fork();
    cout << "Executing..." << endl;
    printf ("%s \n", command[0]);
    //Calls perror() here, then exits out
    if (pid == -1)
    {
        perror("fork failed");
        exit(-1);
    } 
    //Waits for the child to finish processing
    else if (pid > 0)
    {
        cout << "parent: " << pid << endl;
        int process;
        waitpid(pid, &process, 0);
    }
    //Calls execvp() here
    else
    {
        /*Parsing using strtok()*/
        cout << "child: " << pid << endl;
        //char* const a[];
        //printf ("%s \n", command[0]);
        if (execvp(command[0], command) == -1) {
            perror("exec");    
            return -1;
        }
        //if (execvp(command.c, ))
        
        //It will only reach this point if execvp() fails. When it does, -1 will
        //determine what to do next
    }
    return 0;
}