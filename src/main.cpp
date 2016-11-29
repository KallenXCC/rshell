#include <iostream>
#include <vector>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <stack>
using namespace std;

#include "../header/Command.h"
#include "../header/Connector.h"
#include "../header/Command.h"
#include "../header/Andand.h"
#include "../header/Oror.h"
#include "../header/Semicolon.h"
#include "../header/Base.h"
#include "../header/Flag.h"

int main() {
    vector<Base*> commands;         //Vector to hold the commands
    vector<char> connectorTypes;    //Vector to hold the connectors
    stack<const char*> history;     //Stack to hold the history of cd inputs
    string input;                   //String to store user input
    int prevIndex = 0;              /* To keep track of where we are in
                                      commands and connectorTypes */
    
    //Used to check the input (mainly for the cd command)
    bool sharp = false;    
    bool goHome = false;
    bool dash = false;
    bool slash = false;
    
    do {
    
    commands.resize(0);
    connectorTypes.resize(0);
    
    //Used to output current working directory
    cout << getenv("PWD") << " $ ";
    getline(cin, input);
    prevIndex = 0;

    sharp = false;
    goHome = false;
    dash = false;
    slash = false;
    
    cout << getenv("PWD") << endl;

    cout << "Parsing commands: " << endl;
    
    //Loop to check the input for connectors and other indicators
    for (unsigned i = 0; i < input.size(); ++i) {
        
        //Is it a commented-out command?
        if (input.at(i) == '#') {
            Command* comm = new Command(input.substr(prevIndex, i - prevIndex));
            commands.push_back(comm);
            sharp = true;
            prevIndex = i + 1;
        }  
        
        //Is it a regular command?
        if (input.at(i) == ';') {
            cout << input.substr(prevIndex, i - prevIndex) << endl;
            Command* comm = new Command(input.substr(prevIndex, i - prevIndex));
            commands.push_back(comm);
            connectorTypes.push_back(';');
            prevIndex = i + 1;
        }
        
        //Is it a command with an AND connector behind it?
        if (input.at(i) == '&') {
            if (i != input.size() - 1) {
                if (input.at(i + 1) == '&') {
                    cout << input.substr(prevIndex, i - prevIndex) << endl;
                    Command* comm = new Command(input.substr(prevIndex, i - prevIndex));
                    commands.push_back(comm);
                    connectorTypes.push_back('&');
                    prevIndex = i + 2;
                }
            }
        }
        
        //Is it a command with an OR connector behind it?
        if (input.at(i) == '|') {
            if (i != input.size() - 1) {
                if (input.at(i + 1) == '|') {
                    cout << input.substr(prevIndex, i - prevIndex) << endl;
                    Command* comm = new Command(input.substr(prevIndex, i - prevIndex));
                    commands.push_back(comm);
                    connectorTypes.push_back('|');
                    prevIndex = i + 2;
                }
            }
        }
        
        //Is it a command with a test? [isDir? isReg?]
        if (input.at(i) == ']') {
            cout << input.substr(input.find('[', prevIndex) + 1, i - input.find('[', prevIndex) - 1) << endl;
            Flag* fl = new Flag(input.substr(input.find('[', prevIndex) + 1, i - input.find('[', prevIndex) - 1));
            commands.push_back(fl);
            connectorTypes.push_back(']');
            prevIndex = i + 1;
        }
        
        //Same as above [the alternative way]
        if (input.at(i) == 't') {
            if((i + 3) < input.size()) {
                if((input.at(i + 1) == 'e') && (input.at(i + 2) == 's') && (input.at(i + 3) == 't')){
                    cout << "test";
                    prevIndex = i + 4;
                    int lastIndex;
                    
                    while(i < input.size()) {
                        if (input.at(i) == '#') {
                            lastIndex = i;
                            cout << input.substr(prevIndex, lastIndex - prevIndex) << endl;
                            Flag* fl = new Flag(input.substr(prevIndex, lastIndex - prevIndex));
                            commands.push_back(fl);
                            sharp = true;
                            prevIndex = i + 1;
                            break;
                        }  
                        if (input.at(i) == ';') {
                            lastIndex = i;
                            cout << input.substr(prevIndex, lastIndex - prevIndex) << endl;
                            Flag* fl = new Flag(input.substr(prevIndex, lastIndex - prevIndex));
                            commands.push_back(fl);
                            connectorTypes.push_back(';');
                            prevIndex = i + 1;
                            break;
                        }
                        if (input.at(i) == '&') {
                            if (i != input.size() - 1) {
                                if (input.at(i + 1) == '&') {
                                    lastIndex = i - 1;
                                    cout << input.substr(prevIndex, lastIndex - prevIndex) << endl;
                                    Flag* fl = new Flag(input.substr(prevIndex, lastIndex - prevIndex));
                                    commands.push_back(fl);
                                    connectorTypes.push_back('&');
                                    prevIndex = i + 2;
                                }
                            }
                            break;
                        }
                        if (input.at(i) == '|') {
                            if (i != input.size() - 1) {
                                if (input.at(i + 1) == '|') {
                                    lastIndex = i - 1;
                                    cout << input.substr(prevIndex, lastIndex - prevIndex) << endl;
                                    Flag* fl = new Flag(input.substr(prevIndex, lastIndex - prevIndex));
                                    commands.push_back(fl);
                                    connectorTypes.push_back('|');
                                    prevIndex = i + 2;
                                }
                            }
                            break;
                        }
                        ++i;
                    }
                    if(i == input.size()) {
                        cout << input.substr(prevIndex, input.size() - prevIndex) << endl;
                        Flag* fl = new Flag(input.substr(prevIndex, input.size() - prevIndex));
                        commands.push_back(fl);
                    }
                    
                }
            }
        }

    }
    
    //==========================================================================
    //BEGIN CORE OF ASSIGNMENT 4
    //==========================================================================
    
    //Is cd the only command inputted
    if (input.at(0) == 'c' && input.at(1) == 'd') {
        for (unsigned d = 3; d < input.size(); ++d) {
            //Do they want to go back to the previous directory?
            if (input.at(d) == '-') {
                goHome = false;
                dash = true;
            }
            //Did they want to go to a new directory/path?
            else {
                goHome = false;
                slash = true;
            }
        }
        if(input.size() < 3) {
            goHome = true;
        }
        //User only put "cd", meaning to go back home
        if (goHome) {
            char* oldEnv = getenv("PWD");
            history.push(oldEnv);
            if (oldEnv == NULL) {
                perror("getenv");
            }
            int newEnv = setenv("OLDPWD", oldEnv, 1); //set oldpwd to current environment
            if (newEnv == -1) {
                perror("setenv");
            }
            int dir = chdir(getenv("HOME"));
            if (dir == -1) {
                perror("chdir");
            }
            else {
                //Gets the home environment
                char* env = getenv("HOME");
                if (env == NULL) {
                    perror("getenv");
                }
                //Sets the environment to HOME
                int set = setenv("PWD", env, 1); //set pwd to home environment
                if (set == -1) {
                    perror("setenv");
                }
            }
            //cout << "AFTER RUNNING: " << getenv("PWD") << endl;
        }
        //User put "cd -", meaning to go back to the previous environment
        else if (dash) {
            char* oldEnv = getenv("PWD");
            if (oldEnv == NULL) {
                perror("getenv");
            }
            int setOldEnv = setenv("OLDPWD", oldEnv, 1); //set oldpwd to current environment
            if (setOldEnv == -1) {
                perror("setenv");
            }
            //Is it empty? If not, then continue
            if (history.size() > 0) {
                //cout << "Previous environment: " << history.top() << endl;
                int dir = chdir(history.top());
                if (dir == -1) {
                    perror("chdir");
                }
                else {
                    //Sets the environment to previous environment
                    if ( (setenv("PWD", history.top(), 1)) == -1) {
                        perror("setenv");
                    }
                }
                history.pop();
            }
            history.push(oldEnv);
        }
        //User put cd <PATH>, meaning go to the path specified by the input
        else if (slash) { //SUSPECT
            char* oldEnv = getenv("PWD");
            if (oldEnv == NULL) {
                perror("getenv");
            }
            int setOldEnv = setenv("OLDPWD", oldEnv, 1); //set oldpwd to current environment
            if (setOldEnv == -1) {
                perror("setenv");
            }
            
            //PWD = <PATH>; //Set PWD to PATH
            
            string path;
            // int temp = i + 2;
            path = input.substr(input.find(' ') + 1);
            // path = input.substr(' ', temp);
            int dir = chdir(path.c_str());
            if (dir == -1) {
                perror("chdir");
            }
            else { //SUSPECT
                //Gets the home environment
                char* env = getenv(path.c_str());
                if (env == NULL) {
                    perror("getenv");
                } else {
                    //Sets the environment to HOME
                    int set = setenv(path.c_str(), env, 0);
                    if (set == -1) {
                        perror("setenv");
                    }
                    //Is the current path not starting from the beginning? (In other words, did the user access previous directories before?)
                    // if (history.size() > 0) {
                    //     //Are we at the end of history? If so, then push_back
                    //     if (PWD == history.size() - 1) {
                    //         history.push_back(path.c_str());
                    //         OLDPWD = PWD;
                    //         ++PWD;
                    //     }
                    //     //If not, then that means we're somewhere in the middle
                    //     else {
                    //         history.at(PWD + 1) = path.c_str();
                    //         OLDPWD = PWD;
                    //         ++PWD;
                    //     }
                    // }
                    // //If here, then that means this is the first directory
                    // else {
                    //     history.push_back(path.c_str());
                    //     PWD = 0;
                    //     OLDPWD = 0;
                    // }
                }
            }
        }
    }
        
    //==========================================================================
    // END CORE OF ASSIGNMENT 4
    //==========================================================================
    
    //Checks to see if the command was actually commented out
    if(!sharp) {
        cout << input.substr(prevIndex, input.size() - prevIndex) << endl;
        Command* last = new Command(input.substr(prevIndex, input.size() - prevIndex));
        commands.push_back(last);
    }
    cout << endl;
    
    int prevResult;
    
    //Was it not one of the three?
    if(!(goHome || dash || slash)) {
    
        prevResult = commands.at(0)->execute();
        cout << endl;
        cout << "Exit status: " << prevResult << endl;
        
    }
    
    //Loop takes it's commands along with the connectors and runs execute()
    unsigned i = 0;
    while(i < connectorTypes.size()) {
        ++i;
        if(connectorTypes.at(i - 1) == ';') {
            Semicolon* semi = new Semicolon(commands.at(i), prevResult);
            prevResult = semi->execute();
        }
        else if(connectorTypes.at(i - 1) == '&') {
            Andand* amper = new Andand(commands.at(i), prevResult);
            prevResult = amper->execute();
        }
        else if(connectorTypes.at(i - 1) == '|') {
            Oror* bar = new Oror(commands.at(i), prevResult);
            prevResult = bar->execute();
        }
        cout << endl;
        cout << "Exit status: " << prevResult << endl;
    }

    /*cout << "Argument list:" << endl;
    for(unsigned i = 0; i < commands.size(); ++i) {
        //cout << commands.at(i)->command[0] << endl;
        for(unsigned j = 0; j < commands.at(i)->size; ++j) {
            printf ("%s \n", commands.at(i)->command[j]);
        }
    }
    cout << endl;
    cout << "Connector Type list:" << endl; 
    for(unsigned i = 0; i < connectorTypes.size(); ++i) {
        cout << connectorTypes.at(i) << endl;
    }*/
    
    } while(true);
    return 0;
}