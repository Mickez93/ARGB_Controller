#include "jsonfile.h"

JSONfile::JSONfile(const QString &jsonFileName) : filename(jsonFileName.toStdString())
{
    std::string basePath = "D:\\ARGB_Controller\\ARGB_Controller\\";
    fullPath = basePath + filename;
    //Open the stream only for writing to make sure the file is created if it does not already exist
    fileStream.open(fullPath,std::fstream::app);
    fileStream.close();

}

QString JSONfile::readJSON()
{
    if (!fileStream.is_open())
    {
        fileStream.open(fullPath, std::fstream::in);
    }
    fileStream.seekg(0, std::ios::beg);
    char jsonFileContents[1000];
    fileStream.getline(jsonFileContents,1000);
    QString jsonQString(jsonFileContents);
    fileStream.close();
    qDebug() << "Read contents" << jsonQString;
    return jsonQString;
}

void JSONfile::writeJSON(const QString &jsonString, std::fstream::openmode mode)
{

    qDebug() << "mode is : " << mode;
    if (!fileStream.is_open())
    {
        if(mode == std::fstream::out)
        {
            fileStream.open(fullPath, std::fstream::out);
            qDebug() << "Filestream opened for writing" << "\n";
        }

        else
        {
            fileStream.open(fullPath, std::fstream::out | std::fstream::app);
            qDebug() << "Filestream opened for writing and appending" << "\n";
        }

    }
    else
    {

        qDebug() << "Filestream already opened" << "\n";
    }
    fileStream << jsonString.toStdString() << std::endl;
    fileStream.close();



}

std::string JSONfile::getFileName()
{
    return filename;
}
