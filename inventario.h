#ifndef INVENTARIO_H
#define INVENTARIO_H
#include "dbmanager.h"
#include <QWidget>
#include <QCloseEvent>
#include <QPushButton>
#include <QMainWindow>
#include <QTableView>
#include <QSqlQueryModel>
#include <QDebug>
#include <QTableWidget>
#include <QSqlRecord>
#include <QTableWidgetItem>
#include <QSqlQuery>
#include <QMessageBox>

namespace Ui {
class Inventario;
}

class Inventario : public QWidget
{
    Q_OBJECT

public:
    explicit Inventario(QWidget *parent = nullptr);
    ~Inventario();
    void closeEvent (QCloseEvent *event);
    void setInv();
    QPushButton *guardar;
    QPushButton *limpiar;
    DbManager *database;

private slots:
    void on_Guardar_clicked();

    void on_limpiar_clicked();

private:
    Ui::Inventario *ui;
};

#endif // INVENTARIO_H
