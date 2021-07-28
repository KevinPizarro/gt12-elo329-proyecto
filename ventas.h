#ifndef VENTAS_H
#define VENTAS_H

#include <QWidget>
#include <QDateEdit>
#include <QLineEdit>
#include <QCheckBox>
#include <QCloseEvent>
#include <QComboBox>
#include <QPushButton>

namespace Ui {
class Ventas;
}

class Ventas : public QWidget
{
    Q_OBJECT

public:
    explicit Ventas(QWidget *parent = nullptr);
    ~Ventas();
    QLineEdit *Nventa;
    QDateEdit *fecha;
    QCheckBox *check;
    QComboBox *pago;
    QPushButton *guardar;
    QPushButton *revisar;
    void closeEvent (QCloseEvent *event);

private:
    Ui::Ventas *ui;
};

#endif // VENTAS_H
