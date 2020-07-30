#include "principal.h"
#include "ui_principal.h"

#include <QPainter>
#include <QPaintEvent>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    lienzo= QPixmap(500,500);
    lienzo.fill(Qt::white);

    this->dibujar();

}

Principal::~Principal()
{
    delete ui;
}

void Principal::dibujar()
{


    QPainter painter(&lienzo);

    QPen pincel;
    //int n1=ui->inNota1->value();
    int x=0;
    int y=0;



    pincel.setWidth(5);
    pincel.setColor(Qt::red);
    pincel.setJoinStyle(Qt::MiterJoin);

    // Establecer el pincel al "pintor"
    painter.setPen(pincel);




    //painter.drawRect(x+50, y+50,100,400);


    QColor colorRelleno(190,120,162);

    QColor colorBorde(78,3,48);


    pincel.setColor(colorBorde);


    painter.setPen(pincel);


    painter.setBrush(colorRelleno);


    //painter.drawRect(x+170, y+200, 100, 250);


    QColor cRellenoBarra3(253, 253, 115);
    QColor cBordeBarra3(174, 174, 51);

    pincel.setColor(cBordeBarra3);
    painter.setPen(pincel);
    painter.setBrush(cRellenoBarra3);




    //painter.drawRect(x+290,y+350,100,100);

    y=50;
    x=20;

    int num=200;
    for(int i=y;i<450;i+=50){

        painter.drawLine(x-5,i,x-5,i);
        QString linea=
        QString::number(num);
        num-=25;
        painter.drawText(x-20,i,linea);


    }
    painter.drawLine(x,y-30,x,y+400);
    //
    for(int u=x;u<450;u+=130){
        painter.drawLine(u,y+405,u,y+405);
        painter.drawText(80,465,"Nota 1");
        painter.drawText(200,465,"Nota 2");
        painter.drawText(320,465,"Nota 3 ");



    }


painter.drawLine(x+5,y+400,x+400,y+400);
}


void Principal::on_actionGuardar_triggered()
{
    QString nombreArchivo = QFileDialog::getSaveFileName(
                this,"Guardar imagen",QString(),"Imagenes (*.png)");
    if (!nombreArchivo.isEmpty()){
        if (lienzo.save(nombreArchivo))
            QMessageBox::information(this,"Guardar imagen","Archivo guarado en: " + nombreArchivo);
        else
            QMessageBox::warning(this,"Guardar imagen","No se pudo guardar el archivo");
    }
}





void Principal::on_pushprom_clicked()
{
    QPainter painter(&lienzo);
    QPen pincel;
    int ntone=ui->barra1->value();
    int nttwo=ui->barra2->value();
    int nttree=ui->barra3->value();

    int x=0;


    pincel.setWidth(5);
    pincel.setJoinStyle(Qt::MiterJoin);
    QColor BB1(249,142,0);
    QColor RB1(249,166,0);


    pincel.setColor(BB1);
    painter.setBrush(RB1);

    painter.setPen(pincel);


    painter.drawRect(x+50, 450-ntone*2, 100,ntone*1.95);


    QColor RB2( 35,106,98);
    QColor BB2( 36,96,104);
    pincel.setColor(BB2);
    painter.setPen(pincel);
    painter.setBrush(RB2);


    painter.drawRect(x+170, 450-nttwo*2, 100,nttwo*1.95);


    QColor BB3(168,56,59);
    QColor RB3( 170,81,57);


    pincel.setColor(BB3);
    painter.setPen(pincel);
    painter.setBrush(RB3);


    painter.drawRect(x+290,450-nttree*2 ,100,nttree*1.95);
    update();
 int prom=ntone+nttwo+nttree/3;
 ui->inpromedio->setText(QString::number(prom));


}

void Principal::paintEvent(QPaintEvent *event)
{

        QPainter painter(this);

        painter.drawPixmap(20, 65, lienzo);


        event->accept();
}




void Principal::on_actionNuevo_triggered()
{
    lienzo.fill(Qt::white);
    dibujar();
    ui->barra1->setValue(0);
    ui->barra2->setValue(0);
    ui->barra3->setValue(0);
    ui->inpromedio->clear();
    update();
}


void Principal::on_actionAcerca_de_triggered()
{
    QMessageBox::information(this,"acerca de","Instant Bar\n Autor: David Vargas\n Creado el domi.,26 de jul del 2020 \n QT 4.12.2\n Mi github:https://github.com/david2060dd \n Copyright 2008-2020 Compufuture.inc All rights reserve");
}
