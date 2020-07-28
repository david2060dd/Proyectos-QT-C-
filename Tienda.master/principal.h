#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>

#include "producto.h"
#include "fact.h"

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
    void mostrarPrecio(int);
    void agregarProducto();
    void validarCedula();
    void factura();
    void dat();
    void limpiar();
private slots:
    void on_actionAgregar_productos_triggered();

    void on_actionAcerca_de_triggered();

private:
    Ui::Principal *ui;
    QList<Producto*> m_productos;

    void inicializarDatos();
    void inicializarWidgets();
    float m_subtotal;

    void calcular(float subtotal);
    // este metodo es para agrupar los mismos productos que ya hemos ingresado
    bool buscar(Producto *producto, int cantidad);
    // CEDULA


};
#endif // PRINCIPAL_H
