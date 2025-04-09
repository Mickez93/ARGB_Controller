#ifndef DATABASEACCESS_H
#define DATABASEACCESS_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <iostream>
class databaseaccess
{
public:
    databaseaccess(QString dbName);
    void fetchjsonfile(QString filename);
    void insertJsonFile(QString filename);
private:
    void initializeDatabase();
    QString dbName;

};
#endif // DATABASEACCESS_H
