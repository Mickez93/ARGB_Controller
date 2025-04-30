#include "jsonfile.h"

JSONfile::JSONfile(const QString &jsonFileName)
{
    std::string basePath = "D:\\ARGB_Controller\\ARGB_Controller\\";
    filename = basePath + jsonFileName.toStdString();
    //Open the stream only for writing to make sure the file is created if it does not already exist
    fileStream.open(filename,std::fstream::app);
    fileStream.close();

}

QString JSONfile::readJSON()
{
    if (!fileStream.is_open())
    {
        fileStream.open(filename, std::fstream::in);
    }
    fileStream.seekg(0, std::ios::beg);
    char jsonFileContents[1000];
    fileStream.getline(jsonFileContents,1000);
    QString jsonQString(jsonFileContents);
    return jsonQString;
}

void JSONfile::writeJSON(const QString &jsonString, std::fstream::openmode mode)
{

    if (!fileStream.is_open())
    {
        if(mode == std::fstream::out)
        fileStream.open(filename, std::fstream::out);
    }
    else
    {
        fileStream.open(filename, std::fstream::out | std::fstream::app);
    }

    fileStream << jsonString.toStdString() << std::endl;


}
