#ifndef COMPRAS_H
#define COMPRAS_H
#include "dbmanager.h"
#include <QWidget>
#include <QLineEdit>
#include <QDateEdit>
#include <QCloseEvent>
#include <QCheckBox>
#include <QPushButton>
#include <QTableView>
#include <QSqlQueryModel>
#include <QDebug>
#include <QTableWidget>
#include <QSqlRecord>
#include <QTableWidgetItem>
#include <QSqlQuery>
#include <QVector>
#include <QMessageBox>
#include <QDate>

namespace Ui {
class Compras;
}

class Compras : public QWidget
{
    Q_OBJECT

public:
    explicit Compras(QWidget *parent = nullptr);
    ~Compras();
    QLineEdit *Ncompra;
    QDateEdit *fecha;
    QLineEdit *fact;
    QLineEdit *nProveedor;
    QLineEdit *rutProveedor;
    QCheckBox *check;
    QPushButton *guardar;
    QPushButton *revisar;
    QTableWidget *tabla;
    void closeEvent (QCloseEvent *event);
    DbManager *database;
    void setNcompras();
public slots:
    void getItem(QTableWidgetItem *item);
private slots:
    void on_Guardar_pressed();

    void on_Revisar_pressed();

private:
    Ui::Compras *ui;

};

#endif // COMPRAS_H
