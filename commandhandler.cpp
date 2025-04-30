#include "commandHandler.h"
#define BASE_PATH "D:\\ARGB_Controller\\ARGB_Controller\\"

commandHandler::commandHandler()
{

}

void commandHandler::sendCustomCommand()
{

}

void commandHandler::commandResponse()
{

}

commandHandler::~commandHandler()
{
}

void commandHandler::btnSendCommand(const QString jsonFileName)
{
    jsonFile = new JSONfile(jsonFileName);
    emit sendSerialCommandSignal(jsonFile->readJSON());
    delete jsonFile;

}

void sendSerialCommandSignal(const QString &jsonFileContents)
{

}
