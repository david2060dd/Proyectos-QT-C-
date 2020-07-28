#include "principal.h"
#include "ui_principal.h"
#include"aggproducts.h"

#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>


Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    inicializarDatos();
    m_subtotal = 0;
}

Principal::~Principal()
{
    delete ui;
}

void Principal::mostrarPrecio(int index)
{
    // OBTENER EL PRECIO DEL PRODUCTO A LA LISTA
    float precio = m_productos.at(index)->precio();
    // COLOCAR EL PRECIO EN LA ETIQUETA CORRESPONDIENTE
    ui->outPrecio->setText("$" + QString::number(precio));
}

void Principal::agregarProducto()
{
    // OBTENIENDO DATOS DESDE LA INTEFAZ
    int index = ui->inProducto->currentIndex();
    Producto *p = m_productos.at(index);
    int cantidad = ui->inCantidad->value();

    if(cantidad == 0){
        return;
    }

    // CALCULAR SUBTOTAL
   float subtotal = cantidad * p->precio();
   // BUSCAR Y ACTUALIZAR PRODUCTOS REPETIDOS
   if(!buscar(p, cantidad)){

    // AGREGAR DATOS A LA TABLA
    int posicion = ui->outDetalle->rowCount();
    ui->outDetalle->insertRow(posicion);
    ui->outDetalle->setItem(posicion,0,new QTableWidgetItem(QString::number(cantidad)));
    ui->outDetalle->setItem(posicion,1,new QTableWidgetItem(p->nombre()));
    ui->outDetalle->setItem(posicion,2,new QTableWidgetItem(QString::number(subtotal)));
   }

    // LIMPIAR DATOS
    ui->inCantidad->setValue(0);
    ui->inProducto->setFocus();

    // CALCULAR VALORES Y MOSTRAR
    calcular(subtotal);
}

void Principal::inicializarDatos()
{
    // ABRIR ARCHIVOS DE PRODUCTOS
    QFile archivo("productos.csv");
    // LEER EL ARCHIVO DE PRODUCTOS
    if(archivo.open(QFile::ReadOnly)){
        QTextStream in(&archivo);
        while (!in.atEnd()){
           QString linea = in.readLine();
           // SEPARAR DATOS POR ';'
           QStringList datos = linea.split(';');
           int codigo = datos[0].toInt();
           float precio = datos[2].toFloat();
           // CREAR PRODUCTOS
           m_productos.append(new Producto(codigo,datos[1],precio));

           //qDebug()<<codigo<<precio;
        }
    }else{
        qDebug()<<"Error al abrir el archivo";
    }
    archivo.close();

    // CREAR Y AGREGAR PRODUCTOS A LA LISTA
    //Producto p(1,"Leche",0.75);
    /*m_productos.append(new Producto(1,"Leche",0.75));
    m_productos.append(new Producto(2,"Pan",0.15));
    m_productos.append(new Producto(3,"Queso",2.50));*/
    // INVOCAR AL METODO PARA INICIALIZAR LOS WIDGETS
    inicializarWidgets();
}

void Principal::inicializarWidgets()
{
    // AGREGAR NOMBRES DE LOS PRODUCTORS AL COMBO BOX
    for (int i = 0; i < m_productos.length(); ++i) {
       ui->inProducto->addItem(m_productos.at(i)->nombre());
    }
    // COLOCAR CABEZERA EN LA TABLA
    QStringList cabecera = {"Cantidad", "Producto", "Sub-Total"};
    ui->outDetalle->setColumnCount(3);
    ui->outDetalle->setHorizontalHeaderLabels(cabecera);
    // EVENTOS

   connect(ui->inProducto, SIGNAL(currentIndexChanged(int)), this, SLOT(mostrarPrecio(int)));
   connect(ui->cmdAgregar, SIGNAL(clicked(bool)), this, SLOT(agregarProducto()));
   connect(ui->inCedula, SIGNAL(editingFinished()), this, SLOT(validarCedula()));
   connect(ui->pushButton, SIGNAL(clicked(bool)),this, SLOT(dat()));
   connect(ui->pushButton, SIGNAL(clicked(bool)),this, SLOT(factura()));
   connect(ui->pushButton, SIGNAL(clicked(bool)),this, SLOT(limpiar()));
   // MOSTRAR PRECIO DEL PRIMER PRODUCTO
   mostrarPrecio(0);
}

void Principal::calcular(float subtotal)
{
    m_subtotal += subtotal;
    float iva = m_subtotal * 0.12;
    float total = m_subtotal + iva;

    ui->outSubtotal->setText(QString::number(m_subtotal));
    ui->outIva->setText(QString::number(iva));
    ui->outTotal->setText(QString::number(total));
}

bool Principal::buscar(Producto *producto, int cantidad)
{
    // RECORRER EL NUMERO DE FILAS
    int numfilas = ui->outDetalle->rowCount();
    // RECORRER LA TABLA
    for (int i = 0; i < numfilas; ++i) {
        // OBTENER EL ITEM EN LA FILA Y LA COLUMNA 1(NOMBRE DEL PRODUCTO)
       QTableWidgetItem *item = ui->outDetalle->item(i,1);
       QString dato = item->data(Qt::DisplayRole).toString();
        // COMPARAR EL PRODUCTO
       if(dato == producto->nombre()){
           // OBTENER LA CANTIDAD DEL PRODUCTO QUE YA ESTA EN EL DETALLE
           QTableWidgetItem *item = ui->outDetalle->item(i,0);
           int cantidadActual = item->data(Qt::DisplayRole).toInt();
           // SUMAR LA CANTIDAD
           int cantidadNueva = cantidadActual + cantidad;
           // CALCULAR NUEVA SUB-TOTAL
           float subtotal = cantidadNueva * producto->precio();
           // ACTUALIZAR EN LA TABLA
           ui->outDetalle->setItem(i,0,new QTableWidgetItem(QString::number(cantidadNueva)));
           ui->outDetalle->setItem(i,2,new QTableWidgetItem(QString::number(subtotal)));

           //qDebug()<<"Producto Repetido";
           return true;
       }
    }
    return false;
}

