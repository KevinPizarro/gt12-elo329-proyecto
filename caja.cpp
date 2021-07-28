#include "caja.h"
#include "ui_caja.h"

Caja::Caja(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Caja)
{
    ui->setupUi(this);
    this->tarjetas = ui->ttarjetas;
    this->efectivo = ui->tefectivo;
    this->total = ui->tdia;
    this->revisar = ui->pushButton;
    this->fecha = ui->dateEdit;
    this->fecha->setDate(QDate::currentDate());
}

Caja::~Caja()
{
    delete ui;
}

void Caja::on_pushButton_clicked()
{

}

void Caja::closeEvent (QCloseEvent *event){
    event->ignore();
    this->hide();
}
