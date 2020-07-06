/**
 * poo
 * Autor: David Vargas <dvargasd@ups.edu.ec>
 * Fecha: 30-06-2020
 * termometro
 *
 */
#include "temperatura.h"
#include "ui_temperatura.h"
#include <QDebug>

Temperatura::Temperatura(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Temperatura)
{
    ui->setupUi(this);

    //Conexión de Signals y Slots
    connect(ui->dialCent,SIGNAL(valueChanged(int)),this,SLOT(cent2Fahr(int)));
    connect(ui->dialFahr,SIGNAL(valueChanged(int)),this,SLOT(fhar2Cent(int)));
    connect(ui->dialCent,SIGNAL(valueChanged(int)),this,SLOT(cent2Kelvin(int)));
    connect(ui->dialKel,SIGNAL(valueChanged(int)),this,SLOT(kelvin2Cent(int)));
    connect(ui->dialFahr,SIGNAL(valueChanged(int)),this,SLOT(fhar2Kelvin(int)));
    connect(ui->dialKel,SIGNAL(valueChanged(int)),this,SLOT(kelvin2fahr(int)));

    //Establecer el valor de fahrenheit
    ui->dialFahr->setValue(32);
    ui->dialKel->setValue(273);

}

Temperatura::~Temperatura()
{
    delete ui;
}

void Temperatura::cent2Fahr(int valor)
{
    if(ui->dialCent->hasFocus()){
        float f = valor *9.0/5 + 32;
        //ui->lcdFahr->display(f);
        ui->dialFahr->setValue(f);
    }
}

void Temperatura::fhar2Cent(int valor)
{
    if(ui->dialFahr->hasFocus()){
        float c = (valor - 32) * 5.0/9;
        ui->dialCent->setValue(c);
    }
}

void Temperatura::cent2Kelvin(int valor)
{
    if(ui->dialCent->hasFocus()){
        float k = valor + 273.15;
        ui->dialKel->setValue(k);

    }
}

void Temperatura::kelvin2Cent(int valor)
{
    if(ui->dialKel->hasFocus()){
        float ke = valor - 273.15;
        ui->dialCent->setValue(ke);
    }
}

void Temperatura::fhar2Kelvin(int valor)
{
    if(ui->dialFahr->hasFocus()){
        float kel = (valor-32)*5.0/9+273.15;
        ui->dialKel->setValue(kel);
    }
}

void Temperatura::kelvin2fahr(int valor)
{
    if(ui->dialKel->hasFocus()){
        float kelv = (valor-273.15)*9.0/5+32;
        ui->dialFahr->setValue(kelv);
    }
}

