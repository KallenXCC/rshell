/* Type 1: "&&" */
#ifndef ANDAND_H
#define ANDAND_H

class Andand : public Connector {
    public:
       Andand(Base* current, int previous) : Connector(current, previous) {};
       int execute();
};

#endif