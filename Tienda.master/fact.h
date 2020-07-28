#ifndef FACT_H
#define FACT_H

#include <QDialog>

namespace Ui {
class fact;
}

class fact : public QDialog
{
    Q_OBJECT

public:
    explicit fact(QWidget *parent = nullptr);
    ~fact();
    public slots:

    void setfact(QString factura);

private slots:
    void on_pushButton_clicked();

private:
    Ui::fact *ui;
};

#endif // FACT_H
