/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *clickMich;
    QLineEdit *clicks;
    QPushButton *extraClickKauf;
    QLabel *label_2;
    QLineEdit *extraClickPreis;
    QLineEdit *extraClickBesitz;
    QLineEdit *clicksProSek;
    QLineEdit *clicksProClick;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *autoClickKauf_2;
    QLineEdit *autoClickPreis_2;
    QLabel *label_6;
    QLineEdit *autoClickBesitz_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1090, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        clickMich = new QPushButton(centralwidget);
        clickMich->setObjectName("clickMich");
        clickMich->setGeometry(QRect(330, 60, 80, 24));
        clicks = new QLineEdit(centralwidget);
        clicks->setObjectName("clicks");
        clicks->setGeometry(QRect(320, 40, 113, 24));
        clicks->setReadOnly(true);
        extraClickKauf = new QPushButton(centralwidget);
        extraClickKauf->setObjectName("extraClickKauf");
        extraClickKauf->setGeometry(QRect(620, 160, 80, 24));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(530, 160, 91, 21));
        extraClickPreis = new QLineEdit(centralwidget);
        extraClickPreis->setObjectName("extraClickPreis");
        extraClickPreis->setGeometry(QRect(700, 160, 31, 24));
        extraClickBesitz = new QLineEdit(centralwidget);
        extraClickBesitz->setObjectName("extraClickBesitz");
        extraClickBesitz->setGeometry(QRect(730, 160, 31, 24));
        clicksProSek = new QLineEdit(centralwidget);
        clicksProSek->setObjectName("clicksProSek");
        clicksProSek->setGeometry(QRect(200, 40, 51, 24));
        clicksProClick = new QLineEdit(centralwidget);
        clicksProClick->setObjectName("clicksProClick");
        clicksProClick->setGeometry(QRect(200, 70, 51, 24));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(260, 40, 21, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(260, 70, 31, 21));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(700, 140, 31, 21));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(730, 140, 31, 20));
        autoClickKauf_2 = new QPushButton(centralwidget);
        autoClickKauf_2->setObjectName("autoClickKauf_2");
        autoClickKauf_2->setGeometry(QRect(620, 190, 80, 24));
        autoClickPreis_2 = new QLineEdit(centralwidget);
        autoClickPreis_2->setObjectName("autoClickPreis_2");
        autoClickPreis_2->setGeometry(QRect(700, 190, 31, 24));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(530, 190, 91, 21));
        autoClickBesitz_2 = new QLineEdit(centralwidget);
        autoClickBesitz_2->setObjectName("autoClickBesitz_2");
        autoClickBesitz_2->setGeometry(QRect(730, 190, 31, 24));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        clickMich->setText(QCoreApplication::translate("MainWindow", "Click mich", nullptr));
        extraClickKauf->setText(QCoreApplication::translate("MainWindow", "Kaufen", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "+1c pro Click", nullptr));
        extraClickPreis->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        extraClickBesitz->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        clicksProSek->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        clicksProClick->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "/s", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "/click", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Preis", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Besitz", nullptr));
        autoClickKauf_2->setText(QCoreApplication::translate("MainWindow", "Kaufen", nullptr));
        autoClickPreis_2->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "+1c pro Sekunde", nullptr));
        autoClickBesitz_2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
