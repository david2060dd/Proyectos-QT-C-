#ifndef IMPRESORA_H
#define IMPRESORA_H

#include <QObject>

class Impresora : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int codigo READ codigo )
    Q_PROPERTY(QString nombre READ nombre )
    Q_PROPERTY(float precio READ precio WRITE setPrecio )

public:
    explicit Impresora(QObject *parent = nullptr);
    Impresora(int codigo, QString nombre, float precio);
    QString nombre() const;
    float precio() const;
    int codigo() const;
    void setPrecio(float precio);

signals:
 private:
    QString m_nombre;
    float m_precio;
    int m_codigo;





};

#endif // IMPRESORA_H
