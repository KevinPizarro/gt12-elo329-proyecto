#include "caja.h"
#include "ui_caja.h"

/**
 * @brief Caja::Caja: Constructor de la clase
 * @param parent: Ventana principal a la que pertenece
 */
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

/**
 * @brief Caja::~Caja: Destructor de la clase
 */
Caja::~Caja()
{
    delete ui;
}

/**
 * @brief Caja::on_pushButton_clicked: Slot correspondiente a cuando es presionado el boton Revisar
 */
void Caja::on_pushButton_clicked()
{
    //TODO: Por implementar
}

/**
 * @brief Caja::closeEvent: Metodo que maneja el cierre de la ventana, modificado para que no destruya el objeto
 * @param event: Evento de cierre de ventana
 */
void Caja::closeEvent (QCloseEvent *event){
    event->ignore();//Ignora el cierre de ventana
    this->hide();   //Esconde la ventana
}
