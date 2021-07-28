#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <ventas.h>
#include <compras.h>
#include <inventario.h>
#include <producto.h>
#include <caja.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bool vflag, cflag;
    QTimer *timer;
    Ventas *ventas;
    Compras *compras;
    Inventario *inventario;
    Producto *producto;
    Caja *caja;

public slots:
    void change_enabled_compras();
    void change_enabled_ventas();
    void askhide();

private slots:
    void on_actionVentas_triggered();
    void on_actionCompras_triggered();
    void on_actionInventario_triggered();
    void on_actionProductos_triggered();
    void on_actionCja_triggered();
};
#endif // MAINWINDOW_H
