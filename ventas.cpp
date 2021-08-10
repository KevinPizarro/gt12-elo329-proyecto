#include "ventas.h"
#include "ui_ventas.h"

/**
 * @brief Ventas::Ventas: Constructor de la clase, inicializa sus atributos.
 * @param parent: Ventana principal a la cual pertenece.
 */
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
    this->total = ui->Total;
    this->totalci = ui->TotalCI;
    this->iva = ui->Iva;
    this->tabla = ui->tableWidget;
    connect(ui->tableWidget,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(getItem(QTableWidgetItem*)));
}

/**
 * @brief Ventas::~Ventas: Destructor de la clase
 */
Ventas::~Ventas()
{
    delete ui;
}

/**
 * @brief Ventas::closeEvent: Metodo que maneja el cierre de la ventana, escondiendola en vez de destruirla.
 * @param event: Evento detectado como cierre de la ventana.
 */
void Ventas::closeEvent (QCloseEvent *event){
    event->ignore();
    this->hide();
}

/**
 * @brief Ventas::getItem: Metodo que selecciona un item o producto en particular de la base de datos.
 * @param item: Item o producto a buscar en la base de datos.
 */
void Ventas::getItem(QTableWidgetItem *item){
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
            if(query.value(6) == 1){
                ui->tableWidget->setItem(row,4,new QTableWidgetItem(query.value(5).toString()));
                ui->tableWidget->item(row,4)->setFlags(ui->tableWidget->item(row,4)->flags() & ~Qt::ItemIsEditable);
            }
            else{
                ui->tableWidget->setItem(row,4,new QTableWidgetItem(query.value(4).toString()));
                ui->tableWidget->item(row,4)->setFlags(ui->tableWidget->item(row,4)->flags() & ~Qt::ItemIsEditable);
            }
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
        if(ui->tableWidget->item(row,0)){
            int cant=ui->tableWidget->item(row,3)->text().toInt();
            int saldo = ui->tableWidget->item(row,2)->text().toInt();
            int cod = item->text().toInt();
            QSqlQuery query;
            query.prepare("select * from Producto where Codigo = :codigo");
            query.bindValue(":codigo",cod);
            if(!query.exec()){
            }
            query.first();
            if(query.isValid()){
                if(cant > saldo){
                    QMessageBox msgBox;
                    msgBox.setWindowTitle("Error");
                    msgBox.setText("No puede vender mas unidades de las existentes.");
                    msgBox.exec();
                    ui->tableWidget->item(row,3)->setText(QString::number(saldo));
                }
                cant=ui->tableWidget->item(row,3)->text().toInt();
                float precio=ui->tableWidget->item(row,4)->text().toFloat();
                float t=precio*cant;
                ui->tableWidget->setItem(row,5,new QTableWidgetItem(QString::number(t)));
                float tci = 0;
                for(int i = 0; i < 100; i++){
                    QTableWidgetItem *item(ui->tableWidget->item(i,5));
                    if(item){
                        tci += ui->tableWidget->item(i,5)->text().toFloat();
                    }
                }
                total->setText(QString::number(tci/1.19));
                iva->setText(QString::number((tci/1.19)*0.19));
                totalci->setText(QString::number(tci));
            }
        }
    }

}

/**
 * @brief Ventas::on_Guardar_pressed: Metodo que guarda o actualiza el producto ingresado con sus respectivos atributos.
 */
