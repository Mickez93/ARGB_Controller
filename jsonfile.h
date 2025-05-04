#ifndef JSONFILE_H
#define JSONFILE_H

#include <fstream>
#include <string>
#include <QDebug>

class JSONfile
{
public:
    JSONfile(const QString &jsonFileName);
    QString readJSON();
    void writeJSON(const QString &jsonString, std::fstream::openmode mode = std::fstream::out);
    std::string getFileName(void);
private:
    std::fstream fileStream;
    std::string filename;
    std::string basePath = "D:\\ARGB_Controller\\ARGB_Controller\\";
    std::string fullPath;
};

#endif // JSONFILE_H
