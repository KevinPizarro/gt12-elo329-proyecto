#include "inventario.h"
#include "ui_inventario.h"

Inventario::Inventario(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Inventario)
{
    ui->setupUi(this);
    this->limpiar = ui->limpiar;
    this->guardar = ui->Guardar;
    database= new DbManager();
    setInv();
}

Inventario::~Inventario()
{
    delete ui;
}
void Inventario::closeEvent (QCloseEvent *event){
    event->ignore();
    this->hide();
}

void Inventario::setInv(){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from Producto");
    QSqlQuery query;
    QSqlRecord row;
    for(int i=0; i<model->rowCount(); i++){
        row=model->record(i);
        for(int j=0;j<3;j++){
            ui->tableWidget->setItem(i,j,new QTableWidgetItem(row.value(j).toString()));
            if(j == 0 || j == 1){
                ui->tableWidget->item(i,j)->setFlags(ui->tableWidget->item(i,j)->flags() & ~Qt::ItemIsEditable);
            }
        }
    }
    ui->tableWidget->setColumnWidth(0,200);
    ui->tableWidget->setColumnWidth(1,700);
    ui->tableWidget->setColumnWidth(2,150);
    ui->tableWidget->setFixedWidth(1100);
    ui->tableWidget->setFixedHeight(400);
    ui->tableWidget->adjustSize();
    ui->tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

}

void Inventario::on_Guardar_clicked(){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from Producto");
    QSqlQuery query;
    int codigo;
    int saldo;
    QString c;
    QString s;
    for(int i=0; i < model->rowCount(); i++){
        codigo = ui->tableWidget->item(i,0)->text().toInt();
        saldo  = ui->tableWidget->item(i,2)->text().toInt();
        c = QString::number(codigo);
        s = QString::number(saldo);
        query.prepare("update Producto SET [Saldo] = :saldo where Codigo = :codigo");
        query.bindValue(":codigo",c);
        query.bindValue(":saldo",s);
        if(query.exec()){
        }
    }
    QMessageBox msgBox;
    msgBox.setWindowTitle("Guardado");
    msgBox.setText("Cambios Guardados.");
    msgBox.exec();
}


void Inventario::on_limpiar_clicked(){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from Producto");
    QSqlQuery query;
    QSqlRecord row;
    for(int i=0; i<model->rowCount(); i++){
        row=model->record(i);
        for(int j=0;j<3;j++){
            ui->tableWidget->setItem(i,j,new QTableWidgetItem(row.value(j).toString()));
            if(j == 0 || j == 1){
                ui->tableWidget->item(i,j)->setFlags(ui->tableWidget->item(i,j)->flags() & ~Qt::ItemIsEditable);
            }
        }
    }
}

