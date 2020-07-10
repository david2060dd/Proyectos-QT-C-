#include "Impresora.h"

Impresora::Impresora(QObject *parent) : QObject(parent)
{
   m_codigo= 0;
   m_nombre= "";
   m_precio= 0.0;
}

Impresora::Impresora(int codigo, QString nombre, float precio)
{
  m_codigo=codigo;
  m_nombre=nombre;
  m_precio=precio;
}

int Impresora::codigo() const
{
    return m_codigo;
}
QString Impresora::nombre() const
{
    return m_nombre;
}

float Impresora::precio() const
{
    return m_precio;
}

void Impresora::setPrecio(float precio)
{
    m_precio=precio;
}
