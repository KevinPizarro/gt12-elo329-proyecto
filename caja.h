#ifndef CAJA_H
#define CAJA_H

#include <QDialog>
#include <QCloseEvent>
#include <QLineEdit>
#include <QPushButton>
#include <QDateEdit>
#include <QDate>
#include <QDebug>
#include <QSqlQuery>
#include <QTableWidgetItem>
#include <QSqlQueryModel>
#include <QSqlRecord>

namespace Ui {
class Caja;
}

class Caja : public QDialog
{
    Q_OBJECT

public:
    explicit Caja(QWidget *parent = nullptr);
    ~Caja();
    QLineEdit *debito;
    QLineEdit *credito;
    QLineEdit *efectivo;
    QLineEdit *total;
    QLineEdit *nven;
    QPushButton *revisar;
    QDateEdit *fecha;
    void closeEvent (QCloseEvent *event);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Caja *ui;
};

#endif // CAJA_H
