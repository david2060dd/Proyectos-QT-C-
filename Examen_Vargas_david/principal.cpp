#include "principal.h"
#include "ui_principal.h"
#include <QTableWidget>
#include<QDate>
#include <QFileDialog>
#include<QMessageBox>

#include <QDebug>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{

    ui->setupUi(this);
    connect(ui->PBlistar, SIGNAL(released()),this,SLOT(registra()));
    connect(ui->actionSalir,SIGNAL(triggered(bool)),this, SLOT(close()));


    inicializarDatos();

}

Principal::~Principal()
{

}




void Principal::inicializarDatos()
{

    m_tipo.append(new Tipo(1,"Estudiantil"));
    m_tipo.append(new Tipo(2,"personal"));
    m_tipo.append(new Tipo(3,"Hogar"));
    m_tipo.append(new Tipo(4,"entretenimiento personal"));
    m_tipo.append(new Tipo(5,"culinario"));
    inicializarWidgets();
}

void Principal::inicializarWidgets()
{

    for (int i = 0; i < m_tipo.length(); ++i) {
        ui->inProducto->addItem(m_tipo.at(i)->nombre());

        QStringList cabecera = {"nombre", "Fecha-Hora limite", "Prioridad", "tipo"};
        ui->outDetalle->setColumnCount(4);
        ui->outDetalle->setHorizontalHeaderLabels(cabecera);



    }


}

void Principal::registra()

{
    QString prioridad;


    if (ui->inalta->isChecked()){

        prioridad = "Prioridad alta";
    }else if (ui->inmedia->isChecked()){
        prioridad ="Prioridad media";
    }else{
        prioridad= "Prioridad baja";
}
    QDate fecha=ui->infecha->date();
    QString nombredeact=ui->innombre->text();
    int index=ui->inProducto->currentIndex();
    Tipo *i=m_tipo.at(index);
    int posicion = ui->outDetalle->rowCount();
    ui->outDetalle->insertRow(posicion);

    ui->outDetalle->setItem(posicion,3,new QTableWidgetItem(i->nombre()));
    ui->outDetalle->setItem(posicion,0,new QTableWidgetItem(QString(nombredeact)));
    ui->outDetalle->setItem(posicion,2,new QTableWidgetItem(QString(prioridad)));
    ui->outDetalle->setItem(posicion,1,new QTableWidgetItem(fecha.toString()));
}

void Principal::limp()
{
    ui->innombre->setText("");
    ui->inalta->setChecked(true);

    ui->infecha->clear();
}
void Principal::on_PBlistar_clicked()
{
 //C:\Users\david\Documents\Prueba-Final
  QString fileName=("C:\\Users\\david\\Documents\\Prueba-Final\\registro.txt");
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

limp();
}

void Principal::on_actionAcerca_de_triggered()
{
 QMessageBox::information(this,"acerca de","Fast Work\n Autor: David Vargas\n Creado el Lun.,27 de jul del 2020 \n QT 4.12.2\n Mi github:https://github.com/david2060dd \n Copyright 2008-2020 Compufuture.inc All rights reserve");
}

void Principal::on_infinalizar_triggered()
{
    //Finalizo la tarea y elimina de la tabla
    int quit = ui->outDetalle->currentRow();
    ui->outDetalle->removeRow(quit);
}
