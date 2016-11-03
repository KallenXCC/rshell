#include "../header/Command.h"
#include "../header/Connector.h"
#include "../header/Command.h"
#include "../header/Andand.h"
#include "../header/Oror.h"
#include "../header/Semicolon.h"

int main() {
    Command* test = new Command("ls -l");
    test->execute();
    return 0;
}  