#ifndef JSONFILE_H
#define JSONFILE_H

#include <fstream>
#include <string>
#include <QDebug>

class JSONfile
{
public:
    JSONfile();
    void readJSON();
    void writeJSON(QString &jsonString);
private:
    std::ofstream outStream;
    std::ifstream inStream;
    std::string filename;
};

#endif // JSONFILE_H
