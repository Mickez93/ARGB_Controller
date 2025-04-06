#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "serialsender.h"
#include "jsonfile.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    JSONfile jsonFileInstance;
    QString jsonString = "{\"command\":\"L\"}";
    jsonFileInstance.writeJSON(jsonString);
    QString string = "COM3";
    serialSender serialSenderInstance(string);
    qDebug() << "poop";

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
