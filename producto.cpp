#include "producto.h"
#include "ui_producto.h"

Producto::Producto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Producto)
{
    ui->setupUi(this);
    this->compra = ui->PrecCompra;
    this->Ofcheck = ui->Ofertacheck;
    this->borrar = ui->Eliminar;
    this->guardar = ui->Guardar;
    this->proov = ui->Proovedor;
    this->neto = ui->Precneto;
    this->total = ui->PrecIva;
    this->oferta = ui->PrecOferta;
    this->desc = ui->Descripcion;
    this->saldo = ui->Saldo;
    this->codigo = ui->Codigo;
    this->oflag = false;
    connect(this->Ofcheck,SIGNAL(stateChanged(int)),this,SLOT(change_enabled_oferta()));
}

Producto::~Producto()
{
    delete ui;
}

void Producto::closeEvent (QCloseEvent *event){
    event->ignore();
    this->hide();
}


void Producto::change_enabled_oferta(){
    if(this->oflag){
        this->oflag = false;
    }
    else{
        this->oflag = true;
    }
    this->oferta->setEnabled(oflag);
}

void Producto::on_Guardar_clicked()
{

}


void Producto::on_Eliminar_clicked()
{

}

