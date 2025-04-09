#include "commandHandler.h"
#define BASE_PATH "D:\\ARGB_Controller\\ARGB_Controller\\"

commandHandler::commandHandler(QString dbName)
{
    // Initialize the database
    db = new databaseaccess(BASE_PATH + dbName);
    db->insertJsonFile("poopster.json");
    db->fetchjsonfile("poopster.json");
}

void commandHandler::sendCustomCommand()
{

}

void commandHandler::commandResponse()
{

}

commandHandler::~commandHandler()
{
    delete db;
}
