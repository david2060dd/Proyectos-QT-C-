#include "principal.h"
#include "ui_principal.h"

#include <QImage>
#include <QPainter>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QDebug>
#include <QInputDialog>
#include <QColorDialog>
#include <QFileDialog>
#include <QMessageBox>

#define DEFAULT_ANCHO 3

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);

    mImagen = new QImage(this->size(),QImage::Format_ARGB32_Premultiplied);
    mImagen->fill(Qt::white);
    mPainter = new QPainter(mImagen);
    mPainter->setRenderHint(QPainter::Antialiasing);
    mPuedeDibujar = false;
    mcl = Qt::black;
    mAn = DEFAULT_ANCHO;
    mNL = 0;

    mestilo = 2;
}

Principal::~Principal()
{
    delete ui;
    delete mPainter;
    delete mImagen;
}

void Principal::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);

    painter.drawImage(0, 0, *mImagen);

    event->accept();
}

void Principal::mousePressEvent(QMouseEvent *event)
{
    mPuedeDibujar = true;
    mstart = event->pos();
    event->accept();
}

void Principal::mouseMoveEvent(QMouseEvent *event)
{

    if(mestilo==2){
        mPuedeDibujar = false;
        mend = event->pos();
        QPen pincel;
        pincel.setColor(mcl);
        pincel.setWidth(mAn);
       mPainter->setPen(pincel);
        mPainter->drawLine(mstart,mend);

        ui->statusbar->showMessage("Número de lineas: "+QString::number(++mNL));
        update();
        mstart=mend;

    }


}

void Principal::mouseReleaseEvent(QMouseEvent *event)
{

      if(mestilo==1){
          mPuedeDibujar = false;

          mend = event->pos();

          QPen pincel;
          pincel.setColor(mcl);
          pincel.setWidth(mAn);
          mPainter->setPen(pincel);
          mPainter->drawLine(mstart,mend);
          ui->statusbar->showMessage("Número de lineas: "+QString::number(++mNL));

          update();

          event->accept();
      }

      if(mestilo==3){
          mPuedeDibujar = false;

          mend = event->pos();

          QPen pincel;
          pincel.setColor(mcl);
          pincel.setWidth(mAn);
          QRect rect(mstart,mend);

          mPainter->setPen(pincel);
          mPainter->drawRect(rect);

          ui->statusbar->showMessage("Número de lineas: "+QString::number(++mNL));

          update();

          event->accept();
      }

      if(mestilo==4){
          mPuedeDibujar = false;

          mend = event->pos();
          QPen pincel;
          pincel.setColor(mcl);
          pincel.setWidth(mAn);

          QRectF circunferencia(mstart,mend);

          mPainter->setPen(pincel);
          mPainter->drawEllipse(circunferencia);

          ui->statusbar->showMessage("Número de lineas: "+QString::number(++mNL));
          update();

          event->accept();
      }


}


void Principal::on_actionAncho_triggered()
{
    mAn = QInputDialog::getInt(this,"Ancho del pincel","Ingrese el ancho del pincel de dibujo",mAn,1, 100);
}

void Principal::on_actionSalir_triggered()
{
    QString nombreArchivo;

    if(mNL==0){
        this->close();
    }else{

        if(!mImagen->save(nombreArchivo)){
            QMessageBox mBox;
            mBox.setText("No se ha guardado la imagen.");
            mBox.addButton("Guardar", QMessageBox::AcceptRole);
            mBox.addButton(tr("Cancelar"), QMessageBox::RejectRole);
            mBox.addButton(tr("Salir "), QMessageBox::DestructiveRole);
            int valid = mBox.exec();
            switch (valid) {
            case QMessageBox::AcceptRole:
                on_actionGuardar_triggered();
                break;
            case QMessageBox::RejectRole:
                break;
            case QMessageBox::DestructiveRole:
                this->close();
                break;
            default:
                break;
            }

        }
    }

}

void Principal::on_actionColor_triggered()
{
   mcl = QColorDialog::getColor(mcl,
                                    this,
                                    "Color del pincel");
}

void Principal::on_actionNuevo_triggered()
{
    QString nombreArchivo;
    if(!mImagen->save(nombreArchivo)){
        QMessageBox mBox2;
        mBox2.setText("su plantilla no se ah guardado \n Que desea hacer ?");
        mBox2.addButton("Guardar", QMessageBox::AcceptRole);
        mBox2.addButton("Cancelar", QMessageBox::RejectRole);
        mBox2.addButton("Nuevo sin guardar", QMessageBox::DestructiveRole);
        int valid2 = mBox2.exec();
        switch (valid2) {
        case QMessageBox::AcceptRole:
            on_actionGuardar_triggered();
            break;
        case QMessageBox::RejectRole:
            break;
        case QMessageBox::DestructiveRole:
          mImagen->fill(Qt::white);
            break;
        default:
            break;
        }

    }

   mNL = 0;


    update();

}

void Principal::on_actionGuardar_triggered()
{
    QString nombreArchivo = QFileDialog::getSaveFileName(this,
                                                         "Guardar imagen",
                                                         QString(),
                                                         "Imágenes (*.png)");
    if ( !nombreArchivo.isEmpty() ){
        if (mImagen->save(nombreArchivo))
            QMessageBox::information(this,
                                     "Guardar imagen",
                                     "Archivo almacenado en: " + nombreArchivo);
        else
            QMessageBox::warning(this,
                                 "Guardar imagen",
                                 "No se pudo almacenar la imagen.");
    }
}

void Principal::on_actionLineas_triggered()
{
    ui->actionLibre->setCheckable(false);
    ui->actionRect_nculos->setCheckable(false);
    ui->actionCircunferencias->setCheckable(false);


    mestilo=1;
}

void Principal::on_actionLibre_triggered()
{
    ui->actionLineas->setCheckable(false);
    ui->actionRect_nculos->setCheckable(false);
    ui->actionCircunferencias->setCheckable(false);


    mestilo=2;
}

void Principal::on_actionRect_nculos_triggered()
{
    ui->actionLibre->setCheckable(false);
    ui->actionLineas->setCheckable(false);
    ui->actionCircunferencias->setCheckable(false);


    mestilo=3;
}

void Principal::on_actionCircunferencias_triggered()
{
    ui->actionLibre->setCheckable(false);
    ui->actionRect_nculos->setCheckable(false);
    ui->actionLineas->setCheckable(false);


    mestilo=4;
}

void Principal::on_actionacerca_de_triggered()
{
    QMessageBox::information(this,"acerca de","mini Paint\n Autor: David Vargas\n Creado el domi.,26 de jul del 2020 \n QT 4.12.2\n Mi github:https://github.com/david2060dd \n Copyright 2008-2020 Compufuture.inc All rights reserve");
}
