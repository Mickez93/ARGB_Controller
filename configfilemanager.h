#ifndef CONFIGFILEMANAGER_H
#define CONFIGFILEMANAGER_H

#include <QObject>
#include <jsonfile.h>

class configFileManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QString> configFilesList READ browseConfigFiles  NOTIFY configFilesListChanged)
public:
    explicit configFileManager(QObject *parent = nullptr);
    QList<QString> browseConfigFiles();
    //Q_INVOKABLE void addConfigFile();
    //Q_INVOKABLE void removeConfigFile();
private:
    QList<QString> configFilesList;
    QString basePath = "D:\\ARGB_Controller\\ARGB_Controller\\";


signals:
    void configFilesListChanged();
};

#endif // CONFIGFILEMANAGER_H
