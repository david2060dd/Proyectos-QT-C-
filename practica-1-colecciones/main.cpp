/**
 * POO
 * Autor: David Vargas <dvargasd@ups.edu.ec>
 * Fecha: 24-06-2020
 * practica 7
 * MANIPULACION DE ARCHIVOS
 */
#include <QCoreApplication>
#include <QDir>
#include <QDebug>
#include <iostream>

void crearCarpeta();
void eliminarCarpeta();
void cambiarNombre();
void eliminarArchivos();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int opc = 0;
    do{
        qDebug() << "\n--- Menu de Manipulacion de Archivos---";
        qDebug() << "1.Crear carpeta";
        qDebug() << "2.Eliminar carpeta impar";
        qDebug() << "3.Cambiar de nombre";
        qDebug() << "4.Eliminar todos los archivos del directorio";
        qDebug() << "5.Salir";
        qDebug() << "\nIngrese una opcion";
        std::cin >> opc;
        system ("cls");

        switch (opc) {

        case 1:
        {
            qDebug() <<"Crear Carpeta";
            crearCarpeta();
        }
            break;
        case 2:
        {
          qDebug() <<"Eliminar Carpeta ";
          eliminarCarpeta();

        }
            break;
        case 3:
        {
            qDebug() <<"Cambiar nombre de la carpeta\n";
            cambiarNombre();
        }
            break;

        case 4:
        {
             qDebug() <<"Eliminar archivos txt";
             eliminarArchivos();

        }
            break;
        case 5:
        {
            qDebug() <<"Adios :`3";

        }
            break;

        default:
            qDebug() <<"Opcion incorrecta!";
            break;
        }

    }while(opc !=5);

    //return 0;
    return a.exec();
}

void crearCarpeta(){
    //creando directororios en mi equipo /C:
    QString carpeta = "C:/Actividad Qt";
    QDir directorio (carpeta);

    qDebug()<<directorio.absolutePath()<<directorio.exists();
    //Lista de contenido ordenado
    QFileInfoList contenido = directorio.entryInfoList(QDir::Dirs,QDir::Name);
    /*foreach (const QFileInfo &info, contenido){
        qDebug() << info.fileName();
    }*/
    //Tamaño de la carpeta
    int tam = contenido.size();
    //Obtener ultima carpeta
    QFileInfo ultima_carpeta = contenido.at(tam-1);
    // Obtener el nombre de la ultima carpeta
    QString nombre_uc = ultima_carpeta.fileName();
    QString numero_string = nombre_uc.remove(0,7);
    int numero = numero_string.toInt();
    numero++;
    QString nueva_carpeta = "Carpeta"+ QString::number(numero);
    qDebug()<<nueva_carpeta;
    if (directorio.mkdir(nueva_carpeta)){
        qDebug() << "Se ha creado una nueva carpeta" << nueva_carpeta;
    }else{
        qWarning() << "No se ha creado nada" << nueva_carpeta;
    }
}

void eliminarCarpeta(){
    /*for(int i=1; i<=10; i+=2){
        QString eliminar_carpeta = "Carpeta" +QString::number(i);

        eliminar_carpeta.insert(0, "C:/Actividad Qt/");
        qDebug() << eliminar_carpeta;
        QDir carpEliminar (eliminar_carpeta);
        if(carpEliminar.exists()){
            //qDebug() << eliminar_carpeta;

            if(carpEliminar.removeRecursively()){
                qDebug() <<"Se elimino la carpeta" << eliminar_carpeta;

            }else{
                qWarning() <<"No se elimino";
            }
        }
    }*/
    QString carpeta = "C:/Actividad Qt";
    QDir directorio (carpeta);
    //Lista de contenido ordenado
    QFileInfoList contenido = directorio.entryInfoList(QDir::Dirs,QDir::Name);
    foreach(QFileInfo const &d, contenido){
        QString nombre = d.fileName();
        if ((nombre == ".") || (nombre == ".."))
            continue;
        int numero = nombre.remove("Carpeta").toInt();
        if (numero%2 != 0){
            directorio.cd(d.fileName());
            QStringList archivos = directorio.entryList();

            for (int i=0;i<archivos.length(); ++i){
                if ((archivos[i] == ".") || (archivos[i] == ".."))
                    continue;
                if (!directorio.remove(archivos[i])){
                    qDebug() << "\tNo se puede eliminar el archivo:" << archivos[i];

                }
            }
            directorio.cdUp();
            if (directorio.rmdir(d.fileName())){
                qDebug() << "Eliminado el directorio:" << d.fileName();
            }else{
                qDebug() << "No se peude eliminar el directorio:" << d.fileName();
            }
        }
    }
}

void cambiarNombre(){
    QString carpeta = "C:/Actividad Qt";
    QDir directorio (carpeta);

    qDebug()<<directorio.absolutePath()<<directorio.exists();
    //directorio.rename("Carpeta2","Driectorio2");
    if(directorio.rename("Carpeta2","Directorio2")){
        qDebug()<<"Se ha cambiado el nombre con exito!";
    }else{
        qWarning()<<"No se logro cambiar/ya se cambio el nombre";
    }
}

void eliminarArchivos(){
    QString carpeta = "C:/Actividad Qt";
    QDir directorio (carpeta);
    //Lista de contenido ordenado
    QFileInfoList contenido = directorio.entryInfoList(QDir::Dirs,QDir::Name);
    // Recorrer el contenido del directorio
    foreach(QFileInfo const &d, contenido){
        QString nombre = d.fileName();
        // descartar las carpetas especiales "." y ".."
        if ((nombre == ".") || (nombre == ".."))
            continue;
        //cambiar de directorio
            directorio.cd(d.fileName());
            if (!directorio.remove("Archivo2.txt")){
                qDebug() << "\tse elimino el Archivo2.txt:";
                }
            if (!directorio.remove("Archivo4.txt")){
                qDebug() << "\tse elimino el Archivo4.txt:";
                }
            }
    //subir al directorio padre
            directorio.cdUp();



}
