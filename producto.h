#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <QDialog>
#include <QCloseEvent>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QWidget>
#include <QDateEdit>
#include <QTableView>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QVector>
#include <QMessageBox>
#include <QDate>

namespace Ui {
class Producto;
}

class Producto : public QDialog
{
    Q_OBJECT

public:
    explicit Producto(QWidget *parent = nullptr);
    ~Producto();
    void closeEvent (QCloseEvent *event);
    bool oflag;
    QLineEdit *neto;
    QLineEdit *total;
    QLineEdit *desc;
    QLineEdit *oferta;
    QLineEdit *saldo;
    QLineEdit *codigo;
    QLineEdit *prov;
    QCheckBox *Ofcheck;
    QLineEdit *ganancia;
    QPushButton *guardar;
    QPushButton *borrar;

public slots:
    void change_enabled_oferta();

private slots:
    void on_Guardar_clicked();

    void on_Eliminar_clicked();

    void getItem();

    void calcprec();

    void calcgan();

private:
    Ui::Producto *ui;
};

#endif // PRODUCTO_H
