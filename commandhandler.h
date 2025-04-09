#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H
#include "databaseaccess.h"
#include "jsonfile.h"

class commandHandler
{
public:
    commandHandler(QString dbName);
    ~commandHandler();
    void sendCustomCommand();
    void sendPreDefCommand();
    void commandResponse();

private:
    databaseaccess *db;
    JSONfile *jsonFile;
    void formatCommand();

};

#endif // COMMANDHANDLER_H
