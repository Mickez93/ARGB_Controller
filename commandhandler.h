#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include "jsonfile.h"

class commandHandler
{
public:
    commandHandler();
    void sendCommand();
    void commandResponse();

private:
    void formatCommand();
    JSONfile *commandFile;
};

#endif // COMMANDHANDLER_H
