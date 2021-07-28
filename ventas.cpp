#include "ventas.h"
#include "ui_ventas.h"

Ventas::Ventas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ventas)
{
    ui->setupUi(this);
    this->Nventa = ui->lineEdit;
    this->fecha = ui->dateEdit;
    this->check = ui->checkBox;
    this->pago = ui->comboBox;
    this->guardar = ui->Guardar;
    this->revisar = ui->Revisar;
}

Ventas::~Ventas()
{
    delete ui;
}

void Ventas::closeEvent (QCloseEvent *event){
    event->ignore();
    this->hide();
}
