#include "compras.h"
#include "ui_compras.h"

/**
 * @brief Compras::Compras: Constructor de la clase
 * @param parent: Ventana principal a la que pertenece
 */
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

/**
 * @brief Compras::~Compras: Destructor de la clase
 */
Compras::~Compras()
{
    delete ui;
}

/**
 * @brief Compras::closeEvent: Metodo que maneja el cierre de la ventana, modificado para que no destruya el objeto
 * @param event: Evento de cierre de ventana
 */
void Compras::closeEvent (QCloseEvent *event){
    event->ignore();//Ignora el cierre de ventana
    this->hide();   //Esconde la ventana
}
