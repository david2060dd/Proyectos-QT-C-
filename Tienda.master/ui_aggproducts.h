/********************************************************************************
** Form generated from reading UI file 'aggproducts.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGGPRODUCTS_H
#define UI_AGGPRODUCTS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_aggproducts
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_3;
    QTextEdit *textEdit;
    QPushButton *pushButton_2;

    void setupUi(QWidget *aggproducts)
    {
        if (aggproducts->objectName().isEmpty())
            aggproducts->setObjectName(QString::fromUtf8("aggproducts"));
        aggproducts->resize(550, 399);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/recursos/discount.png"), QSize(), QIcon::Normal, QIcon::Off);
        aggproducts->setWindowIcon(icon);
        aggproducts->setStyleSheet(QString::fromUtf8("background-color: rgb(205, 92, 92);"));
        verticalLayout_3 = new QVBoxLayout(aggproducts);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox = new QGroupBox(aggproducts);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 128, 128);"));

        verticalLayout_2->addWidget(pushButton);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 128, 128);"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);


        verticalLayout_2->addWidget(groupBox_2);

        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 128, 128);"));

        verticalLayout_2->addWidget(textEdit);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 128, 128);"));

        verticalLayout_2->addWidget(pushButton_2);


        verticalLayout_3->addWidget(groupBox);


        retranslateUi(aggproducts);

        QMetaObject::connectSlotsByName(aggproducts);
    } // setupUi

    void retranslateUi(QWidget *aggproducts)
    {
        aggproducts->setWindowTitle(QApplication::translate("aggproducts", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("aggproducts", "GroupBox", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton->setToolTip(QApplication::translate("aggproducts", "pulsa para visualizar los productos de la tienda ", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton->setText(QApplication::translate("aggproducts", "Visualizar Productos a la lista", nullptr));
        groupBox_2->setTitle(QApplication::translate("aggproducts", "GroupBox", nullptr));
        label->setText(QApplication::translate("aggproducts", "Instrucciones para agregar o borrar productos de la tienda:", nullptr));
        label_4->setText(QApplication::translate("aggproducts", "***Se requiere el reinicio de la aplicacion para visualizar los productos nuevos***", nullptr));
        label_2->setText(QApplication::translate("aggproducts", "numero del producto ; nombre del producto; precio del producto.", nullptr));
        label_3->setText(QApplication::translate("aggproducts", "Nota: Para quitar un producto de la lista basta con solo borrarlo", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QApplication::translate("aggproducts", "pulsa para guardar cambios", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_2->setText(QApplication::translate("aggproducts", "Guardar cambios", nullptr));
    } // retranslateUi

};

namespace Ui {
    class aggproducts: public Ui_aggproducts {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGGPRODUCTS_H
