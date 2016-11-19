#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

#include "../header/Command.h"
#include "../header/Connector.h"
#include "../header/Command.h"
#include "../header/Andand.h"
#include "../header/Oror.h"
#include "../header/Semicolon.h"
#include "../header/Base.h"

int main() {
    vector<Command*> commands;
    vector<char> connectorTypes;
    string input;
    cout << "$ ";
    getline(cin, input);
    int prevIndex = 0;

    bool sharp = false;    

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
            cout << input.substr(input.find('[', prevIndex), i - input.find('[', prevIndex)) << endl;
            Command* comm = new Command(input.substr(input.find('[', prevIndex), i - input.find('[', prevIndex)));
            commands.push_back(comm);
            connectorTypes.push_back(']');
            prevIndex = i + 1;
        }
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

    cout << "Command list:" << endl;
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
    }
    
    return 0;
}