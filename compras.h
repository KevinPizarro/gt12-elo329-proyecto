#ifndef COMPRAS_H
#define COMPRAS_H

#include <QWidget>
#include <QLineEdit>
#include <QDateEdit>
#include <QCloseEvent>
#include <QCheckBox>
#include <QPushButton>

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
    QCheckBox *check;
    QPushButton *guardar;
    QPushButton *revisar;
    void closeEvent (QCloseEvent *event);


private:
    Ui::Compras *ui;
};

#endif // COMPRAS_H
