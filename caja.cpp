#include "caja.h"
#include "ui_caja.h"
/**
 * @brief Caja::Caja constructor de la clase Caja
 * @param parent: Ventana principal a la que pertenece
 */
Caja::Caja(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Caja)
{
    ui->setupUi(this);
    this->debito = ui->debito;
    this->credito = ui->credito;
    this->efectivo = ui->tefectivo;
    this->total = ui->tdia;
    this->nven = ui->nven;
    this->revisar = ui->pushButton;
    this->fecha = ui->dateEdit;
    this->fecha->setDate(QDate::currentDate());
}

/**
 * @brief Caja::~Caja: Destructor de Caja
 */
Caja::~Caja()
{
    delete ui;
}
/**
 * @brief Caja::on_pushButton_clicked: Entrega el total de Caja
 */
void Caja::on_pushButton_clicked(){
    QString f = fecha->text();
    total->clear();
    debito->clear();
    credito->clear();
    efectivo->clear();
    float t = 0;
    float td = 0;
    float tc = 0;
    float te = 0;
    int i=0;
    bool flag=true;
    QSqlQuery query;
    query.prepare("select * from Venta where [fecha] = :fecha");
    query.bindValue(":fecha",f);
    if(!query.exec()){
    }
    else{
        query.first();
        if(query.isValid()){
            while(flag){
                if(query.value(7) == "Efectivo"){
                    te += query.value(1).toFloat();
                }
                else if(query.value(7) == "Débito"){
                    td += query.value(1).toFloat();
                }
                else if(query.value(7) == "Crédito"){
                    tc += query.value(1).toFloat();
                }
                if(!query.next()){
                    flag=false;
                    nven->setText(QString::number(i+1));
                }
                i++;
            }
        }
        t = tc + td + te;
        if(t == 0){
            nven->setText("0");
            total->setText("0");
            debito->setText("0");
            credito->setText("0");
            efectivo->setText("0");
        }
        else{
            total->setText(QString::number(t));
            debito->setText(QString::number(td));
            credito->setText(QString::number(tc));
            efectivo->setText(QString::number(te));
        }
    }
}
/**
 * @brief Caja::closeEvent: Metodo que maneja el cierre de la ventana, modificado para que no destruya el objeto
 * @param event: Evento de cierre de ventana
 */
void Caja::closeEvent (QCloseEvent *event){
    event->ignore();
    this->hide();
}
