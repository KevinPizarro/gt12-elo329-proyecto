#ifndef VENTAS_H
#define VENTAS_H

#include <QWidget>
#include <QDateEdit>
#include <QLineEdit>
#include <QCheckBox>
#include <QCloseEvent>
#include <QComboBox>
#include <QPushButton>
#include <QDebug>
#include <QSqlQuery>
#include <QTableWidgetItem>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QMessageBox>
#include <QSignalBlocker>

namespace Ui {
class Ventas;
}

class Ventas : public QWidget
{
    Q_OBJECT

public:
    explicit Ventas(QWidget *parent = nullptr);
    ~Ventas();
    QTableWidget *tabla;
    QLineEdit *Nventa;
    QDateEdit *fecha;
    QCheckBox *check;
    QComboBox *pago;
    QLineEdit *total;
    QLineEdit *iva;
    QLineEdit *totalci;
    QPushButton *guardar;
    QPushButton *revisar;
    void closeEvent (QCloseEvent *event);
    void setNventas();

private slots:
    void on_Guardar_pressed();

    void on_Revisar_pressed();

public slots:
    void getItem(QTableWidgetItem *item);

private:
    Ui::Ventas *ui;
};

#endif // VENTAS_H
