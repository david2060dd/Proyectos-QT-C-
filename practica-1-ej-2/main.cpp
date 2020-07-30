/**
 * POO
 * Autor: David Vargas <dvargasd@ups.edu.ec>
 * Fecha: 24-06-2020
 * practica 7
 * MANIPULACION DE ARCHIVOS
 */

#include <QCoreApplication>
#include <iostream>
#include <QDebug>
#include <QDir>
#include <QDateTime>

int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
int opc = 0;
do{
qDebug() << "\n======================================================";
qDebug() << "\n==========ANALISIS DE UN DIRECTORIO-FICHERO===========";
qDebug() << "\n======================================================";
qDebug() << "\nQue desea hacer?";
qDebug() << "1.Introduzca un path";
qDebug() << "2.Salir";
qDebug() << "\nPorfavor digite un numero";
std::cin >> opc;
switch (opc) {
case 1:
{
qDebug()<<"Porfavor digite la direccion de su directorio-fichero\n";
char drcto[100];
QDir directorio;
QString Nombre;
QFileInfo cnds;
do{
std::cin.getline(drcto,100);
QString narch = drcto;
directorio = (narch);
QString name = directorio.dirName();
cnds = narch;
if(directorio.exists()){
if(cnds.isDir()){
QFileInfoList inforPath = directorio.entryInfoList();
foreach(const QFileInfo &info, inforPath){
QString nombres = info.fileName();
bool tipo = info.isDir();
QString modificacion = info.birthTime().toString();
bool sePuedeLeer = info.isReadable();
bool esEjecutable = info.isExecutable();
QString duenio = info.owner();
qDebug() <<"-------------------------------------------------------------------";
qDebug() <<"|                   DIRECTORIO                           |";
qDebug() <<"-------------------------------------------------------------------";
qDebug() <<"| Nombre del directorio             | " << nombres;
qDebug() <<"-------------------------------------------------------------------";
qDebug() <<"| es un directorio?:                | " << tipo;
qDebug() <<"-------------------------------------------------------------------";
qDebug() <<"| Fecha de creacion:                | " << modificacion;
qDebug() <<"|------------------------------------------------------------------";
qDebug() <<"| Se puede leer?:                   | " << sePuedeLeer;
qDebug() <<"-------------------------------------------------------------------";
qDebug() <<"| Es ejecutable?:                   | " << esEjecutable;
qDebug() <<"-------------------------------------------------------------------";
qDebug() <<"| tamaño total del directorio:      | " << info.size();
qDebug() <<"-------------------------------------------------------------------";
qDebug() <<"| nombre del propietario:           | " << duenio;
qDebug() <<"-------------------------------------------------------------------";
}
}
if(cnds.isFile()){
QFileInfo ArchivoInfo = directorio.absolutePath();
int tamanio = ArchivoInfo.size();
QString nombresA = ArchivoInfo.fileName();
QString tipoA = directorio.absolutePath();
QString modificacionA = ArchivoInfo.lastModified().toString();
bool sePuedeLeerA = ArchivoInfo.isReadable();
bool esEjecutableA = ArchivoInfo.isExecutable();
QString duenioA = ArchivoInfo.owner();
qDebug() << tamanio;
qDebug() <<"-------------------------------------------------------------------";
qDebug() <<"|                   ARCHIVO                           |";
qDebug() <<"-------------------------------------------------------------------";
qDebug() <<"| Nombre del directorio             | " << nombresA;
qDebug() <<"-------------------------------------------------------------------";
qDebug() <<"| Es un archivo:                    | " << tipoA;
qDebug() <<"-------------------------------------------------------------------";
qDebug() <<"| Fecha de creacion:                | " << modificacionA;
qDebug() <<"|------------------------------------------------------------------";
qDebug() <<"| Se puede leer?:                   | " << sePuedeLeerA;
qDebug() <<"-------------------------------------------------------------------";
qDebug() <<"| Es ejecutable?:                   | " << esEjecutableA;
qDebug() <<"-------------------------------------------------------------------";
qDebug() <<"| tamaño total del archivo:      | " << ArchivoInfo.size();
qDebug() <<"-------------------------------------------------------------------";
qDebug() <<"| nombre del propietario:           | " << duenioA;
qDebug() <<"-------------------------------------------------------------------";
}

break;
}
}while(!directorio.exists()||!(cnds.isFile()));
break;
}
break;
case 2:
{
qDebug()<<"GRACIAS POR USAR EL PROGRAMA";
}
break;
default:
qDebug() <<"Opcion incorrecta!";
break;
}
}while(opc !=2);
return a.exec();
}
