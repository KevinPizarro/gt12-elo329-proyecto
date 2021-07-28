#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <QDialog>
#include <QCloseEvent>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>

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
    QLineEdit *compra;
    QLineEdit *codigo;
    QLineEdit *proov;
    QCheckBox *Ofcheck;
    QPushButton *guardar;
    QPushButton *borrar;

public slots:
    void change_enabled_oferta();


private slots:
    void on_Guardar_clicked();

    void on_Eliminar_clicked();

private:
    Ui::Producto *ui;
};

#endif // PRODUCTO_H
