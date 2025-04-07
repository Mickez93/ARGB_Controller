#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "serialsender.h"
#include "jsonfile.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    JSONfile jsonFileInstance;
    QString jsonString = "{\"on\":true,\"bri\":255,\"seg\":[{\"col\":[[0,0,200]]}]}";
    jsonFileInstance.writeJSON(jsonString);
    QString string = "COM3";
    serialSender serialSenderInstance(string);
    string = jsonFileInstance.readJSON();
    std::cout << string.toStdString() << std::endl;
    serialSenderInstance.sendData(string);
    string = "L";
    serialSenderInstance.sendData(string);

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
