/********************************************************************************
** Form generated from reading UI file 'principal.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINCIPAL_H
#define UI_PRINCIPAL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Principal
{
public:
    QAction *actionAgregar_productos;
    QAction *actionAcerca_de;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *inCedula;
    QLineEdit *inNombre;
    QLineEdit *inTelefono;
    QLabel *label_4;
    QLineEdit *inEmail;
    QLabel *label_5;
    QPlainTextEdit *inDireccion;
    QLabel *label_2;
    QLabel *label_3;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout_2;
    QLabel *label_6;
    QComboBox *inProducto;
    QLabel *label_7;
    QSpinBox *inCantidad;
    QLabel *label_8;
    QLabel *outPrecio;
    QPushButton *cmdAgregar;
    QSpacerItem *verticalSpacer;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout;
    QTableWidget *outDetalle;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_2;
    QFormLayout *formLayout_3;
    QLabel *label_10;
    QLabel *outSubtotal;
    QLabel *label_11;
    QLabel *outIva;
    QLabel *label_12;
    QLabel *outTotal;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menuarchivos;
    QMenu *menuAyuda;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Principal)
    {
        if (Principal->objectName().isEmpty())
            Principal->setObjectName(QString::fromUtf8("Principal"));
        Principal->resize(720, 458);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/recursos/discount.png"), QSize(), QIcon::Normal, QIcon::Off);
        Principal->setWindowIcon(icon);
        Principal->setStyleSheet(QString::fromUtf8("background-color: rgb(205, 92, 92);"));
        actionAgregar_productos = new QAction(Principal);
        actionAgregar_productos->setObjectName(QString::fromUtf8("actionAgregar_productos"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/recursos/bread.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAgregar_productos->setIcon(icon1);
        actionAcerca_de = new QAction(Principal);
        actionAcerca_de->setObjectName(QString::fromUtf8("actionAcerca_de"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/recursos/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAcerca_de->setIcon(icon2);
        centralwidget = new QWidget(Principal);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widget_4 = new QWidget(centralwidget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setMaximumSize(QSize(350, 16777215));
        verticalLayout_3 = new QVBoxLayout(widget_4);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox = new QGroupBox(widget_4);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        inCedula = new QLineEdit(groupBox);
        inCedula->setObjectName(QString::fromUtf8("inCedula"));
        inCedula->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 128, 128);"));

        formLayout->setWidget(0, QFormLayout::FieldRole, inCedula);

        inNombre = new QLineEdit(groupBox);
        inNombre->setObjectName(QString::fromUtf8("inNombre"));
        inNombre->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 128, 128);"));

        formLayout->setWidget(1, QFormLayout::FieldRole, inNombre);

        inTelefono = new QLineEdit(groupBox);
        inTelefono->setObjectName(QString::fromUtf8("inTelefono"));
        inTelefono->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 128, 128);"));

        formLayout->setWidget(3, QFormLayout::FieldRole, inTelefono);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_4);

        inEmail = new QLineEdit(groupBox);
        inEmail->setObjectName(QString::fromUtf8("inEmail"));
        inEmail->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 128, 128);"));

        formLayout->setWidget(5, QFormLayout::FieldRole, inEmail);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_5);

        inDireccion = new QPlainTextEdit(groupBox);
        inDireccion->setObjectName(QString::fromUtf8("inDireccion"));
        inDireccion->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 128, 128);"));

        formLayout->setWidget(6, QFormLayout::FieldRole, inDireccion);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(widget_4);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        formLayout_2 = new QFormLayout(groupBox_2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_6);

        inProducto = new QComboBox(groupBox_2);
        inProducto->setObjectName(QString::fromUtf8("inProducto"));
        inProducto->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 128, 128);"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, inProducto);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_7);

        inCantidad = new QSpinBox(groupBox_2);
        inCantidad->setObjectName(QString::fromUtf8("inCantidad"));
        inCantidad->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 128, 128);"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, inCantidad);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_8);

        outPrecio = new QLabel(groupBox_2);
        outPrecio->setObjectName(QString::fromUtf8("outPrecio"));
        outPrecio->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 128, 128);"));
        outPrecio->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, outPrecio);

        cmdAgregar = new QPushButton(groupBox_2);
        cmdAgregar->setObjectName(QString::fromUtf8("cmdAgregar"));
        cmdAgregar->setMinimumSize(QSize(0, 45));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        cmdAgregar->setFont(font);
        cmdAgregar->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 128, 128);"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, cmdAgregar);


        verticalLayout_3->addWidget(groupBox_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_2->addWidget(widget_4);

        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout_2 = new QVBoxLayout(widget_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox_3 = new QGroupBox(widget_3);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout = new QVBoxLayout(groupBox_3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        outDetalle = new QTableWidget(groupBox_3);
        outDetalle->setObjectName(QString::fromUtf8("outDetalle"));
        outDetalle->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 128, 128);"));

        verticalLayout->addWidget(outDetalle);


        verticalLayout_2->addWidget(groupBox_3);

        widget = new QWidget(widget_3);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 128, 128);"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        formLayout_3 = new QFormLayout(widget_2);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        label_10 = new QLabel(widget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_10);

        outSubtotal = new QLabel(widget_2);
        outSubtotal->setObjectName(QString::fromUtf8("outSubtotal"));
        outSubtotal->setMinimumSize(QSize(100, 0));
        outSubtotal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, outSubtotal);

        label_11 = new QLabel(widget_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_11);

        outIva = new QLabel(widget_2);
        outIva->setObjectName(QString::fromUtf8("outIva"));
        outIva->setMinimumSize(QSize(100, 0));
        outIva->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, outIva);

        label_12 = new QLabel(widget_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Copperplate Gothic Bold"));
        font1.setPointSize(10);
        label_12->setFont(font1);
        label_12->setStyleSheet(QString::fromUtf8("background-color: rgb(205, 92, 92);"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_12);

        outTotal = new QLabel(widget_2);
        outTotal->setObjectName(QString::fromUtf8("outTotal"));
        outTotal->setMinimumSize(QSize(100, 0));
        outTotal->setFont(font1);
        outTotal->setStyleSheet(QString::fromUtf8("background-color: rgb(205, 92, 92);\n"
"color:rgb(0, 0, 0)"));
        outTotal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, outTotal);


        horizontalLayout->addWidget(widget_2);


        verticalLayout_2->addWidget(widget);

        pushButton = new QPushButton(widget_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMaximumSize(QSize(100, 16777215));
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 128, 128);"));

        verticalLayout_2->addWidget(pushButton);


        horizontalLayout_2->addWidget(widget_3);

        Principal->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Principal);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 720, 21));
        menuarchivos = new QMenu(menubar);
        menuarchivos->setObjectName(QString::fromUtf8("menuarchivos"));
        menuAyuda = new QMenu(menubar);
        menuAyuda->setObjectName(QString::fromUtf8("menuAyuda"));
        Principal->setMenuBar(menubar);
        statusbar = new QStatusBar(Principal);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Principal->setStatusBar(statusbar);

        menubar->addAction(menuarchivos->menuAction());
        menubar->addAction(menuAyuda->menuAction());
        menuarchivos->addAction(actionAgregar_productos);
        menuAyuda->addAction(actionAcerca_de);

        retranslateUi(Principal);

        QMetaObject::connectSlotsByName(Principal);
    } // setupUi

    void retranslateUi(QMainWindow *Principal)
    {
        Principal->setWindowTitle(QApplication::translate("Principal", "Principal", nullptr));
        actionAgregar_productos->setText(QApplication::translate("Principal", "Agregar productos", nullptr));
        actionAcerca_de->setText(QApplication::translate("Principal", "Acerca de..", nullptr));
        groupBox->setTitle(QApplication::translate("Principal", "Cliente", nullptr));
        label->setText(QApplication::translate("Principal", "Cedula:", nullptr));
#ifndef QT_NO_TOOLTIP
        inCedula->setToolTip(QApplication::translate("Principal", "ingresar la cedula del cliente", nullptr));
#endif // QT_NO_TOOLTIP
        inCedula->setPlaceholderText(QApplication::translate("Principal", "Cedula del cliente", nullptr));
        inNombre->setPlaceholderText(QApplication::translate("Principal", "Nombre del cliente", nullptr));
        inTelefono->setPlaceholderText(QApplication::translate("Principal", "Numero de telefono del cliente", nullptr));
        label_4->setText(QApplication::translate("Principal", "E-mail:", nullptr));
        inEmail->setPlaceholderText(QApplication::translate("Principal", "E-mail del cliente", nullptr));
        label_5->setText(QApplication::translate("Principal", "Direccion:", nullptr));
#ifndef QT_NO_TOOLTIP
        inDireccion->setToolTip(QApplication::translate("Principal", "Direccion del cliente", nullptr));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("Principal", "Nombre:", nullptr));
        label_3->setText(QApplication::translate("Principal", "Telefono:", nullptr));
        groupBox_2->setTitle(QApplication::translate("Principal", "Producto", nullptr));
        label_6->setText(QApplication::translate("Principal", "Nombre:", nullptr));
#ifndef QT_NO_TOOLTIP
        inProducto->setToolTip(QApplication::translate("Principal", "Elige el producto que el cliente desee comprar ", nullptr));
#endif // QT_NO_TOOLTIP
        label_7->setText(QApplication::translate("Principal", "Cantidad:", nullptr));
#ifndef QT_NO_TOOLTIP
        inCantidad->setToolTip(QApplication::translate("Principal", "elige la cantidad del producto", nullptr));
#endif // QT_NO_TOOLTIP
        label_8->setText(QApplication::translate("Principal", "Precio:", nullptr));
#ifndef QT_NO_TOOLTIP
        outPrecio->setToolTip(QApplication::translate("Principal", "Precio del producto", nullptr));
#endif // QT_NO_TOOLTIP
        outPrecio->setText(QApplication::translate("Principal", "0.0", nullptr));
#ifndef QT_NO_TOOLTIP
        cmdAgregar->setToolTip(QApplication::translate("Principal", "pulsa para agregar al carrito", nullptr));
#endif // QT_NO_TOOLTIP
        cmdAgregar->setText(QApplication::translate("Principal", "Agregar", nullptr));
        groupBox_3->setTitle(QApplication::translate("Principal", "Detalle de la Compra", nullptr));
        label_10->setText(QApplication::translate("Principal", "Sub Total:", nullptr));
        outSubtotal->setText(QApplication::translate("Principal", "0.0", nullptr));
        label_11->setText(QApplication::translate("Principal", "IVA:", nullptr));
        outIva->setText(QApplication::translate("Principal", "0.0", nullptr));
        label_12->setText(QApplication::translate("Principal", "Total:", nullptr));
        outTotal->setText(QApplication::translate("Principal", "0.0", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton->setToolTip(QApplication::translate("Principal", "Pulsa para finalizar", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton->setText(QApplication::translate("Principal", "Finalizar", nullptr));
        menuarchivos->setTitle(QApplication::translate("Principal", "archivos", nullptr));
        menuAyuda->setTitle(QApplication::translate("Principal", "Ayuda", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Principal: public Ui_Principal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINCIPAL_H
