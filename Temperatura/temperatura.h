#ifndef TEMPERATURA_H
#define TEMPERATURA_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Temperatura; }
QT_END_NAMESPACE

class Temperatura : public QDialog
{
    Q_OBJECT

public:
    Temperatura(QWidget *parent = nullptr);
    ~Temperatura();
public slots:
    void cent2Fahr(int);
    void fhar2Cent(int);
    void cent2Kelvin(int);
    void kelvin2Cent(int);
    void fhar2Kelvin(int);
    void kelvin2fahr(int);

private:
    Ui::Temperatura *ui;
};
#endif // TEMPERATURA_H
