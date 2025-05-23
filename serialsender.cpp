#include "serialsender.h"

serialSender::serialSender(QString &portName, QObject *parent) :
    QObject(parent), serialPort(new QSerialPort(portName))
{
    serialPort->setBaudRate(115200);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    if (serialPort->open(QIODevice::ReadWrite))
    {
        qDebug() << "Serial port opened successfully.";

        // Send the character 'L'
        QByteArray dataToSend = "L"; // This sends the letter 'L'
        qint64 bytesWritten = serialPort->write(dataToSend);

        if (bytesWritten == -1) {
            qDebug() << "Failed to write data to serial port.";
        } else {
            //qDebug() << "Data 'L' sent successfully.";
        }

        // Wait for a response (this will block until data is available)
        if (serialPort->waitForReadyRead(5000)) { // Timeout after 5 seconds
            QByteArray responseData = serialPort->readAll(); // Read all available data
            qDebug() << "Received response:" << responseData;
        } else {
            qDebug() << "No response received within timeout period.";
        }
    }
    else
    {
        qDebug() << "Failed to open serial port.";
    }
};

serialSender::serialSender(const QString &portName, const int baudRate, const QSerialPort::DataBits dataBits,const QSerialPort::Parity parity,
                           const QSerialPort::StopBits stopBits, QObject *parent) :
    QObject(parent), serialPort(new QSerialPort(portName))
{
    serialPort->setBaudRate(baudRate);
    serialPort->setDataBits(dataBits);
    serialPort->setParity(parity);
    serialPort->setStopBits(stopBits);
    if(serialPort->open(QIODeviceBase::ReadWrite))
    {
        qDebug() << "Serial port opened successfully.";
    }
}

bool serialSender::sendData(const QString &data)
{
    if(!serialPort->isOpen())
    {
        qDebug() << "Serial port is not open.";
        return false;
    }
    else
    {
        qDebug() << "Serial port is open.";
    }

    QByteArray dataToSend = data.toUtf8();
    for (int i = 0; i < dataToSend.size(); ++i) {
        qDebug() << "Byte" << i << ":" << (int)dataToSend[i];
    }

    qint64 bytesWritten = serialPort->write(dataToSend);
    if (bytesWritten != -1)
    {
        return true;
    }
    else
    {
        qDebug() << "Error sending data";
        return false;
    }
};
