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
    /**
     * @brief closeEvent Metodo que se ejecuta al cerrar la subventana de inventario, se modifica para que solo lo oculte
     * @param event
     */
    void closeEvent (QCloseEvent *event);
    /**
     * @brief setInv Metodo para setear los productos en la ventana de inventario
     */
    void setInv();
    /**
     * @brief guardar Boton para guardar cambios
     */
    QPushButton *guardar;
    /**
     * @brief limpiar Boton para limpiar cambios
     */
    QPushButton *limpiar;
    /**
     * @brief database Base de datos
     */
    DbManager *database;

private slots:
    /**
     * @brief on_Guardar_clicked Slot que recibe la pulsacion de guardar
     */
    void on_Guardar_clicked();
    /**
     * @brief on_limpiar_clicked Slot que recibe la pulsacion de limpiar
     */
    void on_limpiar_clicked();

private:
    Ui::Inventario *ui;
};

#endif // INVENTARIO_H
