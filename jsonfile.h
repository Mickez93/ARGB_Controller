#ifndef JSONFILE_H
#define JSONFILE_H

#include <fstream>
#include <string>
#include <QDebug>

class JSONfile
{
public:
    JSONfile();
    QString readJSON();
    void writeJSON(const QString &jsonString);
private:
    std::fstream fileStream;
    std::string filename;
};

#endif // JSONFILE_H
