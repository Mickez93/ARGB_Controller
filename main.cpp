#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "serialsender.h"
#include "jsonfile.h"
#include "commandhandler.h"
#include <QDir>
#include "standardconfig.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    JSONfile jsonFileInstance;
    QString jsonString = "{\"on\":true,\"bri\":255,\"seg\":[{\"col\":[[0,0,200]]}]}";
    jsonFileInstance.writeJSON(jsonString);
    QString string = "COM3";
    serialSender serialSenderInstance(string);
    string = jsonFileInstance.readJSON();
    serialSenderInstance.sendData(string);
    string = "L";
    serialSenderInstance.sendData(string);
    commandHandler commandHandlerInstance(QString::fromUtf8(DB_NAME));


    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("ARGB_Controller", "Main");
    QList<QObject*> rootObjects = engine.rootObjects();
    QList<QObject*> childObjects;
    QObject *currRootItem;
    QObject *currChildItem;
    while(!rootObjects.isEmpty())
    {
        currRootItem = rootObjects.front();
        childObjects = currRootItem->children();

         while(!childObjects.isEmpty())
        {
            currChildItem = childObjects.front();

             if(currChildItem->objectName() == "clickBtn")
            {
                QObject::connect(currChildItem, SIGNAL(sendCommandSig()), &commandHandlerInstance, SLOT(sendCommand()));
                qDebug() <<currChildItem->objectName();

            }
            childObjects.pop_front();
        }

        rootObjects.pop_front();

    }










    return app.exec();
}
