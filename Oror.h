/* Type 2: "||" */
#ifndef OROR_H
#define OROR_H

#include "Connector.h"

class Oror : public Connector {
    public:
       Oror(Base* current, int previous) : Connector(current, previous) {};
       int execute();
};

#endif