#include "dbmanager.h"

DbManager::DbManager()
{
    if(!QFile::exists("D:/Miguel/Documents/Codigos/Java/ELO329/Proyecto/Proyecto/proyecto/database/test.db"))
    {
        qDebug() << "No encuentra archivo";
    }
    mydb = QSqlDatabase::addDatabase("QSQLITE");
       mydb.setDatabaseName("D:/Miguel/Documents/Codigos/Java/ELO329/Proyecto/Proyecto/proyecto/database/test.db");

       if (!mydb.open())
       {
          qDebug() << "Error: connection with database failed";
       }
       else
       {
          qDebug() << "Database: connection ok";
       }
}
