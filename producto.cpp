#include "producto.h"
#include "ui_producto.h"

/**
 * @brief Producto::Producto: Constructor de la clase, inicializa sus atributos.
 * @param parent: Ventana principal a la cual pertenece.
 */
Producto::Producto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Producto){
    ui->setupUi(this);
    this->Ofcheck = ui->Ofertacheck;
    this->borrar = ui->Eliminar;
    this->guardar = ui->Guardar;
    this->prov = ui->Proovedor;
    this->neto = ui->Precneto;
    this->total = ui->PrecIva;
    this->oferta = ui->PrecOferta;
    this->desc = ui->Descripcion;
    this->saldo = ui->Saldo;
    this->codigo = ui->Codigo;
    this->ganancia = ui->ganancia;
    this->oflag = false;
    connect(this->Ofcheck,SIGNAL(stateChanged(int)),this,SLOT(change_enabled_oferta()));
    connect(codigo,SIGNAL(editingFinished()),this,SLOT(getItem()));
    connect(total,SIGNAL(editingFinished()),this,SLOT(calcgan()));
    connect(neto,SIGNAL(editingFinished()),this,SLOT(calcprec()));
    connect(ganancia,SIGNAL(editingFinished()),this,SLOT(calcprec()));
}

/**
 * @brief Producto::~Producto: Destructor de la clase.
 */
Producto::~Producto()
{
    delete ui;
}

/**
 * @brief Producto::closeEvent: Metodo que maneja el cierre de la ventana, escondiendola en vez de destruirla.
 * @param event: Evento detectado como cierre de la ventana.
 */
void Producto::closeEvent (QCloseEvent *event){
    event->ignore();
    this->hide();
}

/**
 * @brief Producto::change_enabled_oferta: Metodo que determina si existe un precio de oferta en el producto.
 */
void Producto::change_enabled_oferta(){
    if(this->oflag){
        this->oflag = false;
    }
    else{
        this->oflag = true;
    }
    this->oferta->setEnabled(oflag);
}

/**
 * @brief Producto::on_Guardar_clicked: Metodo que guarda o actualiza el producto ingresado con sus respectivos atributos.
 */
void Producto::on_Guardar_clicked(){
    QSqlQuery query,query2,query3;
    QString c = QString::number(codigo->text().toInt());
    QString d = desc->text();
    QString n = neto->text();
    QString g = ganancia->text();
    QString t = total->text();
    QString s = saldo->text();
    QString p = prov->text();
    QString o = oferta->text();
    QString oc = QString::number(Ofcheck->isChecked());
    query2.prepare("select Nombre from Producto where Codigo = :c");
    query2.bindValue(":c",c);
    if(query2.exec()){
    }
    query2.first();
    if(query2.isValid()){
        query3.prepare("update Producto SET [Nombre] = :nombre, [Saldo] = :saldo, [Precio] = :precio, [PrecioCI] = :precioCI, [POferta] = :pOferta, [COferta] = :cOferta, [Proveedor] = :proveedor, [PGanancia] = :pGanancia where Codigo = :codigo");
        query3.bindValue(":codigo",c);
        query3.bindValue(":nombre",d);
        query3.bindValue(":saldo",s);
        query3.bindValue(":precio",n);
        query3.bindValue(":precioCI",t);
        query3.bindValue(":pOferta",o);
        query3.bindValue(":cOferta",oc);
        query3.bindValue(":proveedor",p);
        query3.bindValue(":pGanancia",g);
        if(query3.exec()){
        }
    }
    else{
        query.prepare("insert into Producto values ( :codigo , :nombre , :saldo, :precio, :precioCI, :pOferta, :cOferta, :proveedor, :pGanancia)");
        query.bindValue(":codigo",c);
        query.bindValue(":nombre",d);
        query.bindValue(":saldo",0);
        query.bindValue(":precio",n);
        query.bindValue(":precioCI",t);
        query.bindValue(":pOferta",o);
        query.bindValue(":cOferta",oc);
        query.bindValue(":proveedor",p);
        query.bindValue(":pGanancia",g);
        if(query.exec()){
        }
    }
    codigo->clear();
    desc->clear();
    neto->clear();
    ganancia->clear();
    total->clear();
    saldo->clear();
    prov->clear();
    oferta->clear();
    Ofcheck->setChecked(false);
}

/**
 * @brief Producto::on_Eliminar_clicked: Metodo que elimina un producto en particular de la base de datos.
 */
void Producto::on_Eliminar_clicked(){
    int cod = codigo->text().toInt();
    QSqlQuery query;
    query.prepare("select * from Producto where Codigo = :codigo");
    query.bindValue(":codigo",cod);
    if(query.exec()){
    }
    query.first();
    if(query.isValid()){
        QSqlQuery query2;
        query2.prepare("delete from Producto where Codigo = :codigo");
        query2.bindValue(":codigo",cod);
        if(query2.exec()){
        }
        codigo->clear();
        desc->clear();
        neto->clear();
        ganancia->clear();
        total->clear();
        saldo->clear();
        prov->clear();
        oferta->clear();
        Ofcheck->setChecked(false);
    }
    else{
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error");
        msgBox.setText("Numero de Compra Inexistente.");
        msgBox.exec();
        codigo->clear();
        desc->clear();
        neto->clear();
        ganancia->clear();
        total->clear();
        saldo->clear();
        prov->clear();
        oferta->clear();
        Ofcheck->setChecked(false);
    }

}

/**
 * @brief Producto::getItem: Metodo que selecciona un item o producto en particular de la base de datos.
 */
void Producto::getItem(){
        int cod = codigo->text().toInt();
        QSqlQuery query;
        query.prepare("select * from Producto where Codigo = :codigo");
        query.bindValue(":codigo",cod);
        if(query.exec()){
        }
        query.first();
        if(query.isValid()){
            desc->setText(query.value(1).toString());
            saldo->setText(query.value(2).toString());
            neto->setText(query.value(3).toString());
            total->setText(query.value(4).toString());
            oferta->setText(query.value(5).toString());
            if(query.value(6) == 1){
                Ofcheck->setChecked(true);
            }
            else{
                Ofcheck->setChecked(false);
            }
            prov->setText(query.value(7).toString());
            ganancia->setText(query.value(8).toString());
        }
        else{
            desc->clear();
            neto->clear();
            ganancia->clear();
            total->clear();
            saldo->clear();
            prov->clear();
            oferta->clear();
            Ofcheck->setChecked(false);
        }
}

/**
 * @brief Producto::calcprec: Metodo que permite calcular el precio de venta segun la ganancia que se desee.
 */
void Producto::calcprec(){
    float prec = neto->text().toFloat();
    float g = ganancia->text().toFloat();
    prec = (prec + prec * (g/100)) * 1.19;
    total->setText(QString::number(prec));
}

/**
 * @brief Producto::calcgan: Metodo que permite calcular la ganancia segun el precio con iva y el neto.
 */
void Producto::calcgan(){
    float civa = total->text().toFloat();
    float n = neto->text().toFloat();
    float g = ((civa/(n*1.19)) - 1)*100;
    ganancia->setText(QString::number(g));
}
