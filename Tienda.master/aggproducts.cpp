#include "aggproducts.h"
#include"principal.h"
#include "ui_aggproducts.h"
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <QDir>
#include <QIODevice>
#include  <QTableWidgetItem>



aggproducts::aggproducts(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aggproducts)
{
    ui->setupUi(this);
}

aggproducts::~aggproducts()
{
    delete ui;
}

void aggproducts::on_pushButton_clicked()
{
 QFile file("C:\\Users\\david\\Documents\\proyectos-qt\\Tienda\\productos.csv");
 if(!file.open(QIODevice::ReadWrite))
     QMessageBox::information(0,"INFO",file.errorString());
 QTextStream in(&file);
 ui->textEdit->setText(in.readAll());

}

void aggproducts::on_pushButton_2_clicked()
{
    QString fileName=("C:\\Users\\david\\Documents\\proyectos-qt\\Tienda\\productos.csv");

    QFile data(fileName);

    if (data.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream salida(&data);
        salida << ui->textEdit->toPlainText();

    }
}
