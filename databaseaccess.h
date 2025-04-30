#ifndef DATABASEACCESS_H
#define DATABASEACCESS_H
#include <QSqlDatabase>
#include <QSqlQuery>
class databaseaccess
{
public:
    databaseaccess(const QString &dbName);
    QString fetchjsonfile(const QString &filename);
    void insertJsonFile(const QString &filename);
private:
    void initializeDatabase();
    QString dbName;

};
#endif // DATABASEACCESS_H
