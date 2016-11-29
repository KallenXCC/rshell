#include <iostream>
#include <vector>
#include <stdio.h>
#include <unistd.h>
#include <string>
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
    vector<Base*> commands;
    vector<char> connectorTypes;
    vector<const char*> history;

    string input;
    cout << "$ ";
    getline(cin, input);
    int prevIndex = 0;

    unsigned int PWD = 0;
    unsigned int OLDPWD = 0;

    bool sharp = false;    
    bool goHome = true;
    bool dash = false;
    bool slash = false;
    cout << "Parsing commands: " << endl;
    
    for (unsigned i = 0; i < input.size(); ++i) {
        if (input.at(i) == '#') {
            Command* comm = new Command(input.substr(prevIndex, i - prevIndex));
            commands.push_back(comm);
            sharp = true;
            prevIndex = i + 1;
        }  
        if (input.at(i) == ';') {
            cout << input.substr(prevIndex, i - prevIndex) << endl;
            Command* comm = new Command(input.substr(prevIndex, i - prevIndex));
            commands.push_back(comm);
            connectorTypes.push_back(';');
            prevIndex = i + 1;
        }
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
        if (input.at(i) == ']') {
            cout << input.substr(input.find('[', prevIndex) + 1, i - input.find('[', prevIndex) - 1) << endl;
            Flag* fl = new Flag(input.substr(input.find('[', prevIndex) + 1, i - input.find('[', prevIndex) - 1));
            commands.push_back(fl);
            connectorTypes.push_back(']');
            prevIndex = i + 1;
        }
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
<<<<<<< HEAD
        // Dan's contribution    :D
        if (input.at(0) == 'c' && input.at(1) == 'd') {
            for (unsigned d = 3; d < input.size(); ++d) {
                //Do they want to go back to the previous directory?
                if (input.at(d) == '-') {
                    goHome = false;
                    dash = true;
                }
                //Did they want to go to a new directory/path?
                else if (input.at(d) == '/') {
                    goHome = false;
                    slash = true;
                }
            }
            //User only put "cd", meaning to go back home
            if (goHome) {
                //Set OLDPWD to PWD
                //PWD = $HOME; //Set PWD to Home
                
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
                    // else {
                        //Sets the environment to HOME
                        int set = setenv("HOME", env, 0);
                        if (set == -1) {
                            perror("setenv");
                        }
                        else {
                            if (PWD == history.size() - 1) {
                                history.push_back(env);
                                OLDPWD = PWD;
                                ++PWD;
                            }
                            //If not, then that means we're somewhere in the middle
                            else {
                                history.at(PWD + 1) = env;
                                OLDPWD = PWD;
                                ++PWD;
                            }
                        }
                    // }
                }
            }
            //User put "cd -", meaning to go back to the previous environment
            else if (dash) {
                //Set a temp to OLDPWD
                //Set OLDPWD to PWD
                //Set PWD to temp
                
                //Is it empty? If not, then continue
                if (history.size() > 0) {
                    const char* temp = history.at(OLDPWD);
                    history.at(OLDPWD) = history.at(PWD);
                    history.at(PWD) = temp;
                }
            }
            //User put cd <PATH>, meaning go to the path specified by the input
            else if (slash) {
                //Set OLDPWD to PWD
                //PWD = <PATH>; //Set PWD to PATH
                
                string path;
                // int temp = i + 2;
                path = input.substr(input.find(' '));
                // path = input.substr(' ', temp);
                int dir = chdir(path.c_str());
                if (dir == -1) {
                    perror("chdir");
                }
                else {
                    //Gets the home environment
                    char* env = getenv(path.c_str());
                    if (env == NULL) {
                        perror("getenv");
                    }
                    else {
                        //Sets the environment to HOME
                        int set = setenv(path.c_str(), env, 0);
                        if (set == -1) {
                            perror("setenv");
                        }
                        //Is the current path not starting from the beginning? (In other words, did the user access previous directories before?)
                        if (history.size() > 0) {
                            //Are we at the end of history? If so, then push_back
                            if (PWD == history.size() - 1) {
                                history.push_back(path.c_str());
                                OLDPWD = PWD;
                                ++PWD;
                            }
                            //If not, then that means we're somewhere in the middle
                            else {
                                history.at(PWD + 1) = path.c_str();
                                OLDPWD = PWD;
                                ++PWD;
                            }
                        }
                        //If here, then that means this is the first directory
                        else {
                            history.push_back(path.c_str());
                            PWD = 0;
                            OLDPWD = 0;
                        }
                    }
                }
            }
        }
        //Dan's contribution    :D
    }
    if(!sharp) {
        cout << input.substr(prevIndex, input.size() - prevIndex) << endl;
        Command* last = new Command(input.substr(prevIndex, input.size() - prevIndex));
        commands.push_back(last);
    }
    cout << endl;
    
    int prevResult = commands.at(0)->execute();
    cout << endl;
    cout << "Exit status: " << prevResult << endl;
    
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
    
    return 0;
}
