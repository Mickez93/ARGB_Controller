#include "databaseaccess.h"

databaseaccess::databaseaccess(const QString &dbName)
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName);
    if (db.open()) {
        // success!
    }

    if (!db.isValid())
    {
        qDebug() << "Database is not valid";
        return;
    }
    if (!db.open()) {
        qDebug() << "Database error:";
    } else {
        initializeDatabase();
    }
}

void databaseaccess::initializeDatabase()
{
    // Create the table if it doesn't exist
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS json_files (id INTEGER PRIMARY KEY AUTOINCREMENT, filename TEXT)");

}

QString databaseaccess::fetchjsonfile(const QString &filename)
{
    QSqlQuery query;
    QString file;
    query.prepare("SELECT id, filename FROM json_files WHERE filename = :filename LIMIT 1");
    query.bindValue(":filename", filename);  // Bind the filename parameter

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Error fetching filename from database:";
        return nullptr;
    }

    // If we find the file, print its ID and filename
    if (query.next()) {
        int id = query.value(0).toInt();     // Get the 'id' column
        file = query.value(1).toString();  // Get the 'filename' column
        qDebug() << "File found: ID =" << id << ", Filename =" << file;
    } else {
        qDebug() << "No file found with the name:" << filename;
    }
    return file;
}

void databaseaccess::insertJsonFile(const QString &filename)
{
    QSqlQuery query;
    query.prepare("INSERT INTO json_files (filename) VALUES (:poop)");
    query.bindValue(":poop", filename);
    if (!query.exec()) {
        qDebug() << "Error inserting filename into database:";
    }
}
