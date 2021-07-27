#include "inventario.h"
#include "ui_inventario.h"

Inventario::Inventario(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Inventario)
{
    ui->setupUi(this);
    this->limpiar = ui->limpiar;
    this->guardar = ui->Guardar;
}

Inventario::~Inventario()
{
    delete ui;
}
void Inventario::closeEvent (QCloseEvent *event){
    event->ignore();
    this->hide();
}
