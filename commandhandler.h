#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H
#include "jsonfile.h"
#include <QObject>
#include <fstream>

class commandHandler : public QObject
{
    Q_OBJECT


public:
    commandHandler();
    ~commandHandler();
    void commandResponse();
    int getRGBValue() const;

    enum Color
    {
        Red,
        Green,
        Blue
    };
    Q_ENUM(Color)
    Q_INVOKABLE void setRGBValue(Color c, const int value);

private:
    JSONfile *jsonFile;
    JSONfile liveJsonFile;
    int m_rValue = 0;
    int m_gValue = 0;
    int m_bValue = 0;

public slots:
    void sendCommand(const QString JSONfile);
signals:
    void sendSerialCommandSignal(const QString &jsonFileContents = NULL);





};

#endif // COMMANDHANDLER_H
