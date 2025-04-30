#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H
#include "jsonfile.h"
#include <QObject>

class commandHandler : public QObject
{
    Q_OBJECT

public:
    commandHandler();
    ~commandHandler();
    void sendCustomCommand();
    void createPreDefCommand();
    void sendPreDefCommand();
    void commandResponse();

private:
    JSONfile *jsonFile;
    void formatCommand();

public slots:
    void btnSendCommand(const QString JSONfile);
signals:
    void sendSerialCommandSignal(const QString &jsonFileContents);





};

#endif // COMMANDHANDLER_H
