#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "serialsender.h"
#include "jsonfile.h"
#include "commandhandler.h"
#include <QDir>
#include "configfilemanager.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    JSONfile jsonFileInstance("_LiveCommand.json");
    configFileManager configFileManagerInstance;
    ////// To be removed later
    QString jsonString = "{\"on\":true,\"bri\":255,\"seg\":[{\"col\":[[0,0,200]]}]}";
    jsonFileInstance.writeJSON(jsonString);
    //
    QString string = "COM3";
    serialSender serialSenderInstance(string);
    commandHandler commandHandlerInstance;
    QObject::connect(&commandHandlerInstance, SIGNAL(sendSerialCommandSignal(QString)), &serialSenderInstance, SLOT(sendSerialCommand(QString)));
    qmlRegisterSingletonInstance("CmdHandler",1,0,"CommandHandler",&commandHandlerInstance);
    qmlRegisterSingletonInstance("ConfHandler",1,0,"ConfigHandler",&configFileManagerInstance);


    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("ARGB_Controller", "Main");








    return app.exec();
}