void Principal::validarCedula()
{
    int ced,par,imp,total,dec=0;
    int vala,valb,valc,vald,vale,valf,valg,valh,vali,valj;
    ced  = ui->inCedula->text().toInt();
    vala=ced/1000000000;
        ced=ced-(vala*1000000000);
        valb=ced/100000000;
        ced=ced-(valb*100000000);
        valc=ced/10000000;
        ced=ced-(valc*10000000);
        vald=ced/1000000;
        ced=ced-(vald*1000000);
        vale=ced/100000;
        ced=ced-(vale*100000);
        valf=ced/10000;
        ced=ced-(valf*10000);
        valg=ced/1000;
        ced=ced-(valg*1000);
        valh=ced/100;
        ced=ced-(valh*100);
        vali=ced/10;
        ced=ced-(vali*10);
        valj=ced/1;
        ced=ced-(valj*1);

        if (ced>2400000000){
                ui->inCedula->setStyleSheet("color : green");
            }else{
                par=valb+vald+valf+valh;
                vala=vala*2;
                if (vala>9){
                    vala=vala%10+vala/10;
                }
                valc=valc*2;
                if (valc>9){
                    valc=valc%10+valc/10;
                }
                vale=vale*2;
                if (vale>9){
                    vale=vale%10+vale/10;
                }
                valg=valg*2;
                if (valg>9){
                    valg=valg%10+valg/10;
                }
                vali=vali*2;
                if (vali>9){
                    vali=vali%10+vali/10;
                }
                imp=vala+valc+vale+valg+vali;
                total=par+imp;
                while (dec-total!=valj && dec<total+10){
                    dec=dec+10;
                }
                if (dec-total==valj){
                    ui->inCedula->setStyleSheet("color : green");
                }else {
                    ui->inCedula->setStyleSheet("color : red");
                }
            }

}

void Principal::factura()
{
    QString name=ui->inNombre->text();
    QString phonenumber=ui->inTelefono->text();
    QString coel=ui->inEmail->text();
    QString cdl=ui->inCedula->text();
    QString direc=ui->inDireccion->toPlainText();
    QString subT=ui->outSubtotal->text();
    QString iva= ui->outIva->text();
    QString totalC=ui->outTotal->text();





    if(name=="" || phonenumber=="" || coel=="" || cdl==""){
        return;
    }else {

        fact *dlgRecibo= new fact;
        QString imprimir= "Nombre: " + name + "\n";
        imprimir += "Cedula: " + cdl + "\n";
        imprimir += "Telefono: " + phonenumber + "\n";
        imprimir += "Correo: " + coel + "\n";
        imprimir += "Direccion: "+ direc +"\n";
        imprimir += "Subtotal: $"+ subT +"\n";
        imprimir += "Iva: "+ iva +"\n";
        imprimir += "Total a pagar: $"+ totalC +"\n";


        //Plantear Recibo en una ventana
        dlgRecibo->setfact(imprimir);
        dlgRecibo->show();
}
    limpiar();
}

void Principal::dat()
{
    QString name=ui->inNombre->text();
    QString tlf=ui->inTelefono->text();
    QString ce=ui->inEmail->text();
    QString ced=ui->inCedula->text();
    if(name==""){
        ui->inNombre->setStyleSheet("background-color: red");

    }else{
        ui->inNombre->setStyleSheet("background-color: green");
    }
    if(tlf==""){
        ui->inTelefono->setStyleSheet("background-color: red");
    }else{
        ui->inTelefono->setStyleSheet("background-color: green");
    }
    if(ce==""){
        ui->inEmail->setStyleSheet("background-color: red");
    }else{
        ui->inEmail->setStyleSheet("background-color: green");
    }
    if(ced==""){
        ui->inCedula->setStyleSheet("background-color: red");
    }else{
        ui->inCedula->setStyleSheet("background-color: green");

    }
    if(name=="" || tlf=="" || ce=="" || ced==""){
        QMessageBox vacio;
        vacio.setText("Los datos ingresados son incorrectos porfavor verifique!!");
        vacio.exec();

    }

}

void Principal::limpiar()
{
    ui->inNombre->setText("");
    ui->inTelefono->setText("");
    ui->inEmail->setText("");
    ui->inCedula->setText("");
    ui->inDireccion->setPlainText("");
    ui->outDetalle->clear();
    ui->outIva->clear();
    ui->outTotal->clear();
    ui->outSubtotal->clear();

}


void Principal::on_actionAgregar_productos_triggered()
{
    aggproducts *agg=new aggproducts;

    agg->show();
    //agg->setVisible(true);
    //agg->hide();
    //agg->setVisible(false);


}

void Principal::on_actionAcerca_de_triggered()
{
    QMessageBox::information(this,"acerca de","TiendaDeMichita\n Autor: David Vargas\n Creado el domi.,19 de jul del 2020 \n QT 4.12.2\n Mi github:https://github.com/david2060dd \n Copyright 2008-2020 Compufuture.inc All rights reserve");

}
