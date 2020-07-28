#include "fact.h"
#include "ui_fact.h"


fact::fact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fact)
{
    ui->setupUi(this);
}

fact::~fact()
{
    delete ui;
}
void fact::setfact(QString factura)

{
    ui->outRecibo->appendPlainText(factura);


}



void fact::on_pushButton_clicked()
{
close();
}
