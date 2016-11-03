#include "../header/Command.h"

#include <cstdlib>
#include <cstdio>

int Command::execute() {
    //pid_t parent = getpid();
    pid_t pid = fork();
    
    //Calls perror() here, then exits out
    if (pid == -1)
    {
        perror("fork fail");
        exit(-1);
    } 
    //Waits for the child to finish processing
    else if (pid > 0)
    {
        int process;
        waitpid(pid, &process, 0);
    }
    //Calls execvp() here
    else 
    {
        char** tokens;
        tokens = new char*[command.size() + 1];
        strcpy(*tokens, command.c_str());
        *tokens = strtok(*tokens, " ");
        
        execvp(tokens[0], tokens);
        
        //It will only reach this point if execvp() fails. When it does, -1 will
        //determine what to do next
    }
    return -1;
}