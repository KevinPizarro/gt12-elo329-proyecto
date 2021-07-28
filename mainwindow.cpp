#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDate>
#include <iostream>
#include <QMessageBox>

using namespace std;

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

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::change_enabled_ventas(){
    if(this->vflag){
        this->vflag = false;
    }
    else{
        this->vflag = true;
    }
    ventas->Nventa->setEnabled(this->vflag);
    ventas->revisar->setEnabled(this->vflag);
}

void MainWindow::change_enabled_compras(){
    if(this->cflag){
        this->cflag = false;
    }
    else{
        this->cflag = true;
    }
    compras->Ncompra->setEnabled(this->cflag);
    compras->revisar->setEnabled(this->cflag);
}


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
    }
    else{
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error");
        msgBox.setText("Primero debe cerrar la otra subventana.");
        msgBox.exec();
    }
}

void MainWindow::askhide(){
    if(this->ventas->isHidden() && this->compras->isHidden() && this->inventario->isHidden()){
        ui->mdiArea->hide();
    }
    if(producto->isVisible() && !producto->isActiveWindow()){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error");
        msgBox.setText("Primero debe cerrar la ventana de producto.");
        msgBox.exec();
        producto->activateWindow();
    }
    if(caja->isVisible() && !caja->isActiveWindow()){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error");
        msgBox.setText("Primero debe cerrar la ventana de caja.");
        msgBox.exec();
        caja->activateWindow();
    }
}

void MainWindow::on_actionCompras_triggered()
{
    if(ventas->isHidden() && inventario->isHidden()){
        ui->mdiArea->showMaximized();
        this->compras->showMaximized();
        compras->fecha->setDate(QDate::currentDate());
        compras->Ncompra->setEnabled(false);
        compras->fact->setText("");
        compras->check->setChecked(true);
        compras->revisar->setEnabled(false);
        this->cflag = false;
    }
    else{
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error");
        msgBox.setText("Primero debe cerrar la otra subventana.");
        msgBox.exec();
    }
}


void MainWindow::on_actionInventario_triggered()
{
    if(compras->isHidden() && ventas->isHidden()){
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


void MainWindow::on_actionProductos_triggered()
{
    this->producto->show();
}


void MainWindow::on_actionCja_triggered()
{
    this->caja->show();
}

