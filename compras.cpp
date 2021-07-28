#include "compras.h"
#include "ui_compras.h"

Compras::Compras(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Compras)
{
    ui->setupUi(this);
    this->Ncompra = ui->lineEdit;
    this->fecha = ui->dateEdit;
    this->check = ui->checkBox;
    this->fact = ui->lineEdit_2;
    this->revisar = ui->Revisar;
    this->guardar = ui->Guardar;
}

Compras::~Compras()
{
    delete ui;
}

void Compras::closeEvent (QCloseEvent *event){
    event->ignore();
    this->hide();
}
