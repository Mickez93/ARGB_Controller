#include "jsonfile.h"

JSONfile::JSONfile() : filename("Command.json")
{
    std::string basePath = "D:\\ARGB_Controller\\ARGB_Controller\\";
    filename = basePath + filename;
    fileStream.open(filename,std::fstream::out | std::fstream::in);

}

QString JSONfile::readJSON()
{
    if (!fileStream.is_open())
    {
        fileStream.open(filename, std::fstream::out | std::fstream::in);
    }
    fileStream.seekg(0, std::ios::beg);
    char jsonFileContents[1000];
    fileStream.getline(jsonFileContents,1000);
    QString jsonQString(jsonFileContents);
    return jsonQString;
}

void JSONfile::writeJSON(const QString &jsonString)
{

    if (!fileStream.is_open())
    {
        fileStream.open(filename, std::fstream::out | std::fstream::in);
    }

    fileStream << jsonString.toStdString() << std::endl;


}
