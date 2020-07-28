#include "principal.h"

#include <QApplication>

#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator traducion;
    QStringList idiomas;
    idiomas << "Ingles" << "Español";
    QString idiomaSeleccionado = QInputDialog::getItem(NULL,
                               "Idioma",
                               "Seleccione un idioma",
                               idiomas);

    if (idiomaSeleccionado == "Ingles"){
        traducion.load(":/Prueba-Final_en_US.qm");

    }

    if (idiomaSeleccionado != "Español"){
        a.installTranslator(&traducion);
    }

    Principal w;
    w.show();
    return a.exec();
}
