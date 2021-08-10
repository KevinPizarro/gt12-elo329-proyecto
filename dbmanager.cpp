#include "dbmanager.h"
#define dir "D:/Miguel/Documents/Codigos/Java/ELO329/Proyecto/Proyecto/proyecto/database/test.db"

DbManager::DbManager()
{
    if(!QFile::exists(dir))
    {
        qDebug() << "No encuentra archivo";
    }
    mydb = QSqlDatabase::addDatabase("QSQLITE");
       mydb.setDatabaseName(dir);

       if (!mydb.open())
       {
          qDebug() << "Error: connection with database failed";
       }
       else
       {
          qDebug() << "Database: connection ok";
       }
}