void Ventas::on_Guardar_pressed()
{
    bool flag=true;
    int i=0;
    QSqlQuery query,query3;
    while(flag){
        QString codigo=ui->tableWidget->item(i,0)->text();
        QString nombre=ui->tableWidget->item(i,1)->text();
        QString Cantidad=ui->tableWidget->item(i,3)->text();
        QString precio=ui->tableWidget->item(i,4)->text();
        QString total=ui->tableWidget->item(i,5)->text();
        QString idVenta=Nventa->text();
        QString date=fecha->text();
        QString Pago = pago->currentText();
        query.prepare("insert into Venta values (:idVenta, :total, :date, :nombre, :cantidad, :precio, :codigo, :pago)");
        query.bindValue(":idVenta",idVenta);
        query.bindValue(":total",total);
        query.bindValue(":date",date);
        query.bindValue(":nombre",nombre);
        query.bindValue(":cantidad",Cantidad);
        query.bindValue(":precio",precio);
        query.bindValue(":codigo",codigo);
        query.bindValue(":pago",Pago);
        if(query.exec()){
        }
        int nSaldo=(ui->tableWidget->item(i,2)->text().toInt()-Cantidad.toInt());
        query3.prepare("update Producto SET [Saldo] = :saldo where codigo = :codigo");
        query3.bindValue(":saldo",nSaldo);
        query3.bindValue(":codigo",codigo);
        if(query3.exec()){
        }
        i++;
        if(tabla->item(i,0)){
            flag=true;
        }
        else{
            flag=false;
        }
    }
    pago->setCurrentIndex(0);
    ui->tableWidget->clearContents();
    fecha->setDate(QDate::currentDate());
    setNventas();
}

/**
 * @brief Ventas::setNventas: Setea el numero de venta.
 */
void Ventas::setNventas(){
    QSqlQuery query;
    query.prepare("select MAX(idVenta) from Venta");
    if(query.exec()){
        query.first();
        int maxid=query.value(0).toInt();
        maxid++;
        this->Nventa->setText(QString::number(maxid));

    }
    else
    {
        this->Nventa->setText("1");
    }
    total->setText("0");
    iva->setText("0");
    totalci->setText("0");
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
 * @brief Ventas::on_Revisar_pressed: Metodo que nos permite revisar una venta pasada.
 */
void Ventas::on_Revisar_pressed(){
    ui->tableWidget->clearContents();
    int nVenta = Nventa->text().toInt();
    int i=0;
    bool flag=true;
    QSqlQuery query;
    query.prepare("select * from Venta where [idVenta] = :nVenta");
    query.bindValue(":nVenta",nVenta);
    if(!query.exec()){
    }
    else{
        query.first();
        if(query.isValid()){
            while(flag){
                ui->tableWidget->setItem(i,0,(new QTableWidgetItem(query.value(6).toString())));
                ui->tableWidget->setItem(i,1,(new QTableWidgetItem(query.value(3).toString())));
                ui->tableWidget->setItem(i,3,(new QTableWidgetItem(query.value(4).toString())));
                ui->tableWidget->setItem(i,4,(new QTableWidgetItem(query.value(5).toString())));
                ui->tableWidget->setItem(i,5,(new QTableWidgetItem(query.value(1).toString())));
                fecha->setDate(QDate::fromString(query.value(2).toString(),"dd/MM/yyyy"));
                Nventa->setText(query.value(0).toString());
                if(query.value(7) == "Efectivo"){
                    pago->setCurrentIndex(0);
                }
                else if(query.value(7) == "Débito"){
                    pago->setCurrentIndex(1);
                }
                else if(query.value(7) == "Crédito"){
                    pago->setCurrentIndex(2);
                }
                if(!query.next())
                {
                    flag=false;
                }
                i++;
            }
            float tci = 0;
            for(int i = 0; i < 100; i++){
                QTableWidgetItem *item(ui->tableWidget->item(i,5));
                if(item){
                    tci += ui->tableWidget->item(i,5)->text().toFloat();
                }
            }
            total->setText(QString::number(tci/1.19));
            iva->setText(QString::number((tci/1.19)*0.19));
            totalci->setText(QString::number(tci));
        }
        else{
            ui->tableWidget->clearContents();
            pago->setCurrentIndex(0);
            fecha->setDate(QDate::currentDate());
            QMessageBox msgBox;
            msgBox.setWindowTitle("Error");
            msgBox.setText("Numero de Venta Inexistente.");
            msgBox.exec();
        }
    }

}

