#include "compras.h"
#include "ui_compras.h"
/**
 * @brief Compras::Compras: constructor de la clase Compras
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
    this->nProveedor = ui->lineEdit_3;
    this->rutProveedor = ui->lineEdit_4;
    this->tabla = ui->tableWidget;
    connect(ui->tableWidget,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(getItem(QTableWidgetItem*)));

}
/**
 * @brief Compras::~Compras: Destructor de la clase Compras
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
    event->ignore();
    this->hide();
}
/**
 * @brief Compras::getItem: Obtiene la información del producto a buscar
 * @param item: Codigo del producto a buscar
 */
void Compras::getItem(QTableWidgetItem *item)
{
    if(item->column()==0){
        int cod = item->text().toInt();
        int row = item->row();
        QSqlQuery query;
        query.prepare("select * from Producto where Codigo = :codigo");
        query.bindValue(":codigo",cod);
        if(!query.exec()){
        }
        query.first();
        if(query.isValid()){
            ui->tableWidget->setItem(row,1,new QTableWidgetItem(query.value(1).toString()));
            ui->tableWidget->setItem(row,2,new QTableWidgetItem(query.value(2).toString()));
            ui->tableWidget->item(row,2)->setFlags(ui->tableWidget->item(row,2)->flags() & ~Qt::ItemIsEditable);
            ui->tableWidget->setItem(row,4,new QTableWidgetItem(query.value(3).toString()));
            ui->tableWidget->item(row,4)->setFlags(ui->tableWidget->item(row,4)->flags() & ~Qt::ItemIsEditable);
            ui->tableWidget->setItem(row,3,new QTableWidgetItem(QString::number(1)));
        }
        else{
            for(int i = 0; i < 6; i++){
                if(ui->tableWidget->item(row,i)){
                    ui->tableWidget->item(row,i)->setText("");
                }
            }
        }
    }
    if(item->column()==3){
        int row=item->row();
        int cant=ui->tableWidget->item(row,3)->text().toInt();
        int cod = item->text().toInt();
        QSqlQuery query;
        query.prepare("select * from Producto where Codigo = :codigo");
        query.bindValue(":codigo",cod);
        if(!query.exec()){
        }
        query.first();
        if(query.isValid()){
            cant=ui->tableWidget->item(row,3)->text().toInt();
            float precio=ui->tableWidget->item(row,4)->text().toFloat();
            float t=precio*cant;
            ui->tableWidget->setItem(row,5,new QTableWidgetItem(QString::number(t)));
        }
    }
}

/**
 * @brief Compras::on_Guardar_pressed: Guarda la compra
 */
void Compras::on_Guardar_pressed(){
    bool flag=true;
    int i=0;
    QSqlQuery query,query3;
    while(flag)
    {
        QString nfactura=ui->lineEdit_2->text();
        QString codigo=ui->tableWidget->item(i,0)->text();
        QString nombre=ui->tableWidget->item(i,1)->text();
        QString Cantidad=ui->tableWidget->item(i,3)->text();
        QString precio=ui->tableWidget->item(i,4)->text();
        QString total=ui->tableWidget->item(i,5)->text();
        QString nProveedor=ui->lineEdit_3->text();
        QString rutProveedor=ui->lineEdit_4->text();
        QString idCompra=Ncompra->text();
        QString date=fecha->text();
        query.prepare("insert into Compra values ( :codigo , :nombre , :cantidad, :precio, :factura, :total, :idCompra, :nProveedor, :rutProveedor,:date)");
        query.bindValue(":codigo",codigo);
        query.bindValue(":nombre",nombre);
        query.bindValue(":cantidad",Cantidad);
        query.bindValue(":precio",precio);
        query.bindValue(":factura",nfactura);
        query.bindValue(":total",total);
        query.bindValue(":idCompra",idCompra);
        query.bindValue(":nProveedor",nProveedor);
        query.bindValue(":rutProveedor",rutProveedor);
        query.bindValue(":date",date);
        if(query.exec())
        {
            int nSaldo=(ui->tableWidget->item(i,2)->text().toInt()+Cantidad.toInt());
            query3.prepare("update Producto SET [Saldo] = :saldo where codigo = :codigo");
            query3.bindValue(":saldo",nSaldo);
            query3.bindValue(":codigo",codigo);
            if(query3.exec())
            {
            }

        }
        i++;
        if(ui->tableWidget->item(i,0)==0){ flag=false;}
    }
    ui->tableWidget->clearContents();
    nProveedor->clear();
    rutProveedor->clear();
    fecha->setDate(QDate::currentDate());
    fact->clear();
    setNcompras();
}

/**
 * @brief Compras::setNcompras: Actualiza el siguiente id de Compras a guardar
 */
void Compras::setNcompras()
{
    QSqlQuery query;
    query.prepare("select MAX(idCompra) from Compra");
    if(query.exec())
    {
        query.first();
        int maxid=query.value(0).toInt();
        maxid++;
        this->Ncompra->setText(QString::number(maxid));

    }
    else
    {
        this->Ncompra->setText("1");
    }
    ui->tableWidget->setColumnWidth(0,200);
    ui->tableWidget->setColumnWidth(1,400);
    ui->tableWidget->setColumnWidth(4,150);
    ui->tableWidget->setColumnWidth(5,150);
    ui->tableWidget->setFixedWidth(1150);
    ui->tableWidget->setFixedHeight(400);
    //ui->tableWidget->adjustSize();
    ui->tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
}

/**
 * @brief Compras::on_Revisar_pressed: Revisa una compra echa con anterioridad
 */
void Compras::on_Revisar_pressed()
{
    ui->tableWidget->clearContents();
    int nCompra = Ncompra->text().toInt();
    int i=0;
    bool flag=true;
    QSqlQuery query;
    query.prepare("select * from Compra where [idCompra] = :nCompra");
    query.bindValue(":nCompra",nCompra);
    if(!query.exec()){
    }
    else{
        query.first();
        if(query.isValid()){
            while(flag){
                ui->tableWidget->setItem(i,0,(new QTableWidgetItem(query.value(0).toString())));
                ui->tableWidget->setItem(i,1,(new QTableWidgetItem(query.value(1).toString())));
                ui->tableWidget->setItem(i,3,(new QTableWidgetItem(query.value(2).toString())));
                ui->tableWidget->setItem(i,4,(new QTableWidgetItem(query.value(3).toString())));
                nProveedor->setText(query.value(7).toStringList().at(0));
                rutProveedor->setText(query.value(8).toStringList().at(0));
                fecha->setDate(QDate::fromString(query.value(9).toString(),"dd-MM-yyyy"));
                fact->setText(query.value(4).toString());
                Ncompra->setText(query.value(6).toString());
                if(!query.next())
                {
                    flag=false;
                }
                i++;
            }
        }
        else{
            ui->tableWidget->clearContents();
            nProveedor->clear();
            rutProveedor->clear();
            fecha->setDate(QDate::currentDate());
            fact->clear();
            QMessageBox msgBox;
            msgBox.setWindowTitle("Error");
            msgBox.setText("Numero de Compra Inexistente.");
            msgBox.exec();
        }
    }

}

