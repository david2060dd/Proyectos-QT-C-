#include "principal.h"
#include "ui_principal.h"
#include "QFile"
#include "QTextStream"
#include <QFileDialog>
#include "QMessageBox"


#include <QDebug>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    connect(ui->cmdAgregar, SIGNAL(released()),this,SLOT(registrar()));
    inicializarDatosmIp();
    //connect(ui->actionGuardar, SIGNAL(triggered(bool)),
            //this, SLOT(guardar()));

}

Principal::~Principal()
{
    delete ui;
}
//precio de las impresoras
void Principal::precioImpre(int index)
{
float precio = m_impresoras.at(index)->precio();
ui->outPrecio->setText("$"+QString::number(precio));
}

void Principal::registrar()
{
    QString model=ui->inModelo->text();
    int count=ui->inContador->value();
    QString Color = "";

    if (ui->inColor->isChecked()){
        Color ="color";
    }else{
       Color ="N Y N";
    }
    int index=ui->inMarca->currentIndex();
    Impresora *i=m_impresoras.at(index);
    //int Contador=ui->inContador->value();
    int posicion = ui->outDetalle->rowCount();
    ui->outDetalle->insertRow(posicion);
    ui->outDetalle->setItem(posicion,0,new QTableWidgetItem(i->nombre()));
    ui->outDetalle->setItem(posicion,1,new QTableWidgetItem(QString::number(i->codigo())));
    ui->outDetalle->setItem(posicion,2,new QTableWidgetItem(QString(model)));
    ui->outDetalle->setItem(posicion,3,new QTableWidgetItem(QString(Color)));
    ui->outDetalle->setItem(posicion,4,new QTableWidgetItem(QString::number(count)));
    ui->outDetalle->setItem(posicion,5,new QTableWidgetItem(QString::number(i->precio())));
    clean();


}

void Principal::clean()
{
    ui->inModelo->setText("");

    ui->inBN->setChecked(true);
    ui->inContador->setValue(0);

}




void Principal::inicializarDatosmIp()
{
    //agregar impresoras a la lista(para agregar mas solo se copia y pega lo mismo y se cambian los adtos)
  m_impresoras.append(new Impresora(1324565,"Epson",800));
  m_impresoras.append(new Impresora(9470436,"Canon",500));
  m_impresoras.append(new Impresora(9735524,"Hp",350));
  m_impresoras.append(new Impresora(9008454,"Brother",400));
   mostrarImpresoras();

}

//colocar los datos de las impresoras en el combobox :D
void Principal::mostrarImpresoras()
{
 for (int i=0; i<m_impresoras.length();++i){
     ui->inMarca->addItem(m_impresoras.at(i)->nombre());

 }
 QStringList cabeza={"Marca","N. de serie","modelo","C/BN","C. impresiones","Precio"};
 ui->outDetalle->setColumnCount(6);
 ui->outDetalle->setHorizontalHeaderLabels(cabeza);

 connect(ui->inMarca, SIGNAL(currentIndexChanged(int)), this, SLOT(precioImpre(int)));
 precioImpre(0);
}








void Principal::on_actionAcerca_de_triggered()
{
    QMessageBox::information(this,"acerca de","RegPrint\n Autor: David Vargas\n Creado el jue.,7 de jul del 2020 \n QT 4.12.2 \n Copyright 2008-2020 Compufuture.inc All rights reserve");

}

void Principal::on_actionGuardar_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    "Guardar datos", QDir::home().absolutePath() , "Archivo de Texto (*.txt)");
    QFile data(fileName);
    if (data.open(QFile::WriteOnly | QFile::Truncate))
    {
        QTextStream salida(&data);
        QStringList Lista;
        for( int columna = 0; columna < ui->outDetalle->columnCount(); ++columna ){
            Lista << "\" " + ui->outDetalle->horizontalHeaderItem(columna)->data(Qt::DisplayRole).toString() + "\" ";
        }
        salida << Lista.join(";") << "\n";
        for( int fila = 0; fila < ui->outDetalle->rowCount(); ++fila)
        {
            Lista.clear();
            for( int columna = 0; columna < ui->outDetalle->columnCount(); ++columna){
                QTableWidgetItem* item = ui->outDetalle->item(fila,columna);
                if (!item || item->text().isEmpty()){
                    ui->outDetalle->setItem(fila,columna,new QTableWidgetItem("0"));
                }
                Lista << "\" "+ui->outDetalle->item( fila, columna )->text()+"\" ";
            }
            salida<< Lista.join( ";" )+"\n";
        }
        ui->statusbar->showMessage("Datos almacenados en: " + fileName, 5000);
        data.close();
    }
}
