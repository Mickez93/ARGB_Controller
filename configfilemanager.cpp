#include "configfilemanager.h"
#include <QDir>

configFileManager::configFileManager(QObject *parent)
    : QObject{parent}
{

    QDir currentDir(basePath);
    QStringList includeFilter;
    QStringList excludeFilter;
    includeFilter << "*.json";
    excludeFilter << "_";
    QFileInfoList files = currentDir.entryInfoList(includeFilter, QDir::Files);

    //Find json files in the directory
    for(const QFileInfo &fileInfo : files)
    {

        bool excludeFile = false;
        QString fileName = fileInfo.fileName();
        //Find files that start with the exclude filter
        for(const QString &exclude : excludeFilter)
        {
            //Exclude files that start with the exclude filter
            if(fileName.startsWith(exclude))
            {
                excludeFile = true;
            }
        }
        //Add files that should not be excluded
        if(!excludeFile)
        {
            configFilesList.append(fileName);
            qDebug() << "File found:" << fileName;
        }

    }



}

QList<QString> configFileManager::browseConfigFiles()
{
    return configFilesList;
}
