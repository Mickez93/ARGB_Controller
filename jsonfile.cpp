#include "jsonfile.h"

JSONfile::JSONfile() : filename("Command.json")
{
    std::string basePath = "D:\\ARGB_Controller\\ARGB_Controller\\";
    filename = basePath + filename;
    std::ofstream fileStream(filename);
    fileStream.close();

}

void JSONfile::readJSON()
{

}

void JSONfile::writeJSON(QString &jsonString)
{
    outStream.open(filename, std::ofstream::out | std::ofstream::app);
    if (!outStream.is_open())
    {
        qDebug() << "Failed to open file for writing.";
        return;
    }

    outStream << jsonString.toStdString() << std::endl;


}
