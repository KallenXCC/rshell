#include <iostream>
using namespace std;

#include "../header/Command.h"
#include "../header/Connector.h"
#include "../header/Command.h"
#include "../header/Andand.h"
#include "../header/Oror.h"
#include "../header/Semicolon.h"
#include "../header/Base.h"

int main() {
    string input;
    cout << "$ ";
    getline(cin, input);
    
    Command* test = new Command(input);
    test->execute();
    
    return 0;
}  