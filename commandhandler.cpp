#include "commandHandler.h"
#define BASE_PATH "D:\\ARGB_Controller\\ARGB_Controller\\"

commandHandler::commandHandler() : liveJsonFile("_LiveCommand.json")
{

}

void commandHandler::commandResponse()
{

}

int commandHandler::getRGBValue() const
{
    return 1;
}

void commandHandler::setRGBValue(Color c, const int value)
{

    std::string preRGBString = "{\"on\":true,\"bri\":255,\"seg\":[{\"col\":[[";
    std::string postRGBString = "]]}]}";
    std::string rgbString;

    switch(c)
    {
        case Red:
            m_rValue = value;
            break;

        case Green:
            m_gValue = value;
            break;

        case Blue:
            m_bValue = value;
            break;

        default:
            m_rValue = 0;
            m_gValue = 0;
            m_bValue = 0;
    }
    std::string rString = std::to_string(m_rValue);
    rString.append(",");
    std::string gString = std::to_string(m_gValue);
    gString.append(",");
    std::string bString = std::to_string(m_bValue);

    rgbString = rString + gString + bString;
    qDebug() << rgbString << "\n";
    QString jsonString = QString::fromStdString(preRGBString + rgbString + postRGBString);
    qDebug() << jsonString << "\n";
    liveJsonFile.writeJSON(jsonString, std::fstream::out);
    //qDebug() << liveJsonFile.readJSON() << "\n";
    sendCommand(QString::fromStdString(liveJsonFile.getFileName()));

}



commandHandler::~commandHandler()
{
}

void commandHandler::sendCommand(const QString jsonFileName)
{
    jsonFile = new JSONfile(jsonFileName);
    qDebug() << jsonFileName;
    emit sendSerialCommandSignal(jsonFile->readJSON());
    delete jsonFile;

}

void sendSerialCommandSignal(const QString &jsonFileContents)
{

}
