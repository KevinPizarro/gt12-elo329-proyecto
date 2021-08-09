#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDate>
#include <iostream>
#include <QMessageBox>

using namespace std;
/**
 * @brief MainWindow::MainWindow Constructor de la ventana principal del programa
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->showMaximized();
    ventas = new Ventas(this);
    compras = new Compras(this);
    inventario = new Inventario(this);
    producto = new Producto(this);
    caja = new Caja(this);
    producto->setWindowTitle("Producto");
    ventas->setWindowTitle("Ventas");
    compras->setWindowTitle("Compras");
    inventario->setWindowTitle("Inventario");
    caja->setWindowTitle("Caja");
    ui->mdiArea->addSubWindow(ventas);
    ui->mdiArea->addSubWindow(compras);
    ui->mdiArea->addSubWindow(inventario);
    ventas->hide();
    compras->hide();
    inventario->hide();
    producto->hide();
    caja->hide();
    ui->mdiArea->hide();
    if(ventas->check->checkState()){
        ventas->Nventa->setEnabled(false);
    }
    if(compras->check->checkState()){
        compras->Ncompra->setEnabled(false);
    }
    this->timer = new QTimer();
    this->vflag = false;
    this->cflag = false;
    connect(ventas->check,SIGNAL(stateChanged(int)),this,SLOT(change_enabled_ventas()));
    connect(compras->check,SIGNAL(stateChanged(int)),this,SLOT(change_enabled_compras()));
    connect(timer,SIGNAL(timeout()),this,SLOT(askhide()));
    timer->start(1);
}
/**
 * @brief MainWindow::~MainWindow Destructor
 */
MainWindow::~MainWindow()
{
    delete ui;
}
/**
 * @brief MainWindow::change_enabled_ventas Cambia el estado entre activo
 */
void MainWindow::change_enabled_ventas(){
    if(this->vflag){
        this->vflag = false;
    }
    else{
        this->vflag = true;
    }
    ventas->Nventa->setEnabled(this->vflag);
    ventas->revisar->setEnabled(this->vflag);
    if(!ventas->Nventa->isEnabled()){
        ventas->tabla->clearContents();
        ventas->setNventas();
        ventas->guardar->setEnabled(true);
        connect(ventas->tabla,SIGNAL(itemChanged(QTableWidgetItem*)),ventas,SLOT(getItem(QTableWidgetItem*)));
    }
    else{
        disconnect(ventas->tabla,SIGNAL(itemChanged(QTableWidgetItem*)),ventas,SLOT(getItem(QTableWidgetItem*)));
        ventas->guardar->setEnabled(false);
    }
}
/**
 * @brief MainWindow::change_enabled_compras Cambia el estado entre activo e inactivo del boton de Revisar
 */
void MainWindow::change_enabled_compras(){
    if(this->cflag){
        this->cflag = false;
    }
    else{
        this->cflag = true;
    }
    compras->Ncompra->setEnabled(this->cflag);
    compras->revisar->setEnabled(this->cflag);
    if(!compras->Ncompra->isEnabled()){
        compras->setNcompras();
        compras->guardar->setEnabled(true);
    }
    else{
        compras->guardar->setEnabled(false);
    }
}

/**
 * @brief MainWindow::on_actionVentas_triggered Muestra la ventana Ventas al accionar el menu correspondiente.
 */
void MainWindow::on_actionVentas_triggered()
{
    if(compras->isHidden() && inventario->isHidden()){
        ui->mdiArea->showMaximized();
        this->ventas->showMaximized();
        ventas->fecha->setDate(QDate::currentDate());
        ventas->Nventa->setEnabled(false);
        ventas->check->setChecked(true);
        ventas->revisar->setEnabled(false);
        this->vflag = false;
        ventas->pago->setCurrentIndex(0);
        ventas->tabla->clearContents();
        ventas->setNventas();
    }
    else{
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error");
        msgBox.setText("Primero debe cerrar la otra subventana.");
        msgBox.exec();
    }
}
/**
 * @brief MainWindow::askhide Verifica si las ventanas ventas, compras e inventario están ocultas.
 */
void MainWindow::askhide(){
    if(this->ventas->isHidden() && this->compras->isHidden() && this->inventario->isHidden()){
        ui->mdiArea->hide();
    }
}
/**
 * @brief MainWindow::on_actionCompras_triggered Muestra la vetana Compras al acciones el menu correspondiente
 */
void MainWindow::on_actionCompras_triggered()
{
    if(ventas->isHidden() && inventario->isHidden() && producto->isHidden()){
        compras->setNcompras();
        ui->mdiArea->showMaximized();
        this->compras->showMaximized();
        //ui->mdiArea->adjustSize();
        compras->fecha->setDate(QDate::currentDate());
        compras->Ncompra->setEnabled(false);
        compras->fact->setText("");
        compras->check->setChecked(true);
        compras->revisar->setEnabled(false);
        this->cflag = false;
        compras->tabla->clearContents();
        compras->nProveedor->clear();
        compras->rutProveedor->clear();
        compras->fecha->setDate(QDate::currentDate());
        compras->fact->clear();
        compras->setNcompras();

    }
    else{
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error");
        msgBox.setText("Primero debe cerrar la otra subventana.");
        msgBox.exec();
    }
}

/**
 * @brief MainWindow::on_actionInventario_triggered Muestra la ventana inventario al accionar en el menu correspondiente
 */
void MainWindow::on_actionInventario_triggered()
{
    if(compras->isHidden() && ventas->isHidden() && producto->isHidden()){
        this->inventario->setInv();
        ui->mdiArea->showMaximized();
        this->inventario->showMaximized();
    }
    else{
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error");
        msgBox.setText("Primero debe cerrar la otra subventana.");
        msgBox.exec();
    }
}

/**
 * @brief MainWindow::on_actionProductos_triggered Muestra la ventana Productos al accionar el menu correspondiente
 */
void MainWindow::on_actionProductos_triggered()
{
    this->producto->show();
    producto->codigo->clear();
    producto->desc->clear();
    producto->neto->clear();
    producto->ganancia->clear();
    producto->total->clear();
    producto->saldo->clear();
    producto->prov->clear();
    producto->oferta->clear();
    producto->Ofcheck->setChecked(false);
    producto->codigo->setFocus();
}

/**
 * @brief MainWindow::on_actionCja_triggered Muestra la ventana caja al accionar el menur correspondiente
 */
void MainWindow::on_actionCja_triggered()
{
    this->caja->show();
}

