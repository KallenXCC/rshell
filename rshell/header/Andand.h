/* Type 1: "&&" */
#ifndef ANDAND_H
#define ANDAND_H

#include "Connector.h"

class Andand : public Connector {
    public:
       Andand(Base* current, int previous) : Connector(current, previous) {};
       int execute();
};

#endif