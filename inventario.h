#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <QWidget>
#include <QCloseEvent>
#include <QPushButton>

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
    QPushButton *guardar;
    QPushButton *limpiar;

private:
    Ui::Inventario *ui;
};

#endif // INVENTARIO_H
