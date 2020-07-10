#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include "Impresora.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();
public slots:
    void precioImpre(int);
    void registrar();
    void clean();
   // void guardar();



private slots:
    void on_actionAcerca_de_triggered();

private:
    Ui::Principal *ui;
    QList<Impresora*> m_impresoras;
    void inicializarDatosmIp();
    void mostrarImpresoras();


};


#endif // PRINCIPAL_H
