#ifndef AGGPRODUCTS_H
#define AGGPRODUCTS_H

#include <QWidget>

namespace Ui {
class aggproducts;
}

class aggproducts : public QWidget
{
    Q_OBJECT

public:
    explicit aggproducts(QWidget *parent = nullptr);
    ~aggproducts();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::aggproducts *ui;
};

#endif // AGGPRODUCTS_H
