#ifndef SERIALSENDER_H
#define SERIALSENDER_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

class serialSender : public QObject
{
    Q_OBJECT

public:
    serialSender(QString &portName, QObject *parent = nullptr);

    serialSender(const QString &portName, const int baudRate, const QSerialPort::DataBits dataBits,const QSerialPort::Parity parity,
                 const QSerialPort::StopBits stopBits, QObject *parent = nullptr);

    void sendData(const QString &data);
private:
    QSerialPort *serialPort;
};

#endif // SERIALSENDER_H
