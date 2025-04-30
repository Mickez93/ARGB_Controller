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
private:
    std::fstream fileStream;
    std::string filename;
};

#endif // JSONFILE_H
