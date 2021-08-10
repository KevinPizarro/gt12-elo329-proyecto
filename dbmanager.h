#ifndef DBMANAGER_H
#define DBMANAGER_H
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlQueryModel>
#include <QTableView>
#include <QFile>

class DbManager
{
public:
    DbManager();
    QSqlDatabase mydb;
private:

};

#endif // DBMANAGER_H
