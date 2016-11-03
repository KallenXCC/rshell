#include "../header/Command.h"
/*#include "../header/Connector.h"
#include "../header/Command.h"
#include "../header/Andand.h"
#include "../header/Oror.h"
#include "../header/Semicolon.h"*/

#include <cstdlib>
#include <cstdio>

void Command::parse(string& exec) {
    //FIXME
}

int Command::execute() {
    pid_t parent = getpid();
    pid_t pid = fork();
    string exec;    //After parsing string, put executable here
    
    if (pid == -1)
    {
        perror("fork fail");
        exit(-1);
        //call perror, then built-in exit()
    } 
    else if (pid > 0)
    {
        int process;
        waitpid(pid, &process, 0);
    }
    else 
    {
        char** tokens;
        tokens = new char*[command.size() + 1];
        strcpy(*tokens, command.c_str());
        *tokens = strtok(*tokens, " ");
        
        execvp(tokens[0], tokens);
        
        //execvp(exec, cmd) /* Arguments will be the executable and the (rest + executable) */
        //If it reaches here, return -1;
        return -1;
    }
}