/********************************************************************************
** Form generated from reading UI file 'fact.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FACT_H
#define UI_FACT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_fact
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPlainTextEdit *outRecibo;
    QPushButton *pushButton;

    void setupUi(QDialog *fact)
    {
        if (fact->objectName().isEmpty())
            fact->setObjectName(QString::fromUtf8("fact"));
        fact->resize(548, 391);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/recursos/discount.png"), QSize(), QIcon::Normal, QIcon::Off);
        fact->setWindowIcon(icon);
        fact->setStyleSheet(QString::fromUtf8("background-color: rgb(205, 92, 92);"));
        horizontalLayout = new QHBoxLayout(fact);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(fact);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 128, 128);"));

        verticalLayout->addWidget(label);

        outRecibo = new QPlainTextEdit(groupBox);
        outRecibo->setObjectName(QString::fromUtf8("outRecibo"));
        QFont font;
        font.setPointSize(10);
        outRecibo->setFont(font);
        outRecibo->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 128, 128);"));

        verticalLayout->addWidget(outRecibo);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        horizontalLayout->addWidget(groupBox);


        retranslateUi(fact);

        QMetaObject::connectSlotsByName(fact);
    } // setupUi

    void retranslateUi(QDialog *fact)
    {
        fact->setWindowTitle(QApplication::translate("fact", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("fact", "GroupBox", nullptr));
        label->setText(QApplication::translate("fact", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt;\">Michita's Store</span></p></body></html>", nullptr));
        outRecibo->setPlainText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton->setToolTip(QApplication::translate("fact", "pulsa para cerrar", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton->setText(QApplication::translate("fact", "Aceptar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fact: public Ui_fact {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FACT_H
