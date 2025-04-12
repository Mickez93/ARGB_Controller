#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H
#include "databaseaccess.h"
#include "jsonfile.h"

class commandHandler : public QObject
{
    Q_OBJECT

public:
    commandHandler(const QString &dbName);
    ~commandHandler();
    void sendCustomCommand();
    void createPreDefCommand();
    void sendPreDefCommand();
    void commandResponse();

private:
    databaseaccess *db;
    JSONfile *jsonFile;
    void formatCommand();

public slots:
    void sendCommand();



};

#endif // COMMANDHANDLER_H
